// --- FLOW SENSOR LOGIC ---
const int SENSOR_PIN = 25; 
volatile int pulseCount = 0;
float flowRate = 0.0;
float totalVolumeML = 0.0;
unsigned long oldTime = 0;
const float calibrationFactor = 7.5; // Standard for YF-S201

// Interrupt Service Routine (ISR)
void IRAM_ATTR pulseCounter() {
  pulseCount++;
}

void setupFlowSensor() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), pulseCounter, FALLING);
}

void updateFlowReading() {
  if ((millis() - oldTime) > 1000) {
    // Disable interrupt to calculate securely
    detachInterrupt(digitalPinToInterrupt(SENSOR_PIN));
    
    // Calculate flow rate in L/min, then add to total volume in mL
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    oldTime = millis();
    totalVolumeML += (flowRate / 60.0) * 1000.0; // Convert to mL per second
    
    // Reset and re-enable
    pulseCount = 0;
    attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), pulseCounter, FALLING);
  }
}
