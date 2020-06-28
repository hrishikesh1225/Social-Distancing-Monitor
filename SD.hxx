
#include<Adafruit_NeoPixel.h>
#define ledPin D3
#define buzzerPin D2
#define echoPin D5
#define trigPin D6
#define ledNo 16
Adafruit_NeoPixel ring = Adafruit_NeoPixel(ledNo,ledPin,NEO_RGB+NEO_KHZ800);
     int minDistance = 50, maxDistance = 80;
 void setup()
{
pinMode(buzzerPin, OUTPUT); pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT); ring.begin();
  for(int i = 0; i < ledNo; i++)
  {
ring.setPixelColor(i,ring.Color(0,0,0)); }
ring.show(); }
void loop() {
  int distance = calcDistance();
  int ledsToGlow = map(distance, minDistance, maxDistance,
ledNo, 1);
  if(ledsToGlow == 16)
  {
    digitalWrite(buzzerPin, HIGH);
  }
else {
    digitalWrite(buzzerPin, LOW);
  }
  for(int i = 0; i < ledsToGlow; i++)
  {

 if(i < 6) {
ring.setPixelColor(i,ring.Color(50,0,0));//g,r,b }
    else if(i >= 6 && i < 12)
    {
ring.setPixelColor(i,ring.Color(50,50,0));//g,r,b }
    else if(i >= 12 && i < 16)
    {
ring.setPixelColor(i,ring.Color(0,50,0));//g,r,b }
  }
  for(int i = ledsToGlow; i < ledNo; i++)
  {
ring.setPixelColor(i,ring.Color(0,0,0)); }
ring.show();
  delay(150);
}
int calcDistance()
{
  long distance,duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
       distance = duration/29/2;
       if(distance >= maxDistance)
       {
         distance = maxDistance;
       }
       if(distance <= minDistance)
       {
         distance = minDistance;
       }
       return distance;
     }
