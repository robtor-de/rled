#define TIMEOUT 1000

boolean Find(String keyword){
 byte current_char = 0;
 byte keyword_length = keyword.length();
 long deadline = millis() + TIMEOUT;
 while(millis() < deadline){
  if (wifi.available()){
    char ch = wifi.read();
    if (ch == keyword[current_char])
      if (++current_char == keyword_length){
       return true;
    }
   }
  }
 return false; // Timed out
}

boolean SendCommand(String cmd, String ack){
  wifi.println(cmd); // Send "AT+" command to module
  if (!Find(ack)) {
    return false;
  }
  else {
    return true; // ack blank or ack found
  }
}


bool wifi_setup() {
  wifi.begin(115200);
  Serial.begin(115200);
  delay(1000);


  if(SendCommand("AT", "OK")) {
    color green;
    green.green = 255;
    pulse(green, 500);
    Serial.println("Wifi-Module connected successfully");
  }
  else {
    color red;
    red.red = 255;
    pulse(red, 500);
    Serial.println("Wifi-Module missing");
    return false;
  }


  delay(2000);

  if(SendCommand("AT+CWJAP_CUR?", "No AP")) {
    color blue;
    blue.blue = 255;
    fade_to_target(blue, 1000);
    Serial.println("Not connected to accesspoint");
    return true;
  }
  else {
    color green;
    green.green = 255;
    pulse(green, 800);
    Serial.println("Connected to accesspoint succesfully");
    digitalWrite(13, HIGH);
    SendCommand("AT+CIPMUX=1", "OK");
    SendCommand("AT+CIPSERVER=1", "OK");
    return true;
  }
}


color parse_col_res;
void parse_col (String input) {
  parse_col_res.red = input.substring(0,3).toInt();
  parse_col_res.green = input.substring(3,6).toInt();
  parse_col_res.blue = input.substring(6,9).toInt();
}

String ser;

void watch_serial() {
  ser = wifi.readStringUntil('\n');

  if(ser.startsWith("+IPD", 0)) {
    ser = ser.substring(ser.indexOf(':',5)+1);
    Serial.print("Received Data: ");
    Serial.println(ser);
  }

  String analyzed[8];    
  int field = 0;
  for(int i=0; i < ser.length(); i++) {
    if(field <= 4 && ser.charAt(i) != ';') {
      analyzed[field] += ser.charAt(i);
    }
    else if(field <= 4) {
      field += 1;
    }
    else {
      break;
    }
  }

  if(analyzed[0] == "s") {
    parse_col(analyzed[1]);
    switch_to_target(parse_col_res);
    Serial.println("Switch-Command-triggered");
  }
  if(analyzed[0] == "f") {
    parse_col(analyzed[1]);
    fade_to_target(parse_col_res, analyzed[2].toInt());
    Serial.println("Fade-Command-triggered");
  }
  if(analyzed[0] == "p") {
    parse_col(analyzed[1]);
    pulse(parse_col_res, analyzed[2].toInt());
    Serial.println("Pulse-Command-triggered");
  }
  if(analyzed[0] == "k") {
    parse_col(analyzed[1]);
    color p1;
    p1.red = parse_col_res.red;
    p1.green = parse_col_res.green;
    p1.blue = parse_col_res.blue;
    parse_col(analyzed[2]);
    strobe(p1, parse_col_res, analyzed[3].toInt(), analyzed[4].toInt(), analyzed[5].toInt());
    Serial.println("Strobe-Command-triggered");
  }
  if(analyzed[0] == "a") {
    turn_to_default(analyzed[1].toInt());
    Serial.println("On-Command-triggered");
  }
  if(analyzed[0] == "n") {
    turn_off(analyzed[1].toInt());
    Serial.println("Off-Command-triggered");
  }
  
}

