class A {
  public:
    A();
    int getDly();
   private:
     int m_dly; 
};
A::A() : m_dly(200)
{
  //
}
int A::getDly()
{
  return m_dly;
}

const int readingPin = 2;
const int writingPinRed = 8;
const int writingPinGreen = 9;
volatile int value = 0;

A *ptrA;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(readingPin, INPUT);
  pinMode(writingPinRed, OUTPUT);
  pinMode(writingPinGreen, OUTPUT);
  ptrA = new A();
  attachInterrupt(1,buttonPressed,RISING); // 1 ist nicht pin 1
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(value);

  if (value == 0)
  {
    digitalWrite(writingPinRed,HIGH);
    digitalWrite(writingPinGreen, LOW);

    delay(ptrA->getDly());
        digitalWrite(writingPinRed,LOW);

  }
  else
  {
    digitalWrite(writingPinGreen, HIGH);
    digitalWrite(writingPinRed,LOW);
    value = 0;
  }
  
  delay(ptrA->getDly());
}
void buttonPressed()
{
  value = 1;
}

