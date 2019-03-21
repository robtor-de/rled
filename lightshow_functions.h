int squared_rise(float d_time, int d_peak, int x) {
  double result = ((float)d_peak/pow((float)d_time,2))*pow((float)x,2);
  return (int) result;
}

int squared_fall(float d_time, int d_peak, int x) {
  double result = ((float)d_peak/pow((float)d_time,2))*pow((float)x-(float)d_time,2);
  return (int) result;
}

//Create a squared pulse with peak_/r/g/b value in duration d in color c (use: c_red/c_green/c_blue)
void pulse(color peak, int d) {
  long current_millis = millis();
  float rise_time = d/4;
  float fall_time = d*3/4;
  while(true) {
    long now = millis() - current_millis;    
    if(now > rise_time) {
      break;
    }
    color target;
    target.red = squared_rise(rise_time, peak.red, now);
    target.green = squared_rise(rise_time, peak.green, now);
    target.blue = squared_rise(rise_time, peak.blue, now);
    set_rgb(target);
  }
  current_millis = millis();
  while(true) {
    long now = millis() - current_millis;    
    if(now > fall_time) {
      break;
    }
    color target;
    target.red = squared_fall(fall_time, peak.red, now);
    target.green = squared_fall(fall_time, peak.green, now);
    target.blue = squared_fall(fall_time, peak.blue, now);
    set_rgb(target);
  }
}

//Strobe the colors part1 and part2 in change, set duration of both parts with d_part1/2 and set complete duration d --> exits with color1
void strobe(color part1, color part2, int d_part1, int d_part2, int duration) {
  long current_millis = millis();
  while(millis() - current_millis < duration) {
    set_rgb(part1);
    delay(d_part1);
    set_rgb(part2);
    delay(d_part2);
  }
  set_rgb(part1);
}

void disable_light() {
  color cd;
  cd.red = 0;
  cd.green = 0;
  cd.blue = 0;
  set_rgb(cd);
}


