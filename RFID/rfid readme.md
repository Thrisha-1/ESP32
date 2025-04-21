# 🔐 ESP32 RFID exp
This project demonstrates a simple RFID-based home automation system using the ESP32. It reads RFID tags via UART and triggers different LEDs based on valid UID recognition.

---

## 🚀 Features

- ✅ Supports **three pre-defined UIDs**
- ✅ **Reads RFID tags** using UART2 (GPIO16 & GPIO17)
- ✅ **Controls 3 LEDs** corresponding to different users
- ✅ Serial monitor logs every UID scanned

---

## 🧰 Hardware Used

| Component           | Description                   |
|--------------------|-------------------------------|
| ESP32 Dev Module   | Microcontroller                |
| RFID Reader (UART) | Connects via GPIO16 (RX), GPIO17 (TX) |
| LEDs (x3)          | Status indicators              |
| Resistors          | 220Ω (for LEDs)                |
| Jumper Wires       | For connections                |
| Breadboard         | For prototyping                |

---

## 🖼️ Circuit Connections

| Component  | ESP32 Pin |
|------------|-----------|
| RFID RX    | GPIO16    |
| RFID TX    | GPIO17    |
| LED1       | GPIO25    |
| LED2       | GPIO26    |
| LED3       | GPIO2     |

> 📌 All LEDs must be connected with a 220Ω resistor in series.

---

## 📦 Software Requirements

- Arduino IDE with ESP32 board support
- No external libraries required

---

## 🔧 How It Works

1. The ESP32 listens to the RFID module over UART2.
2. When a tag is scanned:
   - It checks the UID against three pre-defined values.
   - If a match is found:
     - It **blinks the corresponding LED**.
     - A confirmation is printed to the Serial Monitor.
   - If no match:
     - It prints **"Unknown UID"** in the Serial Monitor.
---

## 📋 Predefined UIDs

| UID          | LED (GPIO) | Color/Action |
|--------------|------------|--------------|
| `0002306949` | GPIO25     | LED1 Blinks  |
| `0002312277` | GPIO26     | LED2 Blinks  |
| `0002307809` | GPIO2      | LED3 Blinks  |

---

## 💻 How to Upload

1. Open the `.ino` file in Arduino IDE.
2. Connect your ESP32.
3. Select:
   - **Board**: ESP32 Dev Module
   - **Port**: (your COM port)
4. Click **Upload**.
5. Open **Serial Monitor** at 115200 baud to view output.

---
