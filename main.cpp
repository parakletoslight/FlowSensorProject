#include <Arduino.h>
#include "display.h"
#include "input.h"
#include "system.h"

// ===== STATES =====
enum State {
    MAIN_MENU,
    DISPENSE_MENU,
    DISPENSING,
    HISTORY
};

State currentState = MAIN_MENU;

int menuIndex = 0;
int runView = 0;

// ===== SHARED VARIABLES DEFINITION =====
volatile unsigned long pulseCount = 0;
float totalVolume = 0;
float flowRate = 0;
float totalCost = 0;

// ===== SETUP =====
void setup() {
    Serial.begin(115200);

    initDisplay();
    initButtons();
}

// ===== LOOP =====
void loop() {

    switch (currentState) {

        case MAIN_MENU:
            showMainMenu(menuIndex);

            if (downPressed()) {
                menuIndex = (menuIndex + 1) % 2;
            }

            if (selectPressed()) {
                currentState = (menuIndex == 0) ? DISPENSE_MENU : HISTORY;
            }
            break;

        case DISPENSE_MENU:
            showDispenseMenu(menuIndex);

            if (downPressed()) {
                menuIndex = (menuIndex + 1) % 2;
            }

            if (selectPressed()) {
                if (menuIndex == 0) {
                    currentState = DISPENSING;
                    runView = 0;
                } else {
                    currentState = MAIN_MENU;
                }
            }
            break;

        case DISPENSING:
            showDispensing(runView);

            if (upPressed()) {
                runView = (runView + 2) % 3;
            }

            if (downPressed()) {
                runView = (runView + 1) % 3;
            }

            if (selectPressed()) {
                currentState = MAIN_MENU;
            }
            break;

        case HISTORY:
            showHistory();

            if (selectPressed()) {
                currentState = MAIN_MENU;
            }
            break;
    }

    delay(100);
}