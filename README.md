# ESP32 Built-in Touch Pin Relay Control
This project uses the ESP32’s built-in capacitive touch pin to toggle both the onboard LED and an external relay. It includes debounce logic to avoid false triggers from noise or accidental touches.

## Features
- Uses ESP32's `touchRead()` on a built-in touch-capable pin.
- Toggles both onboard LED and relay together.
- Debounce logic to prevent multiple rapid toggles.
- Configurable touch threshold sensitivity.

## Adjustable Parameters
- `threshold` — Touch sensitivity threshold. Lower values = more sensitive.
- `debounceDelay` — Time in milliseconds to filter out rapid touches.

## How It Works
1. `touchRead()` measures capacitance on the chosen touch pin.
2. If the reading is below the `threshold`, it’s treated as a touch.
3. Debounce code ensures stable detection.
4. On a valid touch, the relay and LED toggle their states.

## Hardware Required
- ESP32 board (with touch-capable pins)
- Relay module (for switching external devices)
- No external touch sensor needed — uses built-in touch pin.
