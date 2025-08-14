// set pin numbers
const int touchPin = 4;      // Your touch sensor input
const int inbuiltLedPin = 2; // Assuming your inbuilt LED is on Pin 2
const int relayPin = 5;     // Example: Let's use Pin 18 for the relay to avoid conflict with inbuiltLedPin
const int threshold = 30;   // Set the threshold (adjust based on your touch sensor)
int deviceState = LOW;       // The current state for both the inbuilt LED and relay
int touchState;             // The current reading from the input pin
int lastTouchState = LOW;   // The previous reading from the input pin
unsigned long lastDebounceTime = 0; // The last time the output pins were toggled
unsigned long debounceDelay = 50;   // The debounce time; increase if the output flickers
void setup() {
  pinMode(inbuiltLedPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  // Set initial state for both (OFF)
  digitalWrite(inbuiltLedPin, deviceState);
  digitalWrite(relayPin, !deviceState);
}
void loop() {
  // Read the state of the touch pin
  int reading = touchRead(touchPin);
  // Binarize touch reading for easy operation
  if (reading < threshold) {
    reading = HIGH; // Assuming HIGH when touched (adjust if your sensor is inverted)
  } else {
    reading = LOW;
  }
  // If the pin is touched:
  if (reading != lastTouchState) {
    // Reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:
    // If the touch state has changed:
    if (reading != touchState) {
     touchState = reading;
      // Only toggle the devices if the new touch state is HIGH (touched)
      if (touchState == HIGH) {
        deviceState = !deviceState; // Toggle the state for both
      }
    }
  }
  // Set both the inbuilt LED and the relay to the current deviceState
  digitalWrite(inbuiltLedPin, deviceState);
  digitalWrite(relayPin, !deviceState);

 // Save the reading. Next time through the loop, it'll be the lastTouchState:
  lastTouchState = reading;
}