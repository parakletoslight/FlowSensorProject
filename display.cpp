#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"
#include "system.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void initDisplay() {
    Wire.begin(21, 22);
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.print("Starting...");
    delay(1000);
}

void showMainMenu(int index) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(index == 0 ? ">Dispense" : " Dispense");
    lcd.setCursor(0, 1);
    lcd.print(index == 1 ? ">History" : " History");
}

void showDispenseMenu(int index) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(index == 0 ? ">Start Disp" : " Start Disp");
    lcd.setCursor(0, 1);
    lcd.print(index == 1 ? ">Back" : " Back");
}

void showDispensing(int view) {
    lcd.clear();

    if (view == 0) {
        lcd.print("Flow:");
        lcd.setCursor(0, 1);
        lcd.print(flowRate, 1);
        lcd.print(" mL/s");
    } else if (view == 1) {
        lcd.print("Cost:");
        lcd.setCursor(0, 1);
        lcd.print("KSh ");
        lcd.print(totalCost, 2);
    } else {
        lcd.print("Volume:");
        lcd.setCursor(0, 1);
        lcd.print(totalVolume, 0);
        lcd.print(" mL");
    }
}

void showHistory() {
    lcd.clear();
    lcd.print("History...");
}