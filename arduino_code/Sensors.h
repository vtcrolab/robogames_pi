#ifndef SENSORS_H
#define SENSORS_H

#include <MPU6050_light.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>

#define GPS_RX 11
#define GPS_TX 12
#define PI 3.1415926535897932384626433832795

extern SoftwareSerial ss;
extern TinyGPS gps;
extern MPU6050 mpu;

extern long lat, lng, old_lat, old_lng;

void setupSensors();
void updateSensors();
void calculate_coords();

#endif
