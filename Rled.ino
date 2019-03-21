#include <SoftwareSerial.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 2
#define CLK_PIN  3

SoftwareSerial wifi(9, 8);
CRGB led_strip[NUM_LEDS];


#include "led_settings.h"
#include "transitions.h"
#include "lightshow_functions.h"
#include "modes.h"
#include "esp.h"


color c1, c2, c3;

void setup() {
  // put your setup code here, to run once:
  led_setup();
  turn_off(0);


  if(wifi_setup()) {
    turn_to_default(10000);
  }
  else {
    turn_to_default(10000);
  }




}

void loop() {
  // put your main code here, to run repeatedly:
  watch_serial();
}
