#include "display.h"

LiquidCrystal lcd(D7, D6, D5, D4, D3, D2);

void displaySetup() {
  lcd.begin(16,2);
  lcd.print("MMMA's Temp Coll");
}

void displayTemp(float temp) {
  lcd.setCursor(0, 1);
  lcd.print("T=");
  lcd.setCursor(2, 1);
  lcd.print(temp);
}

void displayStatus(char type, bool status) {
  lcd.setCursor(11, 1);
  lcd.print(type);
  lcd.setCursor(12, 1);
  lcd.print("=");
  lcd.setCursor(13, 1);
  if (status) {
    lcd.print("on ");
  } else {
    lcd.print("off");
  };
}
