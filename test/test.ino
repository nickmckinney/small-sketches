#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306();

#define BUTTON_A 9
#define BUTTON_B 6
#define BUTTON_C 5
#define LED 13

void setup() {
  Serial.begin(9600);

  Serial.println("OLED FeatherWing test");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  Serial.println("OLED begun");

  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();

  Serial.println("IO test");

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("This is Lucy's\nFeather! Dad and Lucyput it together!");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
