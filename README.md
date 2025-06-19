# smart-car-parking-system
# 🚗 Smart Car Parking System (Arduino + Python)

An automated car parking system that detects vehicle presence, counts available parking slots, and opens the gate using a **servo motor**. Includes **voice command support** using Python and speech recognition.

## 🔧 System Components
- **Arduino Mega**
- **IR or Ultrasonic Sensors**
- **16x2 LCD Display with I2C**
- **Servo Motor**
- **Python (speech recognition for voice commands)**

## 💡 Features
- Auto-detection of car entry and exit
- LCD displays available parking slots
- Gate opens only if space is available
- Voice command: say “open” to control the gate

## 📂 Included Files
- `code/` → C++ (Arduino) and Python voice control

- `diagrams/` → Block diagram, flowchart, and circuit layout

## 📦 How It Works
1. IR sensors detect entry/exit
2. Slot count updates on LCD
3. Gate opens with servo motor
4. User can also say “open” via Python app



## 📝 License
This project is open for educational and portfolio use under the [MIT License](LICENSE).
