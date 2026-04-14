# SPI Display Driver + Input Module

## Overview
This module implements a display and user input system for the Flow Sensor Project.

## Features
- SPI TFT display (ST7735)
- Real-time display of:
  - Volume (mL)
  - Flow rate (mL/s)
  - Cost (KSh)
- Button control (start/stop)
- Debounced input handling

## Files Added
- display.h / display.cpp
- input.h / input.cpp

## Hardware Assumptions
- ESP32 microcontroller
- ST7735 SPI TFT display
- Button using INPUT_PULLUP

## Notes
- Display updates in real time
- Button toggles dispensing state