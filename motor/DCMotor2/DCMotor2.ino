const int motorPin = 3;
const int motorPin2 = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin,OUTPUT);
  pinMode(motorPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motorPin,HIGH);
  delay(2000);
    digitalWrite(motorPin,LOW);
  delay(2000);
    digitalWrite(motorPin2,HIGH);
  delay(2000);
    digitalWrite(motorPin2,LOW);
  delay(2000);
}
