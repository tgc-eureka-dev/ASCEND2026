#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

// DHT22
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// MPU6050
Adafruit_MPU6050 mpu;

// HC-SR04
#define TRIG 5
#define ECHO 18

// LED
#define LED_TILT 15   // xanh duong
#define LED_DIST 2    // do
#define LED_TEMP 19   // xanh la

// Do khoang cach
float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000); // timeout 30ms
  if (duration == 0) return -1; // loi

  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);

  // I2C MPU6050
  Wire.begin(21, 22);

  dht.begin();

  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LED_TILT, OUTPUT);
  pinMode(LED_DIST, OUTPUT);
  pinMode(LED_TEMP, OUTPUT);

  Serial.println("System Ready!");
}

void loop() {
  sensors_event_t a, g, temp_mpu;
  mpu.getEvent(&a, &g, &temp_mpu);
  float accelX = a.acceleration.x;

  float distance = getDistance();
  float temp = dht.readTemperature();

  if (isnan(temp)) temp = -100;

  Serial.println("===== DATA =====");
  Serial.print("Accel X: "); Serial.println(accelX);
  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");
  Serial.print("Temp: "); Serial.print(temp); Serial.println(" C");

  // LED MPU6050 (nghieng)
  digitalWrite(LED_TILT, abs(accelX) > 5);

  // LED khoang cach
  digitalWrite(LED_DIST, (distance > 0 && distance < 20));

  // LED nhiet do
  digitalWrite(LED_TEMP, temp > 30);

  delay(500);
}