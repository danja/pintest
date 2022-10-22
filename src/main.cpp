#include <Arduino.h>

const int SW_1 = 16;
const int SW_2 = 4;

bool flag = false;

void IRAM_ATTR handler1()
{
  flag = !flag;
}

void setup()
{
  Serial.begin(9600);
  pinMode(SW_1, INPUT_PULLDOWN);
  pinMode(SW_2, INPUT_PULLDOWN);

  attachInterrupt(digitalPinToInterrupt(SW_1), handler1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SW_2), handler1, CHANGE);
}

void loop()
{
  Serial.println(flag);
  delay(500);
}