#include <Arduino.h>
// made by orgllk
// Version 4.0 - Auto Pump

// Control Pins
#define mainState 8
#define pumpState 4
#define relayState 5
#define MAINpump 3

// Ultrasonic Sensor 1 (Lower)
#define trigPin1 7
#define echoPin1 6

// Ultrasonic Sensor 2 (Upper)
#define trigPin2 9
#define echoPin2 10

// Distance threshold (in cm)
#define WATER_LEVEL_THRESHOLD 83

long duration1, duration2;
int distance1, distance2;

void setup() {
  Serial.begin(9600);

  pinMode(mainState, OUTPUT);
  pinMode(pumpState, OUTPUT);
  pinMode(relayState, OUTPUT);
  pinMode(MAINpump, OUTPUT);

  // Sensor 1 (Lower)
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // Sensor 2 (Upper)
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

int readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  return (duration * 0.034 / 2);
  a
}

void loop() {
  digitalWrite(mainState, HIGH);  // system ON indicator

  distance1 = readDistance(trigPin1, echoPin1); // lower sensor
  distance2 = readDistance(trigPin2, echoPin2); // upper sensor

  // Print distances to Serial
  Serial.print("Lower Sensor Distance: ");
  Serial.print(distance1);
  Serial.print(" cm, Upper Sensor Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");

  bool lower_detected = distance1 <= WATER_LEVEL_THRESHOLD;
  bool upper_detected = distance2 <= WATER_LEVEL_THRESHOLD;

  // Logic: control pump based on both sensors
  if (!lower_detected && !upper_detected) {
    // Tank is empty → pump ON
    digitalWrite(MAINpump, HIGH);
    digitalWrite(pumpState, HIGH);
    Serial.println("Pump ON (Tank Empty)");
  }
  else if (lower_detected && !upper_detected) {
    // Water is rising, still below upper → keep pump ON
    digitalWrite(MAINpump, HIGH);
    digitalWrite(pumpState, HIGH);
    Serial.println("Pump ON (Filling)");
  }
  else if (lower_detected && upper_detected) {
    // Water at top → pump OFF
    digitalWrite(MAINpump, LOW);
    digitalWrite(pumpState, LOW);
    Serial.println("Pump OFF (Tank Full)");
  }
  else {
    // Fallback state
    digitalWrite(MAINpump, LOW);
    digitalWrite(pumpState, LOW);
    Serial.println("Pump OFF (Unknown State)");
  }

  delay(1000); // Delay for readability
}
