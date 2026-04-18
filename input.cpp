#include <Arduino.h>
#include "input.h"

static int buttonPin;
static bool lastState = HIGH;
static unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void initButton(int pin) {
    buttonPin = pin;
    pinMode(buttonPin, INPUT_PULLUP);
}

bool checkButtonPressed() {
    bool reading = digitalRead(buttonPin);

    if (reading != lastState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading == LOW && lastState == HIGH) {
            lastState = reading;
            return true;
        }
    }

    lastState = reading;
    return false;
}