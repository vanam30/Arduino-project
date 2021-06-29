#include<Servo.h>
int SensorInput=0;
int OutputValue=0;
Servo servo_9;
int counter;
int counter2;
void setup()
{
  pinMode(4,INPUT);
  pinMode(A0,INPUT);
  servo_9.attach(9,500,2500);
  Serial.begin(9600);
}

void loop()
{
  OutputValue=0;
  if(digitalRead(4)==HIGH){
    SensorInput = analogRead(A0);
    OutputValue=map(SensorInput,0,1023,0,180);
    servo_9.write(OutputValue);
    Serial.print(SensorInput);
    Serial.print(",");
    Serial.println(OutputValue);
  }
  else{
    OutputValue=0;
    for(counter=0;counter<180;++counter)
    {
      OutputValue=(OutputValue+1);
      servo_9.write(OutputValue);
      delay(10);
    }
    for(counter2=0;counter2<180;++counter2)
    {
      OutputValue=(OutputValue-1);
      servo_9.write(OutputValue);
      delay(10);
    }
}
}
