#include "display.h"

void displaySetup() {
  lcd.begin(16,2);
}

void displayTemp(float temp, int row, int col) {
  lcd.setCursor(col, row);
  lcd.print("T=");
  lcd.setCursor(col + 2, row);
  lcd.print(temp);
}

void displayStatus(char type, float status) {
  lcd.setCursor(10, 1);
  lcd.print(type);
  lcd.setCursor(11, 1);
  lcd.print("=");
  lcd.setCursor(12, 1);
  lcd.print(status);
  /*
  if (status) {
    lcd.print("on ");
  } else {
    lcd.print("off");
  };
  */
}
