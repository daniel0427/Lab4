#include"SevSeg.h"
SevSeg sevseg;
byte Hour = 0;
byte Pin6;
byte Min = 1;
const int buttonPin = 6;
void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3 , 4 , 5 };
  byte segmentPins[] = {8, 9, 10, 11, 12, 13, 14, 15};
  pinMode(buttonPin, INPUT);
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(100);
}
void loop() {
  Pin6 = digitalRead(6);
         if (Pin6 == HIGH)
           Min = Hour = 0;
    sevseg.setNumber(Hour * 100 + Min, 0);
  Min++;
  if (Min == 60) {
    Min = 0;
    if (Hour == 23)
      Hour = 0;
    else
      Hour++;
  }
  for (int i = 0; i < 333333; i++)
    sevseg.refreshDisplay();

}
