ESP32 OLED Video Player (SH1106 / SSD1306)
Play a looping animation/video on a 1.3" I2C OLED (or 0.96") from an ESP32, using pre-converted 1-bit frames stored in flash (PROGMEM).

Works with both common OLED controllers — SH1106 (most 1.3" I2C modules) and SSD1306 (most 0.96" modules) — switchable with one #define.

✨ Features
🎬 Loops video frames (128×64, 1-bit) stored in VideoFrame.h — no SD card needed
🖥️ Dual-controller support: SH1106 and SSD1306 via one #define
⚡ 800 kHz I2C for high frame rates (~25–60 FPS depending on FRAME_DELAY)
🔆 Max-contrast boost for brighter SSD1306 panels
🪶 Tiny flash footprint — frames live in PROGMEM

🧰 Hardware Required
Part	                                    Qty	Notes
ESP32 Dev Board (any classic ESP32)	      1	  ESP32-S2/S3 also work with minor pin changes
1.3" I2C OLED (SH1106) or 0.96" (SSD1306)	1	  128×64, I2C
Jumper wires	                            4	

Wiring (ESP32 ↔ OLED)
OLED Pin	ESP32 Pin
VCC	3V3
GND	GND
SDA	GPIO 21
SCL	GPIO 22
For Arduino Uno/Nano: SDA → A4, SCL → A5 (and VCC → 5V if the module has a regulator — check your board).

📦 Software Required
Arduino IDE (or PlatformIO)
ESP32 Arduino Core (Boards Manager → esp32 by Espressif Systems)
Libraries (Library Manager):
Adafruit GFX
Adafruit SSD1306
Adafruit SH110X (only needed if you use SH1106)

🚀 Getting Started
Clone/download main.ino and Videoframe.h in same folder.
Open main.ino in Arduino IDE.
Install the libraries listed above.
Select your OLED controller in the code:
C++

//#define PAKAI_SSD1306     // uncomment for 0.96" SSD1306
#define PAKAI_SH1106        // default: 1.3" I2C OLEDs are usually SH1106

Make sure VideoFrame.h exists in the same folder (see below on how to generate it).
Select board ESP32 Dev Module → Upload → open Serial Monitor (115200).
If the display shows video — done! 🎉

⚙️ Configuration
Setting	Where	Default	What it does
Controller	#define PAKAI_SSD1306 / PAKAI_SH1106	SH1106	Selects the OLED driver library & init sequence
I2C address	#define OLED_I2C_ADDR	0x3C	Change to 0x3D if the module uses the other address
Frame speed	FRAME_DELAY (in VideoFrame.h)	your value	ms per frame — 40 ms ≈ 25 FPS
I2C speed	Wire.setClock(800000)	800 kHz	Lower to 400000 if you see glitches/tearing
Brightness	SSD1306-only block in setup()	0xFF (max)	SH1106: add display.command(0x81); display.command(0xFF); if dim

📜 License
This project is open source — use, modify, and share freely. Attribution appreciated. (Adjust or remove as you like.)

🙏 Credits
Adafruit GFX, SSD1306, SH110X libraries

Made with ❤️ using ESP32 and OLED.
