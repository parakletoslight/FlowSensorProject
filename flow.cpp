#include <Arduino.h>
#include "flow.h"
#include "system.h"

// ===== PIN =====
#define FLOW_SENSOR_PIN 34

// ===== TIME =====
unsigned long lastTime = 0;

// ===== ISR =====
void IRAM_ATTR flowISR() {
    pulseCount++;
}

// ===== INIT =====
void initFlowSensor() {
    pinMode(FLOW_SENSOR_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), flowISR, FALLING);
    lastTime = millis();
}

// ===== UPDATE FLOW (YF-S201 CORRECT FORMULA) =====
void updateFlow() {

    if (millis() - lastTime >= 1000) {

        static unsigned long lastPulse = 0;
        unsigned long pulses = pulseCount - lastPulse;

        // Frequency (Hz)
        float frequency = pulses;

        // L/min
        float flowLmin = frequency / 7.5;

        // Convert to mL/s
        flowRate = (flowLmin * 1000.0) / 60.0;

        // Accumulate total volume
        totalVolume += flowRate;

        // Cost
        totalCost = (totalVolume / 80.0) * 12.0;

        lastPulse = pulseCount;
        lastTime = millis();
    }
}