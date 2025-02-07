#include <Arduino.h>
// made by orgllk
// 3.0
// auto pump

#define echopin 5    // yellow sensor
#define trigpin 4    // violet sensor
#define motor 11     // relay
//
//
#define ultledc 12   // ultrasonic button check
#define motorledc 13 // motor button check
///
///
#define globelled 6  // ON
#define ultled 7     // ultrasonic LED
#define motorled 10  // motor LED
#define calls 8      // call service
///
///
char val;
long duration;
int distance;

// Function prototype
void hi();

void setup() {
  pinMode(trigpin, OUTPUT); 
  pinMode(echopin, INPUT); 
  pinMode(motor, OUTPUT);
  Serial.begin(9600); 
  //
  //
  pinMode(globelled, OUTPUT);
  pinMode(ultled, OUTPUT);
  pinMode(motorled, OUTPUT);
  pinMode(calls, OUTPUT);
  pinMode(ultledc, INPUT);   // Set pin modes for buttons
  pinMode(motorledc, INPUT);
}

void loop() {
  digitalWrite(globelled, HIGH); // Global light on
  
  if (Serial.available() > 0) {
    char input = Serial.read(); // Read one byte from the serial buffer
    
    if (input == '0') {
      hi();
      digitalWrite(calls, HIGH);
    } else {
      hi();
      digitalWrite(calls, LOW);
    }
  }
  ///
  ///
  int x = digitalRead(ultledc); // Read ultrasonic button state
  int y = digitalRead(motorledc); // Read motor button state
  ///
  ///
  if (x == LOW) {
    digitalWrite(ultled, HIGH);
  } else {
    digitalWrite(ultled, LOW);
  }
  ///
  ///
  
  if (y == LOW) {
    digitalWrite(motorled, HIGH);
  } else {
    digitalWrite(motorled, LOW);
  }
  
  
}

void hi() {
  digitalWrite(trigpin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigpin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigpin, LOW); 

  duration = pulseIn(echopin, HIGH); 
  distance = duration * 0.034 / 2; 
  Serial.println(distance);
  
  if (distance <= 83) {
    digitalWrite(motor, HIGH);
    Serial.println("Off ");
    digitalWrite(motorled, HIGH);
  } else {
    digitalWrite(motor, LOW);
    Serial.println("On ");
    digitalWrite(motorled, LOW);
  }
  
  delay(1000); // Adjust delay as needed (e.g., 1 second)
}