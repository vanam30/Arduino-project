#include <Servo.h>
#define green 13
#define orange 12
#define red 11
#define buzzer 10
int cm = 0;
Servo servo;
int ir1 = 2;
int servo_pin =5;
int val;

long usdistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(green,OUTPUT);
  pinMode(orange,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ir1,INPUT);
  servo.attach(servo_pin);
  servo.write(0);
}

void loop()
{
  cm = 0.01723 * usdistance(6, 7);
  Serial.print(cm);
  Serial.println("cm");
  delay(100);
  val = digitalRead(ir1);

  if (val==0)
  {
    servo.write(0);
  }
  if (val==1)
  {
    delay(2000);
    servo.write(90);
  
    }
  
  if(cm>=10&& cm<=15)
  {
    digitalWrite(green,HIGH);
   delay(500);
    digitalWrite(green,LOW);
   delay(500);
 
  } 
    
     else if(cm>=5 && cm<10)
  {
    digitalWrite(orange,HIGH);
    delay(500);
    digitalWrite(orange,LOW);
    delay(500);
    
     } 
       else if(cm<5&&cm>=1)
  {
    digitalWrite(red,HIGH);
    delay(500);
    digitalWrite(red,LOW);
    delay(500);
  
          tone(buzzer,660,100);
          delay(150);
          tone(buzzer,660,100);
          delay(300);
          tone(buzzer,660,100);
   }  
}
