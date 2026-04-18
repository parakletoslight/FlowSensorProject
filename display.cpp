#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "display.h"

// ===== SPI PINS (adjust if needed) =====
#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void initDisplay() {
    tft.initR(INITR_BLACKTAB);   // IMPORTANT
    tft.setRotation(1);
    tft.fillScreen(ST77XX_BLACK);

    tft.setTextSize(1);
    tft.setTextColor(ST77XX_WHITE);

    tft.setCursor(10, 5);
    tft.print("Flow System");
}

void updateDisplay(float volume, float flowRate, float cost, bool isRunning) {

    // Clear only data area
    tft.fillRect(0, 20, 160, 100, ST77XX_BLACK);

    tft.setCursor(0, 25);
    tft.print("V:");
    tft.print(volume, 0);
    tft.print("mL");

    tft.setCursor(0, 45);
    tft.print("F:");
    tft.print(flowRate, 1);
    tft.print("mL/s");

    tft.setCursor(0, 65);
    tft.print("KSh:");
    tft.print(cost, 2);

    tft.setCursor(0, 85);
    tft.print("Status:");
    tft.print(isRunning ? "RUN" : "STOP");
}