#include "MotorController.h"
#include <Arduino.h>

int motor1_speed = 0;
int motor2_speed = 0;

void setupMotors() {
  // motor1_speed = 0;
  // motor2_speed = 0;
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(ENABLEA_PIN, OUTPUT);
  pinMode(ENABLEB_PIN, OUTPUT);
  analogWrite(ENABLEA_PIN, motor1_speed);
  analogWrite(ENABLEB_PIN, motor2_speed);
}

void setMotorSpeed(int speed) {

 // ========= Updates both motors ============== 

  //motor1_speed = speed;
  //motor2_speed = speed; 

  // ========================

  analogWrite(ENABLEA_PIN, abs(motor1_speed));
  analogWrite(ENABLEB_PIN, abs(motor2_speed));

  if (speed > 0) {
    digitalWrite(MOTOR1_PIN1, HIGH);
    digitalWrite(MOTOR1_PIN2, LOW);
    digitalWrite(MOTOR2_PIN1, HIGH);
    digitalWrite(MOTOR2_PIN2, LOW);
  } else if (speed < 0) {
    digitalWrite(MOTOR1_PIN1, LOW);
    digitalWrite(MOTOR1_PIN2, HIGH);
    digitalWrite(MOTOR2_PIN1, LOW);
    digitalWrite(MOTOR2_PIN2, HIGH);
  } else {
    digitalWrite(MOTOR1_PIN1, LOW);
    digitalWrite(MOTOR1_PIN2, LOW);
    digitalWrite(MOTOR2_PIN1, LOW);
    digitalWrite(MOTOR2_PIN2, LOW);
  }
}
