void fade_to_target(color target, int duration) {
  linear_fade(current_color, target, duration);
  current_color = target;
}
void switch_to_target(color target) {
  set_rgb(target);
  current_color = target;
}

void turn_off(int duration) {
  color black;
  black.red = 0;
  black.green = 0;
  black.blue = 0;
  
  fade_to_target(black, duration);
  current_color = black;
}

void turn_to_default(int duration) {
  color white;
  white.red = 255;
  white.green = 255;
  white.blue = 255;

  fade_to_target(white, duration);
  current_color = white;
}

