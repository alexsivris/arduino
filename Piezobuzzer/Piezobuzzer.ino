#define buzzer 2

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer,4400);
  delay(1000);
  tone(buzzer,5000);
  delay(1000);
}
