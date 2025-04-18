#include "MotorController.h"
#include "ServoController.h"
#include "Communication.h"
#include "Sensors.h"

void setup() {
  Serial.begin(115200);
  setupMotors();
  setupServo();
  setupCommunication();
  setupSensors();
}

void loop() {
  Serial.println("Hello");
  handleSerialInput();     // from Pi
  updateSensors();         // GPS & IMU
  delay(10);
}
