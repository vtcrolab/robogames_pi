// #include <Servo.h>

// #define MOTOR1_PIN1 2
// #define MOTOR1_PIN2 4
// #define ENABLEA_PIN 3
// #define MOTOR2_PIN1 5
// #define MOTOR2_PIN2 7
// #define ENABLEB_PIN 6
// #define SERVO_PIN 8

// const int SERVO_CENTER = 90;
// // const int MAX_DEVIATION = 30;  // ±30 degrees
// const int MAX_DEVIATION = 15;  // FOR TESTING
// int servo_angle = SERVO_CENTER;

// Servo servo;

// // int motor1_speed = 0;
// // int motor2_speed = 0;

// String receivedData = "";


// void setup() {
//   Serial.begin(57600);

//   servo.attach(SERVO_PIN);

//   pinMode(MOTOR1_PIN1, OUTPUT);
//   pinMode(MOTOR1_PIN2, OUTPUT);
//   pinMode(MOTOR2_PIN1, OUTPUT);
//   pinMode(MOTOR2_PIN2, OUTPUT);
//   pinMode(ENABLEA_PIN, OUTPUT);
//   pinMode(ENABLEB_PIN, OUTPUT);

//   Serial.println("Arduino Ready!");

//   delay(2000); //START BUFFER TO MANUALLY SETUP COMPONENTS
//   analogWrite(ENABLEA_PIN, 0); //ENA   pin
//   analogWrite(ENABLEB_PIN, 0); //ENA   pin
//   servo.write(90-15);
//   delay(2000);
//   servo.write(90);
//   delay(2000);
//   servo.write(90+15);
//   delay(2000);

// }

// // void adjustAngle(int targetAngle) {
// //   int angleDifference = targetAngle - currentAngle;
// //   int newAngle = currentAngle + angleDifference;
// //   motor1.write(newAngle);
// //   currentAngle = newAngle;
// // }

// // void moveMotor(int speed) {
// //   if (speed > 0) {
// //     analogWrite(ENABLEA_PIN, abs(speed)); 
// //     analogWrite(ENABLEB_PIN, abs(speed)); 
// //     digitalWrite(MOTOR1_PIN1, HIGH);
// //     digitalWrite(MOTOR1_PIN2, LOW);
// //     digitalWrite(MOTOR2_PIN1, HIGH);
// //     digitalWrite(MOTOR2_PIN2, LOW);
// //   } else if (speed < 0) {
// //     analogWrite(ENABLEA_PIN, abs(speed)); 
// //     analogWrite(ENABLEB_PIN, abs(speed)); 
// //     digitalWrite(MOTOR1_PIN1, LOW);
// //     digitalWrite(MOTOR1_PIN2, HIGH);
// //     digitalWrite(MOTOR2_PIN1, LOW);
// //     digitalWrite(MOTOR2_PIN2, HIGH);
// //   } else {
// //     analogWrite(ENABLEA_PIN, 0);
// //     analogWrite(ENABLEB_PIN, 0); 
// //     digitalWrite(MOTOR1_PIN1, LOW);
// //     digitalWrite(MOTOR1_PIN2, LOW);
// //     digitalWrite(MOTOR2_PIN1, LOW);vtcro2025

// //     digitalWrite(MOTOR2_PIN2, LOW);
// //   }
// // }

// // bool done_once = false;
// int direction_counter=0;
// int forward_or_backward = 0;
// int joystickX = 0;

// void loop() {
//   // //Controlling motor speed (0   = off and 255 = max speed):     
//   // if(!done_once){
//   //   analogWrite(ENABLEA_PIN, 255); //ENA   pin
//   //   analogWrite(ENABLEB_PIN, 255); //ENA   pin

//   //   digitalWrite(MOTOR1_PIN1, LOW);
//   //   digitalWrite(MOTOR1_PIN2, HIGH);
//   //   digitalWrite(MOTOR2_PIN1, LOW);
//   //   digitalWrite(MOTOR2_PIN2, HIGH);
//   //   done_once = true;
//   //   delay(3000);
//   // }
//   // else{
//   //   analogWrite(ENABLEA_PIN, 0); //ENA   pin
//   //   digitalWrite(MOTOR1_PIN1, LOW);
//   //   digitalWrite(MOTOR1_PIN2, LOW);
//   //   digitalWrite(MOTOR2_PIN1, LOW);
//   //   digitalWrite(MOTOR2_PIN2, LOW);
//   // }  

