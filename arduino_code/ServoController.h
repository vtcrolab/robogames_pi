#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

const int SERVO_CENTER = 90;
const int MAX_DEVIATION = 15;

#define SERVO_PIN 8

void setupServo();
void setServoFromJoystick(float joystickX);

#endif
