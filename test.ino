

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "VideoFrame.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

#define OLED_I2C_ADDR 0x3C   
#define PAKAI_SH1106          
#ifdef PAKAI_SSD1306
  #include <Adafruit_SSD1306.h>
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  #define WARNA_LAYAR WHITE

#elif defined(PAKAI_SH1106)
  #include <Adafruit_SH110X.h>
  Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  #define WARNA_LAYAR SH110X_WHITE
#endif

unsigned long previousMillis = 0;
int currentFrame = 50;

void setup() {
  Serial.begin(115200);
  delay(300);

  #ifdef PAKAI_SSD1306
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
      for (;;);
    }
    
    display.ssd1306_command(SSD1306_SETCONTRAST);
    display.ssd1306_command(0xFF);

  #elif defined(PAKAI_SH1106)
    if (!display.begin(OLED_I2C_ADDR, true)) { 
      for (;;);
    }
  #endif

  Wire.setClock(800000);

  display.clearDisplay();
  display.display();

  Serial.println(F("OLED siap."));
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= FRAME_DELAY) {

    previousMillis = currentMillis;

    display.clearDisplay();
    display.drawBitmap(0, 0, video_frames[currentFrame], SCREEN_WIDTH, SCREEN_HEIGHT, WARNA_LAYAR);
    display.display();

    currentFrame++;

    if (currentFrame >= TOTAL_FRAMES) {
      currentFrame = 50;
    }
  }
}
