// #include <Servo.h>

// #define SERVO_PIN 8

// Servo servo;

// const int SERVO_CENTER = 90;
// const int MAX_DEVIATION = 30;  // ±60 degrees
// int servo_angle = SERVO_CENTER;

// void setup() {
//     Serial.begin(115200);
//     servo.attach(SERVO_PIN);

//     Serial.println("Arduino Ready!");
//     delay(1000);
// }

// float joystickX = 0;
// int counter = 0;

// void loop() {
//     if(counter % 3 == 0){
//       joystickX = -1;
//     }
//     else if(counter % 3 == 1){
//       joystickX = 0;
//     }
//     else{
//       joystickX = 1;
//     }
//     //TEST INITIAL POSITION
//     //joystickX = 0;

//     // Clamp joystick value between -1.0 and 1.0 just to be safe
//     joystickX = constrain(joystickX, -1.0, 1.0);

//     // LEFT (+1.0) => 150°, CENTER (0.0) => 90°, RIGHT (-1.0) => 30°
//     servo_angle = SERVO_CENTER + (joystickX * MAX_DEVIATION * -1);  // Flip sign

//     // Clamp angle between 0 and 180 (Servo range)
//     //servo_angle = constrain(servo_angle, 0, 180);

//     servo.write(servo_angle);         // Update Servo Angle
    
//     counter ++;
//     delay(2000);
// }
