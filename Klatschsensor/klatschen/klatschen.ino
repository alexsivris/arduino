#define soundRead A0
#define led1 0
int soundReading = 0;
bool geklatscht = false;
bool initReading = true;
int klatschCounter = 0;
int klatschCounter2 =0;

int previousValue = 0;

int ledArray[3] = {0,1,2};

int sumValues = 0;
int meanCounter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundRead,INPUT);
  pinMode(led1, OUTPUT);
  pinMode(ledArray[1], OUTPUT);
  pinMode(ledArray[2], OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 soundReading = analogRead(soundRead);

 if (initReading)
  {
    previousValue = soundReading;
    initReading = false;
  }
  
  if ((soundReading > (previousValue+20)) || (soundReading < (previousValue-20)))
  {
    //geklatscht
    klatschCounter++;
    klatschCounter2++;
    lightUpLed(klatschCounter);
    delay(10);
    if (klatschCounter2 == 2)
    {
      klatschCounter2 = 0;
      lightUpLed(5);
      delay(1000);
    }
  }
  soundReading = analogRead(soundRead);
  previousValue = soundReading;
  Serial.println(soundReading);
  delay(5);
}

void lightUpLed(int ctr)
{
  if (ctr >= 4)
  {
    for (int i =0;i<3;i++)
    {
        digitalWrite(i,LOW);

    }
    klatschCounter = 0;
  }
  else
  {
    digitalWrite(ctr-1,HIGH);
  }
}

