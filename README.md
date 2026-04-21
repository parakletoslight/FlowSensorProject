# 💧 Flow Sensor Meter & Display System

## 🎯 Project Objective
This system is designed to measure and control the dispensing of a liquid using a flow sensor and an ESP32 microcontroller. It accurately tracks volume, calculates flow rate, computes real-time cost, and automatically halts dispensing when the target volume is reached.

## 🧰 Hardware Requirements
* **Microcontroller:** ESP32 (Standard 38-pin DevKit)
* **Flow Sensor:** YF-S201 
* **User Input:** Push Button
* **Display:** I2C Screen 
* **Actuator:** Pump/Valve Relay 

## 🧩 System Modules (Feature Branches)

### 🌊 1. Flow Sensor Logic (`flow-sensor-reading`)
* **Hardware Pin:** GPIO 25
* **Function:** Uses an Interrupt Service Routine (ISR) to detect sensor pulses. Converts raw pulses into real-time Flow Rate (L/min) and Total Volume Dispensed (ml).

### 🔘 2. User Input & Control (`user-input`)
* **Hardware Pin:** GPIO 26
* **Function:** Utilizes a debounced push button to manually start and stop the dispensing process. 
* **Safety Feature:** Includes an auto-shutoff safety interlock that forces the pump to stop once the target dispensing limit of **850 ml** is reached.

### 💰 3. Cost Calculation (`cost-calculation`)
* **Function:** Continuously runs real-time mathematical conversions based on the active flow volume.
* **Pricing Standard:** Configured to calculate exactly 12 Kenyan Shillings (KSh) per 80 milliliters of dispensed liquid.

## 🚀 Setup & Assembly
*(Note: Master loop and setup execution will be handled in `FlowSensorProject.ino` once all hardware modules are fully merged into the main branch.)*
