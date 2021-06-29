#include<Servo.h>
Servo servo;
int servopin=5;
int cm;
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
void setup() {
  Serial.begin(9600);
  servo.attach(servopin);
}

void loop() {
  cm = 0.01723 * usdistance(6, 8);
  Serial.print(cm);
  Serial.println("cm");
  if(cm<10)
  {
    servo.write(180);
    delay(1000);
    servo.write(90);
  }
  
}
