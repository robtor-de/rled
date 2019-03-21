#include <SoftwareSerial.h>
#include <FastLED.h>


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


#include "led_settings.h"
#include "transitions.h"
#include "lightshow_functions.h"
#include "modes.h"
#include "serial_interface.h"


color c1, c2, c3;

void setup() {
  // put your setup code here, to run once:
  led_setup();
  turn_off(0);

  wifi_setup();



}

void loop() {
  // put your main code here, to run repeatedly:
  watch_serial();
}
