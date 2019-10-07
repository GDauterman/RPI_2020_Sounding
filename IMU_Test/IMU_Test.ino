#include <Wire.h>
#include <Math.h>
#include <Adafruit_LSM303.h>

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(0);

double X = 0, Y = 0, Z = 0;

int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(accel.begin())
    Serial.println("acceleration successfully initialized");
  Serial.print("yee haw");

}

void loop() {
  delay(10);

  sensors_event_t event;
  accel.getEvent(&event);

  X = event.acceleration.x;
  Y = event.acceleration.y;
  Z = event.acceleration.z;

  pitch = atan2(X, sqrt(Z*Z + Y*Y))*(180.0/M_PI);
  roll  = atan2(-Y, Z)*(180.0/M_PI);
  roll += 90;
  if(roll > 180){
    roll -= 270;
  }
  
  i++;
  if(i == 100) {
    i=0;
    Serial.print("\n\nX= ");
    Serial.print(X);
  
    Serial.print("\nY= ");
    Serial.print(Y);
  
     // Fix Z axsis, subtract the gravity stuff (-9.8?)
    Serial.print("\nZ= ");
    Serial.print(Z);
  
    Serial.print("\nPitch= ");
    Serial.print(pitch);
  
    Serial.print("\nRoll= ");
    Serial.print(roll);
  }
}
