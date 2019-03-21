struct color {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} current_color;

void led_setup() {
  //add LED Controller type with DATA_PIN and CLK_PIN as led_strip with 1 LED (complete Strip Controller)
  FastLED.addLeds<P9813, DATA_PIN, CLK_PIN>(led_strip, NUM_LEDS);
}

void set_rgb(color c) {
  led_strip[0].setRGB(c.red, c.green, c.blue);
  FastLED.show();
  current_color = c;
}


void set_hsv(int h, int s, int v) {
  led_strip[0].setHSV(h, s, v);
}
