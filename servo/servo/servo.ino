#include <Servo.h>

Servo katapultServo;
int katapultMode = 0;
int testDisplay = 7; 
const int displayPins[8]={2,3,4,5,6,7,8,9};
int readPin = 0;
int first = 0;
int buttonPressed = 0;

void setup() {
  // put your setup code here, to run once:
  katapultServo.attach(11);
  pinMode(readPin, INPUT);
  pinMode(testDisplay, OUTPUT);
  for (int i=0;i<8;i++)
    pinMode(displayPins[i],OUTPUT);
  attachInterrupt(2, startCountDown, RISING);
  katapultServo.write(90);
}
void loop() {
  // put your main code here, to run repeatedly:
  buttonPressed = digitalRead(readPin);

  Serial.println(buttonPressed);
  if (first && !katapultMode)
  {
          katapultServo.write(0);

  }
    if (katapultMode)
    {
      for (int i=9;i>=0;i--)
      {
        displayNumber(i);
        delay(1000);
      }
      // SHoot!
      katapultServo.write(90);
      delay(2000);
    }
}
//const int displayPins[8]={2,3,4,5,6,7,8,9};
void displayNumber(int _num)
{
  switch (_num)
  {
    case 0: digitalWrite(displayPins[0],HIGH);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],HIGH);
            digitalWrite(displayPins[4],HIGH);
            digitalWrite(displayPins[5],HIGH);
            digitalWrite(displayPins[6],LOW);
            break;
    case 1: digitalWrite(displayPins[0],LOW);
            digitalWrite(displayPins[3],LOW);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[4],LOW);
            digitalWrite(displayPins[5],LOW);
            digitalWrite(displayPins[6],LOW);
            break;
    case 2: digitalWrite(displayPins[0],HIGH);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],LOW);
            digitalWrite(displayPins[3],HIGH);
            digitalWrite(displayPins[4],HIGH);
            digitalWrite(displayPins[5],LOW);
            digitalWrite(displayPins[6],HIGH);
            break;
    case 3: digitalWrite(displayPins[0],HIGH);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],HIGH);
            digitalWrite(displayPins[4],LOW);
            digitalWrite(displayPins[5],LOW);
            digitalWrite(displayPins[6],HIGH);
            break;
    case 4: digitalWrite(displayPins[0],LOW);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],LOW);
            digitalWrite(displayPins[4],LOW);
            digitalWrite(displayPins[6],HIGH);
            digitalWrite(displayPins[5],HIGH);
            break;
    case 5: digitalWrite(displayPins[0],HIGH);
    digitalWrite(displayPins[4],LOW);
    digitalWrite(displayPins[1],LOW);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],HIGH);
            digitalWrite(displayPins[5],HIGH);
            digitalWrite(displayPins[6],HIGH);
            break;
    case 6: digitalWrite(displayPins[0],HIGH);
    digitalWrite(displayPins[1],LOW);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],HIGH);
            digitalWrite(displayPins[4],HIGH);
            digitalWrite(displayPins[5],HIGH);
            digitalWrite(displayPins[6],HIGH);
            break;
    case 7: digitalWrite(displayPins[0],HIGH);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],LOW);
            digitalWrite(displayPins[4],LOW);
            digitalWrite(displayPins[5],LOW);
            digitalWrite(displayPins[6],LOW);
            break;
    case 8: digitalWrite(displayPins[0],HIGH);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],HIGH);
            digitalWrite(displayPins[4],HIGH);
            digitalWrite(displayPins[5],HIGH);
            digitalWrite(displayPins[6],HIGH);
            break;
    case 9: digitalWrite(displayPins[0],HIGH);
            digitalWrite(displayPins[1],HIGH);
            digitalWrite(displayPins[2],HIGH);
            digitalWrite(displayPins[3],HIGH);
            digitalWrite(displayPins[4],LOW);
            digitalWrite(displayPins[5],HIGH);
            digitalWrite(displayPins[6],HIGH);
            break;
    
    default:
    break;
     
  }
}

void startCountDown()
{
  if (first)
    katapultMode = 1;
  else
    first = 1;
}

