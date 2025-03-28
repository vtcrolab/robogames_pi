#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 4
#define ENABLEA_PIN 3
#define MOTOR2_PIN1 5
#define MOTOR2_PIN2 7
#define ENABLEB_PIN 6

extern int motor1_speed;
extern int motor2_speed;

void setupMotors();
void setMotorSpeed(int speed);

#endif
