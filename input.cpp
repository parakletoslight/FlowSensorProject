#include <Arduino.h>
#include "input.h"

struct Button {
    int pin;
    bool lastState;
    unsigned long lastDebounceTime;
};

Button btnUp = {26, HIGH, 0};
Button btnDown = {27, HIGH, 0};
Button btnSelect = {14, HIGH, 0};

const unsigned long debounceDelay = 50;

void initButtons() {
    pinMode(btnUp.pin, INPUT_PULLUP);
    pinMode(btnDown.pin, INPUT_PULLUP);
    pinMode(btnSelect.pin, INPUT_PULLUP);
}

bool check(Button &btn) {
    bool reading = digitalRead(btn.pin);

    if (reading != btn.lastState) {
        btn.lastDebounceTime = millis();
    }

    if ((millis() - btn.lastDebounceTime) > debounceDelay) {
        if (reading == LOW && btn.lastState == HIGH) {
            btn.lastState = reading;
            return true;
        }
    }

    btn.lastState = reading;
    return false;
}

bool upPressed() { return check(btnUp); }
bool downPressed() { return check(btnDown); }
bool selectPressed() { return check(btnSelect); }