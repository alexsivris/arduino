#define triggerPin 2
#define echoPin  7
#define buzzer 1

int value=0;
int freq=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //tone(buzzer,4400);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  value = pulseIn(echoPin, HIGH);
  if (value >= 0) 
  {
    value = value * 0.034/2;
    Serial.println(value);
    if (value > 50)
      freq = 2000;
    else if (value < 40)
      freq = 3000;
     else if (value < 30)
      freq = 4000;
     else if (value < 20)
      freq = 4500;

     tone(buzzer,freq);
    
  }
  delay(60);
}
