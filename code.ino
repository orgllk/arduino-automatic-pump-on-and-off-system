int trigPin = 4;
int echoPin = 12;
int led = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
long duration, distance;
digitalWrite(trigPin,HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin, LOW);
duration=pulseIn(echoPin, HIGH);
distance =(duration/2)/29.1;
Serial.print(distance);
Serial.println("CM");
delay(10);
if((distance<=10))
{
digitalWrite(led, HIGH);
}
else if(distance>10)
{
digitalWrite(led, LOW);
}
}