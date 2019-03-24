#include <SoftwareSerial.h>
#include <FastLED.h>
#include <EEPROM.h>

//uncomment to enable serial debug mode
//#define DEBUG

//configure LED-Controller connection here
#define NUM_LEDS 1
#define DATA_PIN 2
#define CLK_PIN  3

//configure SoftwareSerial connection here
#define SER_RX 8
#define SER_TX 9
#define SER_TIMEOUT 1000
#define SER_BAUD 9600
#define STARTUP_DELAY 10
#define LINEEND_CHAR '\r\n'

CRGB led_strip[NUM_LEDS];

//flags that are set by the wifi-loop
bool F_CONNECTED = false;
bool F_SERVER = false;
bool F_INIT = false;
bool F_FAILSTATE = false;
bool F_FAILSTATESWITCHED = false;

//other options
#define BLINKFREQ 800 //ms frequency to blink on errors or other notifications

#include "led_settings.h"
#include "colorstorage.h"
#include "transitions.h"
#include "status.h"
#include "commands.h"
#include "serial_interface.h"
#include "modes.h"


//startup procedure
void setup() {
  wifi_setup();
  led_setup();
  load_startup_color();

  #ifdef DEBUG
    Serial.begin(115200);
    Serial.println("Debug enabled");
  #endif
}

void loop() {
  wifi_loop();
  mode_loop();
}
