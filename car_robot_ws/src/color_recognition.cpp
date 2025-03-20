#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <image_geometry/pinhole_camera_model.hpp>

class ColorRecognitionNode : public rclcpp::Node {
public:
    ColorRecognitionNode() : Node("color_recognition_node"), camera_info_received_(false) {
        // Subscribe to depth image
        depth_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera/depth/image_rect_raw", 10,
            std::bind(&ColorRecognitionNode::depth_callback, this, std::placeholders::_1));

        // Subscribe to color image
        color_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera/color/image_raw", 10,
            std::bind(&ColorRecognitionNode::color_callback, this, std::placeholders::_1));

        // Subscribe to camera info
        camera_info_sub_ = this->create_subscription<sensor_msgs::msg::CameraInfo>(
            "/camera/color/camera_info", 10,
            std::bind(&ColorRecognitionNode::camera_info_callback, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Color Recognition Node Initialized.");
    }

private:
    void camera_info_callback(const sensor_msgs::msg::CameraInfo::SharedPtr msg) {
        camera_model_.fromCameraInfo(*msg);
        camera_info_received_ = true;
        RCLCPP_INFO(this->get_logger(), "Camera Info Received.");
    }

    void depth_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
        if (!camera_info_received_) {
            RCLCPP_WARN(this->get_logger(), "Waiting for camera info...");
            return;
        }

        // Process the depth image
        cv_bridge::CvImagePtr depth_ptr;
        try {
            depth_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_32FC1);
        } catch (cv_bridge::Exception &e) {
            RCLCPP_ERROR(this->get_logger(), "CV Bridge error: %s", e.what());
            return;
        }

        // Get depth at the center pixel
        cv::Mat depth_image = depth_ptr->image;
        int center_x = depth_image.cols / 2;
        int center_y = depth_image.rows / 2;
        float depth_value = depth_image.at<float>(center_y, center_x);

        RCLCPP_INFO(this->get_logger(), "Depth at center: %.3f meters", depth_value);
    }

    void color_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
        if (!camera_info_received_) {
            RCLCPP_WARN(this->get_logger(), "Waiting for camera info...");
            return;
        }

        // Process the color image
        cv_bridge::CvImagePtr color_ptr;
        try {
            color_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        } catch (cv_bridge::Exception &e) {
            RCLCPP_ERROR(this->get_logger(), "CV Bridge error: %s", e.what());
            return;
        }

        cv::Mat color_image = color_ptr->image;
        cv::Mat hsv_image;
        cv::cvtColor(color_image, hsv_image, cv::COLOR_BGR2HSV);

        // Define the color range for detecting red objects (example)
        cv::Scalar lower_red(0, 120, 70);
        cv::Scalar upper_red(10, 255, 255);
        cv::Mat red_mask;
        cv::inRange(hsv_image, lower_red, upper_red, red_mask);

        // Find contours of the detected objects
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(red_mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // Draw contours and print the depth of the detected objects
        for (const auto& contour : contours) {
            cv::Rect bounding_box = cv::boundingRect(contour);
            cv::rectangle(color_image, bounding_box, cv::Scalar(0, 255, 0), 2); // Draw bounding box

            int center_x = bounding_box.x + bounding_box.width / 2;
            int center_y = bounding_box.y + bounding_box.height / 2;

            // Get the depth at the center of the detected object
            float depth_value = depth_image.at<float>(center_y, center_x);
            RCLCPP_INFO(this->get_logger(), "Detected red object at depth: %.3f meters", depth_value);
        }

        // Show the processed image with contours
        cv::imshow("Detected Red Objects", color_image);
        cv::waitKey(1); // To update the OpenCV window
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr depth_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr color_sub_;
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;

    image_geometry::PinholeCameraModel camera_model_;
    bool camera_info_received_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ColorRecognitionNode>());
    rclcpp::shutdown();
    return 0;
}
