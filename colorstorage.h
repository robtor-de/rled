void save_startup_color(color startupcolor) {
  EEPROM.put(0,startupcolor);
}

void load_startup_color() {
  color startupcolor;

  EEPROM.get(0,startupcolor);

  set_rgb(startupcolor);
}
