int senser = 13 ;
void setup() {
  // put your setup code here, to run once:
	pinMode(senser, INPUT);  
  pinMode(4,OUTPUT);
	Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
int s = digitalRead(senser);
if (s == HIGH){
  digitalWrite(4,HIGH);
}
}

