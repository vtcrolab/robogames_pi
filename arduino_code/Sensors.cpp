#include "Sensors.h"
#include <Wire.h>
#include <Arduino.h>

SoftwareSerial ss(GPS_RX, GPS_TX);
TinyGPS gps;
MPU6050 mpu(Wire);

long lat, lng, old_lat, old_lng;

void setupSensors() {
  // Serial.begin(9600);
  ss.begin(9600);
  Wire.begin();
  mpu.begin();
  mpu.calcOffsets();
}

void updateSensors() {
  bool newData = false;

  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (ss.available()) {
      char c = ss.read();
      if (gps.encode(c)) {
        newData = true;
      }
    }
  }

  if (newData) {
    Serial.println("New GPS data received");
  }

  mpu.update();

  float velocity = gps.f_speed_mps();
  float angley = mpu.getAngleY();
  float anglex = mpu.getAngleX();

  float displace_y = velocity * sin(angley * PI / 180) * 1e4;
  float displace_x = velocity * cos(anglex * PI / 180) * 1e4;

  Serial.print("velocity: "); Serial.println(velocity);
  Serial.print("calc x displace: "); Serial.println(displace_x);
  Serial.print("calc y displace: "); Serial.println(displace_y);

  calculate_coords();
}

void calculate_coords() {
  gps.get_position(&lat, &lng);
  long real_y_displace = lat - old_lat;
  long real_x_displace = lng - old_lng;

  Serial.print("real x displace: "); Serial.println(real_x_displace);
  Serial.print("real y displace: "); Serial.println(real_y_displace);

  old_lat = lat;
  old_lng = lng;
}
