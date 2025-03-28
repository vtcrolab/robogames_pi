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

// int motor1_speed = 0;
// int motor2_speed = 0;

// String receivedData = "";

// void setup() {
//     Serial.begin(115200);
//     servo.attach(SERVO_PIN);

//     pinMode(MOTOR1_PIN1, OUTPUT);
//     pinMode(MOTOR1_PIN2, OUTPUT);
//     pinMode(MOTOR2_PIN1, OUTPUT);
//     pinMode(MOTOR2_PIN2, OUTPUT);
//     pinMode(ENABLEA_PIN, OUTPUT);
//     pinMode(ENABLEB_PIN, OUTPUT);

//     Serial.println("Arduino Ready!");
// }

// void loop() {
//   if (Serial.available()) {
//     Serial.println("ACK"); 
//     Serial.println(receivedData);
//     receivedData = Serial.readStringUntil('\n');  // Read full command

//     if (receivedData.startsWith("S") && receivedData.indexOf("M") != -1) {
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

//         motor1_speed = receivedData.substring(mIndex).toInt();
//         motor2_speed = receivedData.substring(mIndex).toInt();

//         Serial.print("[Joystick] X: ");
//         Serial.print(joystickX);
//         Serial.print("[Servo] Angle: ");
//         Serial.print(servo_angle);
//         Serial.print(" | [Motor] Speed: ");
//         Serial.println(motor1_speed);
//         Serial.println(motor2_speed);

//         servo.write(servo_angle);         // Update Servo Angle
//         analogWrite(ENABLEA_PIN, motor1_speed); // Set Motor Speed
//         analogWrite(ENABLEB_PIN, motor2_speed); // Set Motor Speed

//     }
//     else if (receivedData.startsWith("M")) {
//         // Handle "MYYY" Format (Motor Speed Only)
//         motor1_speed = receivedData.substring(1).toInt();
//         motor2_speed = receivedData.substring(1).toInt();

//         Serial.print("[Motor] Speed Updated: ");
//         Serial.println(motor1_speed);
//         Serial.println(motor2_speed);

//         analogWrite(ENABLEA_PIN, motor1_speed); // Set Motor Speed
//         analogWrite(ENABLEB_PIN, motor2_speed); // Set Motor Speed
//     }
//     else if (receivedData.startsWith("H")) {
//         // Handle "H" Commands (Movement)
//         if (receivedData == "HF") {
//             Serial.println("[Motion] Moving FORWARD");
//             digitalWrite(MOTOR1_PIN1, LOW);
//             digitalWrite(MOTOR1_PIN2, HIGH);
//             digitalWrite(MOTOR2_PIN1, LOW);
//             digitalWrite(MOTOR2_PIN2, HIGH);
//         }
//         else if (receivedData == "HB") {
//             Serial.println("[Motion] Moving BACKWARD");
//             digitalWrite(MOTOR1_PIN1, HIGH);
//             digitalWrite(MOTOR1_PIN2, LOW);
//             digitalWrite(MOTOR2_PIN1, HIGH);
//             digitalWrite(MOTOR2_PIN2, LOW);
//         }
//         else if (receivedData == "HH") {
//             Serial.println("[Motion] HALT");
//             digitalWrite(MOTOR1_PIN1, LOW);
//             digitalWrite(MOTOR1_PIN2, LOW);
//             digitalWrite(MOTOR2_PIN1, LOW);
//             digitalWrite(MOTOR2_PIN2, LOW);
//             analogWrite(ENABLEA_PIN, 0);
//             analogWrite(ENABLEB_PIN, 0);
//             motor1_speed = 0;
//             motor2_speed = 0;
//         }
//     }
//     else {
//         Serial.println("[ERROR] Unknown command received!");
//     }
//   }
// }
