#include <Servo.h>
Servo myServo;
int potpin=0;
int Red = 8;
int Blue = 9;
int Green=10;
int val;
int trigpin=3;
int echopin=4;
long distance;
long duration;
void setup()
{
myServo.attach(6);
 pinMode(Red, OUTPUT);
 pinMode(Blue, OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}
void loop() {
  myServo.write(0);
  val=analogRead(potpin);
  val = map(val, 0,1023,0,100);
  myServo.write(val);
  delay(15);
   if(distance <=100){
  digitalWrite(Red,HIGH);
  delay(3000);
  digitalWrite(Red, LOW);
  delay(3000);
   myServo.write(60);
  }
   else  { myServo.write(0);}
  if (distance<=100){
  digitalWrite(Blue, HIGH);
  delay(3000);
  digitalWrite(Blue,LOW);
  delay(3000);
   myServo.write(120);
 }
  else { myServo.write(0);}
   if (distance<=100){
  digitalWrite(Green,HIGH);
  delay(3000);
  digitalWrite(Green,LOW);
  delayMicroseconds(3000);
  myServo.write(180);
    }
  else{ myServo.write(0);}
}
void ultra(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  distance=duration*0.343/2;
}
