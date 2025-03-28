// /////////////////////////////
// //
// // gps n imu data
// //
// /////////////////////////////


// // includes n whatnot
// #include "TinyGPS.h"
// #include "SoftwareSerial.h"

// #include <Adafruit_Sensor.h>
// #include "Wire.h"
// #include <MPU6050_light.h>


// // constants 
// #define GPS_RX 3
// #define GPS_TX 4

// #define PI 3.1415926535897932384626433832795


// // gps arduino connections
// SoftwareSerial ss(GPS_RX, GPS_TX);
// TinyGPS gps;

// // imu arduino connections
// MPU6050 mpu(Wire);

// // variables
// long lat, lng;
// long  old_lat, old_lng;


// void setup() {

//   Serial.begin(9600);
//   ss.begin(9600);

//   Wire.begin();
//   mpu.begin();
//   mpu.calcOffsets();
// }


// void loop() {

//   // gps code
//   bool newData = false;

//   for (unsigned long start = millis(); millis() - start < 1000;) {
//     while (ss.available()) {
//       char c = ss.read();
//       if (gps.encode(c)) { // Did a new valid sentence come in?
//         newData = true;}
//     }
//   }

//   if(newData) {
//     Serial.println();
//   }

//   Serial.println("-------");
//   Serial.println();
//   delay(1000);


//   // imu code
//   mpu.update();

//   // speed in mps;
//   float velocity = gps.f_speed_mps();
//   float angley = mpu.getAngleY();
//   float anglex = mpu.getAngleX();

//   Serial.println(angley);
//   Serial.println(anglex);

//   float displace_y = (velocity * (sin(angley) * (PI/180))) * 10e4;
//   float displace_x = (velocity * (cos(anglex) * (PI/180))) * 10e4;

//   Serial.print("velocity: "); Serial.println(velocity);

//   Serial.print("calc x displace: "); Serial.println(displace_x);
//   Serial.print("calc y displace: "); Serial.println(displace_y);

//   Serial.println();
//   calculate_coords();
//   Serial.println();
// }


// void calculate_coords() {

//   gps.get_position(&lat, &lng);

//   long real_y_displace = lat - old_lat;
//   long real_x_displace = lng - old_lng;

//   Serial.print("real x displace: "); Serial.println(real_x_displace);
//   Serial.print("real y displace: "); Serial.println(real_y_displace);

//   old_lat = lat;
//   old_lng = lng;
// }