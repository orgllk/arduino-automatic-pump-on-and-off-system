// made by orgllk 
// 1.5
// auto pump 
#define echopin 12
#define trigpin 4
#define LED 7
char val;
long duration; 
int distance; 
void setup() 
{
pinMode(trigpin, OUTPUT); 
pinMode (echopin, INPUT); 
Serial.begin(9600); 
pinMode (LED,OUTPUT);

}

void loop()
{ 





if (val ==('F')){ // STOP
  
  digitalWrite(LED,0);

  digitalWrite(trigpin,LOW); 
delayMicroseconds(2); 
digitalWrite(trigpin,LOW); 
delayMicroseconds(10); 
digitalWrite(trigpin,LOW); 
duration=pulseIn (echopin,HIGH); distance=duration* 0.034/2; Serial.println (distance);
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }
  
}else   { // ON 
a();
digitalWrite(trigpin,LOW); 
delayMicroseconds(2); 
digitalWrite(trigpin,HIGH); 
delayMicroseconds(10); 
digitalWrite(trigpin,LOW); 
duration=pulseIn (echopin,HIGH); distance=duration* 0.034/2; Serial.println (distance);
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }
}
return a();
}


  



   

void a(){ // BRAIN
     if (distance <= 10){
  digitalWrite (LED,1);
  Serial.write("Of  ");
   }
else {
   digitalWrite (LED,0);
   Serial.write("ON  ");

}

 
}

 




