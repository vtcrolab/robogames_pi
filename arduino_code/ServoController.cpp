#include "ServoController.h"
#include <Servo.h>
#include <Arduino.h>

Servo servo;

void setupServo() {
  servo.attach(SERVO_PIN);
  servo.write(SERVO_CENTER);
}

void setServoFromJoystick(float joystickX) {
  joystickX = constrain(joystickX, -1.0, 1.0);
  int angle = SERVO_CENTER + (joystickX * MAX_DEVIATION * -1);
  angle = constrain(angle, 0, 180);
  servo.write(angle);
}
