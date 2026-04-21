// --- USER INPUT & BUTTON LOGIC ---
const int BUTTON_PIN = 26; 
bool isDispensing = false;

// Pulling in the volume from your sensor branch
extern float totalVolumeML; 

// Debounce variables
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
int lastButtonState = HIGH;
int buttonState;

void setupUserInput() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void checkButton() {
  // AUTO-SHUTOFF FEATURE: Force stop if we hit the 850ml target
  if (totalVolumeML >= 850.0 && isDispensing == true) {
    isDispensing = false; 
  }

  int reading = digitalRead(BUTTON_PIN);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      // Start/Stop manually with the button
      if (buttonState == LOW) {
        // Only allow manual start if we haven't hit the limit yet
        if (totalVolumeML < 850.0 || isDispensing == true) {
             isDispensing = !isDispensing;
        }
      }
    }
  }
  lastButtonState = reading;
}
