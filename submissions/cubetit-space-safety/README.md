# Cubetit – Space Safety Mission

## Team Information
**Team Name:** Cubetit  
**Competition:** ASCEND2026  
**Mission Name:** Space Safety  

---

## Mission Overview
The Space Safety mission focuses on monitoring environmental and safety conditions in space. The CubeSat is designed to detect potential risks such as abnormal radiation levels, environmental changes, and onboard system instability.

---

## Objectives
- Monitor environmental conditions in space
- Detect abnormal radiation levels
- Ensure onboard system stability
- Transmit safety-related data to ground station

---

## System Architecture
The satellite uses an ESP32 microcontroller as the onboard computer.  
It collects sensor data, processes it, and transmits relevant safety information.

---

## Hardware Components
- ESP32
- Environmental / Radiation sensor (if applicable)
- Built-in WiFi communication (ESP32)
- USB or Battery power supply

---

## Software Description
The onboard software performs:
- Sensor data acquisition
- Data processing
- Safety condition monitoring
- Data transmission via WiFi

---

## How to Run the Code
1. Open the project in Arduino IDE.
2. Select ESP32 board.
3. Install required libraries (if applicable).
4. Upload the code to ESP32.
5. Monitor data via Serial Monitor or WiFi transmission.

---

## Folder Structure
```
cubetit-space-safety/
│── README.md
│── LICENSE
│── main.ino
```
