color temp_color;

void parsecolor(String col) {
  temp_color.red = col.substring(0,3).toInt();
  temp_color.green = col.substring(3,6).toInt();
  temp_color.blue = col.substring(6,9).toInt();
}

void c_set(String *tail) {
  parsecolor(*tail);
  set_rgb(temp_color);
}

void c_store(String *tail) {
  parsecolor(*tail);
  save_startup_color(temp_color);
}
