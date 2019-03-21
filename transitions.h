//linear fade interpolation
int linear(int d_change, int d_time, int start, int x) {
  double result = ((float)d_change/(float)d_time) * (float)x + (float)start;
  return (int) result;
}


//fade from color f to color t in duration d linear
void linear_fade(color f, color t, int d) {
  int d_red, d_green, d_blue = 0;

  d_red = t.red - f.red;
  d_green = t.green - f.green;
  d_blue = t.blue - f.blue;

  color target;
  long current_millis = millis();

  while(true) {
    long now = millis() - current_millis;
    if(now > d) {
      break;
    }
    color target;
    target.red = linear(d_red, d, f.red, now);
    target.green = linear(d_green, d, f.green, now);
    target.blue = linear(d_blue, d, f.blue, now);
    set_rgb(target);
  }

}
