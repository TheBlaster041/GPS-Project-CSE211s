# GPS Location Tracker with Tiva C and NEO-6M

## 📍 Overview

This project is part of the CSE211s [Spring 2025] course - *Introduction to Embedded Systems*.  
The goal is to build an embedded system using the TM4C123G (Tiva C) LaunchPad and a NEO-6M GPS module to:
- Continuously collect real-time GPS coordinates while moving.
- Display location info on a PC (via UART) or an LCD.
- Match current coordinates with predefined landmarks (e.g., faculty halls) and display the nearest one.

---

## 🛠 Hardware Requirements

- TM4C123GXL LaunchPad (Tiva C Series)
- NEO-6M GPS Module
- USB to UART connection cables
- (Optional) LCD display
- (Optional) Portable power supply (e.g., battery)

---

## 💻 Software Requirements

- Keil µVision IDE (or any ARM C development environment)
- TivaWare library
- Embedded C

---
## 📦 Project Structure
GPS-Project-CSE211s-main/
│
├── headers/ # Header files for HAL, drivers, services
│ ├── CAL/ # Component Abstraction Layer (LCD, GPS, LED, MAP)
│ ├── MCAL/ # Microcontroller Abstraction Layer (UART, GPIO, SYSTIC)
│
├── services/ # Support files and libraries
│ ├── Bit Math Lib/ # Bit manipulation macros
│ ├── Startup Code/ # Assembly startup file
│ └── TIVA C Lib/ # TM4C register definitions
│
├── src/ # Source files
│ ├── APP/ # Application logic (main.c)
│ ├── CAL/ # Component source files
│ └── MCAL/ # Peripheral drivers