//  if(Serial.available()){
//   Serial.println("HELLO PI");
//   analogWrite(ENABLEA_PIN, 255); //ENA   pin
//   analogWrite(ENABLEB_PIN, 255); //ENA   pin

//   receivedData = Serial.readStringUntil('\n');  // Read full command

//   if (receivedData.startsWith("S") && receivedData.indexOf("M") != -1) {
//         // Handle "SXXXMYYY" Format (Servo + Motor Speed)
//         int sIndex = receivedData.indexOf("S") + 1;
//         int mIndex = receivedData.indexOf("M") + 1;

//         float joystickX = receivedData.substring(sIndex, mIndex - 1).toInt();
//         // Clamp joystick value between -1.0 and 1.0 just to be safe
//         joystickX = constrain(joystickX, -1.0, 1.0);

//         // LEFT (+1.0) => 150°, CENTER (0.0) => 90°, RIGHT (-1.0) => 30°
//         servo_angle = SERVO_CENTER + (joystickX * MAX_DEVIATION * -1);  // Flip sign

//         // Clamp angle between 0 and 180 (Servo range)
//         // servo_angle = constrain(servo_angle, 0, 180);

//         // motor1_speed = receivedData.substring(mIndex).toInt();
//         // motor2_speed = receivedData.substring(mIndex).toInt();

//         Serial.print("[Joystick] X: ");
//         Serial.print(joystickX);
//         Serial.print("[Servo] Angle: ");
//         Serial.print(servo_angle);
//         // Serial.print(" | [Motor] Speed: ");
//         // Serial.println(motor1_speed);
//         // Serial.println(motor2_speed);

//         servo.write(servo_angle);         // Update Servo Angle
//         // analogWrite(ENABLEA_PIN, motor1_speed); // Set Motor Speed
//         // analogWrite(ENABLEB_PIN, motor2_speed); // Set Motor Speed

//     }

//   // switch(direction_counter % 6){
//   //   //STRAIGHT FORWARD
//   //   case 0:
//   //     joystickX = 0;
//   //     forward_or_backward = 0;
//   //     break;
//   //   //RIGHT FORWARD
//   //   case 1:
//   //     joystickX = -1;
//   //     forward_or_backward = 0;
//   //     break;
//   //   //LEFT FORWARD
//   //   case 2:
//   //     joystickX = 1;
//   //     forward_or_backward = 0;
//   //     break;
//   //   //STRAIGHT BACKWARD
//   //   case 3:
//   //     joystickX = 0;
//   //     forward_or_backward = 1;
//   //     break;
//   //   //RIGHT BACKWARD
//   //   case 4:
//   //     joystickX = -1;
//   //     forward_or_backward = 1;
//   //     break;
//   //   //LEFT BACKWARD
//   //   case 5:
//   //     joystickX = 1;
//   //     forward_or_backward = 1;
//   //     break;
//   // }

//   // Clamp joystick value between -1.0 and 1.0 just to be safe
//   // joystickX = constrain(joystickX, -1.0, 1.0);

//   // // LEFT (+1.0) => 150°, CENTER (0.0) => 90°, RIGHT (-1.0) => 30°
//   // servo_angle = SERVO_CENTER + (joystickX * MAX_DEVIATION * -1);  // Flip sign

//   // servo.write(servo_angle);
  
//   // if(forward_or_backward == 0){
//   //   digitalWrite(MOTOR1_PIN1, LOW);
//   //   digitalWrite(MOTOR1_PIN2, HIGH);
//   //   digitalWrite(MOTOR2_PIN1, LOW);
//   //   digitalWrite(MOTOR2_PIN2, HIGH);
//   // }
//   // else{
//   //   digitalWrite(MOTOR1_PIN1, HIGH);
//   //   digitalWrite(MOTOR1_PIN2, LOW);
//   //   digitalWrite(MOTOR2_PIN1, HIGH);
//   //   digitalWrite(MOTOR2_PIN2, LOW);
//   // }

//   // direction_counter ++;
//   delay(10);
//   }
// }
