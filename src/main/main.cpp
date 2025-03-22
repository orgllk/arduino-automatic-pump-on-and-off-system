#include <Arduino.h>
// made by orgllk
// 4.0
// auto pump
#define level1 3
#define level2 4
#define top 5
#define motorrela 6
#define globelled 7
#define chargebut 8
#define charge 9
#define chargeled 10
#define chargecheck 11
#define motorrelaled 12

void setup() {
  pinMode(level1, INPUT);
  pinMode(level2, INPUT);
  pinMode(top, INPUT);
  pinMode(chargeled, OUTPUT);
  pinMode(chargebut, OUTPUT);
  pinMode(charge, OUTPUT);
  pinMode(chargecheck, INPUT);
  pinMode(motorrela, OUTPUT);
  pinMode(motorrelaled, OUTPUT);
  pinMode(globelled, OUTPUT);
}

void loop() {
  digitalWrite(globelled, HIGH); // Turn on global LED

  // Example logic for charge control
  if (digitalRead(chargebut) == HIGH) {
    digitalWrite(charge, HIGH);
  } else {
    digitalWrite(charge, LOW);
  }
  if (digitalRead(chargecheck) == HIGH) {
    digitalWrite(chargeled, HIGH); 
  } else {
    digitalWrite(chargeled, LOW);
  }

  // Example logic for water level sensors
  if (digitalRead(level1) == HIGH && digitalRead(level2) == HIGH && digitalRead(top) == HIGH) {
    digitalWrite(motorrela, HIGH); // Turn off motor pump
    digitalWrite(motorrelaled, HIGH);
} else {
    digitalWrite(motorrela, LOW); // Turn on motor pump
    digitalWrite(motorrelaled, LOW);
}
}