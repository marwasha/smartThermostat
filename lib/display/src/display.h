#include "application.h"
#include "LiquidCrystal/LiquidCrystal.h"

LiquidCrystal lcd(D7, D6, D5, D4, D3, D2);

void displaySetup();
void displayTemp(float temp, int row, int col);
void displayStatus(char type, bool status);
