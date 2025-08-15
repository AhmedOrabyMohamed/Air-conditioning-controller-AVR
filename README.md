# Air Conditioning Controller (AVR)

## 📌 Project Overview
This project is a smart air conditioning control system using **AVR** microcontroller, **temperature sensor**, **keypad**, and **LCD display**.  
The user can enter the desired temperature using the keypad, and the system will measure the actual room temperature using the sensor.  
Based on the comparison, the system turns on LEDs to indicate the cooling or heating state.

---

## ⚙️ Features
- User input for desired temperature via **keypad**.
- Real-time room temperature measurement via **temperature sensor**.
- LCD display for showing entered and measured temperatures.
- LED indicators:
  - **Green LED**: Desired temperature is higher than room temperature.
  - **Red LED**: Desired temperature is lower than room temperature.
  - **All LEDs OFF**: Temperatures are equal.

---

## 🛠 Components Used
- AVR microcontroller (e.g., ATmega32)
- Temperature sensor
- Keypad (for user input)
- LCD display
- Green LED
- Red LED
- Resistors & wires

---

## 📋 How It Works
1. User enters the desired temperature using the keypad.
2. The system reads the actual room temperature from the sensor.
3. The microcontroller compares both values:
   - If **desired temperature > room temperature** → Green LED ON.
   - If **desired temperature < room temperature** → Red LED ON.
   - If both are equal → All LEDs OFF.
4. The results are displayed on the LCD.

---
