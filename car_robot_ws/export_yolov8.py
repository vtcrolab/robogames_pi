from ultralytics import YOLO

# Load the pretrained YOLOv8 model
model = YOLO("yolov8n.pt")  # Change the path if necessary

# Export the model to TorchScript format
model.export(format="torchscript")

# Save the TorchScript model to disk
model_path = "yolov8n.torchscript"
model.save(model_path)

print(f"Model saved as {model_path}")

