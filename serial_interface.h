SoftwareSerial wifi(SER_RX, SER_TX);

//constants for serial communication messages
#define MSG_CONNECTED "#connected"
#define MSG_FAIL "#fail"
#define MSG_MISSING_CREDENTIALS "#nocredentials"
#define MSG_INIT "#init"
#define MSG_UNIT_DISABLED "#disabled"
#define MSG_DISCONNECTED "#disconnected"
#define MSG_SAVED "#saved"
#define MSG_SERVER_ENABLED "#listening"
#define MSG_SERVER_CLOSED "#closed"

//used to start serial connection to Rwifi Module
bool wifi_setup() {
  wifi.begin(SER_BAUD);
  Serial.begin(115200);
  delay(STARTUP_DELAY);
}

void command_interpreter(String command) {
  switch(command.charAt(0)) {
    case 's': 
  }
}

void serialEvent() {
  String input = Serial.readStringUntil(LINEEND_CHAR);

  if(input == MSG_CONNECTED) {
    F_INIT = true;
    F_CONNECTED = true;
    F_FAILSTATE = false;
  } else if (input == MSG_INIT) {
    F_INIT = true;
  } else if (input == MSG_FAIL) {
    F_CONNECTED = false;
  } else if (input == MSG_SERVER_ENABLED) {
    F_SERVER = true;
  } else if (input == MSG_SERVER_CLOSED) {
    F_SERVER = false;
  } else if (input == MSG_UNIT_DISABLED || input == MSG_MISSING_CREDENTIALS) {
    F_FAILSTATE = true;
  } else {
    command_interpreter(input);
  }
}



void wifi_loop() {
  if(wifi.available() > 0) {
    serialEvent();
  }
}
