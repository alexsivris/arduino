const int motorPin = 3;
const int analogMotorIn = 0;
int value=0;
int motorSpeed=0;
void setup() {
  // put your setup code here, to run once:

  pinMode(motorPin,OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(motorPin,HIGH);
  value= analogRead(analogMotorIn);
  motorSpeed= map(value,0,1023,0,255);
    Serial.println(motorSpeed);

  digitalWrite(motorPin,motorSpeed);
  delay(3000);
}
