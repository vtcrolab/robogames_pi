#include "Communication.h"
#include "ServoController.h"
#include "MotorController.h"
#include <Arduino.h>

String receivedData = "";

void setupCommunication() {
  Serial.println("Arduino Ready!");
  delay(2000);
}

void handleSerialInput() {
  if (Serial.available()) {
    receivedData = Serial.readStringUntil('\n');

    if (receivedData.startsWith("S") && receivedData.indexOf("M") != -1) {
      int sIndex = receivedData.indexOf("S") + 1;
      int mIndex = receivedData.indexOf("M") + 1;

      float joystickX = receivedData.substring(sIndex, mIndex - 1).toInt();
      //float joystickX = receivedData.substring(sIndex, mIndex - 1).toFloat();

      joystickX = constrain(joystickX, -1.0, 1.0);
      int motorSpeed = receivedData.substring(mIndex).toInt();

      setServoFromJoystick(joystickX);
      setMotorSpeed(motorSpeed);

      Serial.print("JoystickX: "); Serial.print(joystickX);
      Serial.print(" | Servo Angle: "); Serial.print(SERVO_CENTER + joystickX * MAX_DEVIATION * -1);
      Serial.print(" | Motor Speed: "); Serial.println(motorSpeed);
    }
    else if (receivedData.startsWith("M")) {
      motor1_speed = receivedData.substring(1).toInt();
      motor2_speed = receivedData.substring(1).toInt();

      Serial.print("[Motor] Speed Updated: ");
      Serial.println(motor1_speed);
      Serial.println(motor2_speed);

      analogWrite(ENABLEA_PIN, motor1_speed);
      analogWrite(ENABLEB_PIN, motor2_speed);
    }
    else if (receivedData.startsWith("H")) {
      if (receivedData == "HF") {
        Serial.println("[Motion] Moving FORWARD");
        digitalWrite(MOTOR1_PIN1, LOW);
        digitalWrite(MOTOR1_PIN2, HIGH);
        digitalWrite(MOTOR2_PIN1, LOW);
        digitalWrite(MOTOR2_PIN2, HIGH);
      }
      else if (receivedData == "HB") {
        Serial.println("[Motion] Moving BACKWARD");
        digitalWrite(MOTOR1_PIN1, HIGH);
        digitalWrite(MOTOR1_PIN2, LOW);
        digitalWrite(MOTOR2_PIN1, HIGH);
        digitalWrite(MOTOR2_PIN2, LOW);
      }
      else if (receivedData == "HH") {
        Serial.println("[Motion] HALT");
        digitalWrite(MOTOR1_PIN1, LOW);
        digitalWrite(MOTOR1_PIN2, LOW);
        digitalWrite(MOTOR2_PIN1, LOW);
        digitalWrite(MOTOR2_PIN2, LOW);
        analogWrite(ENABLEA_PIN, 0);
        analogWrite(ENABLEB_PIN, 0);
      }
    }
  }
}
