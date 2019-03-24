//functions for blinking
void blink_status(int count, uint8_t r, uint8_t g, uint8_t b) {
  for (int i=0; i <= count; i++) {
    led_strip[0].setRGB(r, g, b);
    digitalWrite(13, HIGH);
    delay(BLINKFREQ);
    led_strip[0].setRGB(0, 0, 0);
    digitalWrite(13, LOW);
    delay(BLINKFREQ);
  }
}

//Is executed when Wifi-Adapter is connected
void st_connect() {
  blink_status(3, 0, 255, 0);
}

//is executed when module initialized
void st_init() {
  blink_status(1, 0, 0, 255);
}

//is executed when wifi error occurs
void st_fail() {
  blink_status(5, 255, 0, 0);
}

//is executed when server is started
void st_server() {
  blink_status(1, 255, 0, 255);
}
