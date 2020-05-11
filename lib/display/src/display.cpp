#include "display.h"

LiquidCrystal lcd(D7, D6, D5, D4, D3, D2);

void displaySetup() {
  lcd.begin(16,2);
  lcd.print("Welcomev2");
}

void displayTemp(float temp) {
  lcd.setCursor(0, 1);
  lcd.print("T=");
  lcd.setCursor(2, 1);
  lcd.print(temp);
}
