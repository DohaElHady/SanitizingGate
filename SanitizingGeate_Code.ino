
#define busygate 13
#define tmr1 6
#define tmr2 8
#define tmr3 10
#define trigPin 2
#define echopin 4
int delaytmr1=3000;
int delaytmr2=6000;
int delaytmr3=10000;
int entrancedelay=1000;
int test;
long duration, distance ,human=60;

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tmr1, INPUT);
  pinMode(tmr2, INPUT);
  pinMode(tmr3, INPUT);
  pinMode(busygate, OUTPUT);
  analogWrite(busygate, 0);
}


void loop() 
  {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if (distance < human) 
   {
      Serial.println(distance);
      delay(entrancedelay);
      analogWrite(busygate, 255);
      sanitizerDelay ();
      analogWrite(busygate, 0);
      }
    delay(50);
    }


void sanitizerDelay ()
{ // Multiple delay options for the sanitizer spraying period, controlled by switches
  if (digitalRead(tmr1)==HIGH)
    delay(delaytmr1);
  
  else if (digitalRead(tmr2)==HIGH)
    delay(delaytmr2);
  
  else if (digitalRead(tmr3)==HIGH)
    {
      delay(delaytmr3);
      Serial.println(delaytmr3);
    }
 
  else 
   delay(delaytmr1);
   
}
