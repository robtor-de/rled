color temp_color;

void parsecolor(String col) {
  temp_color.red = col.substring(0,2).toInt();
  temp_color.green = col.substring(3,5).toInt();
  temp_color.blue = col.substring(6,8).toInt();
}

void c_set(String *tail) {
  parsecolor(*tail);
  set_rgb(temp_color);
}
