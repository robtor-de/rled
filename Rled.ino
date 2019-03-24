#include <SoftwareSerial.h>
#include <FastLED.h>
#include <EEPROM.h>


//configure LED-Controller connection here
#define NUM_LEDS 1
#define DATA_PIN 2
#define CLK_PIN  3

//configure SoftwareSerial connection here
#define SER_RX 9
#define SER_TX 8
#define SER_TIMEOUT 1000
#define SER_BAUD 115200
#define STARTUP_DELAY 1500
#define LINEEND_CHAR '\n'

CRGB led_strip[NUM_LEDS];

//flags that are set by the wifi-loop
bool F_CONNECTED = false;
bool F_SERVER = false;
bool F_INIT = false;
bool F_FAILSTATE = false;



#include "led_settings.h"
#include "colorstorage.h"
#include "transitions.h"
#include "status.h"
#include "commands.h"
#include "serial_interface.h"



void setup() {
  wifi_setup();
  led_setup();
  load_startup_color();
}

void loop() {
  // put your main code here, to run repeatedly:
  wifi_loop();
}
