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
  delay(STARTUP_DELAY);
}

void command_interpreter(String command) {
  String tail = command.substring(2);

  switch(command.charAt(0)) {
    case 's': c_set(&tail); break;
    case 'p': c_store(&tail); break;
  }
}

void serialEvent() {
  String input = wifi.readStringUntil(LINEEND_CHAR);

  #ifdef DEBUG
    Serial.println(input);
  #endif

  if(input.startsWith(MSG_CONNECTED)) {
    F_INIT = true;
    F_CONNECTED = true;
    F_FAILSTATE = false;

    #ifdef DEBUG
      Serial.println("Starting Server...");
    #endif

    wifi.println("&server");
    st_connect();
  } else if (input.startsWith(MSG_INIT)) {
    F_INIT = true;
    st_init();
  } else if (input.startsWith(MSG_FAIL)) {
    F_CONNECTED = false;
    st_fail();
  } else if (input.startsWith(MSG_SERVER_ENABLED)) {
    F_SERVER = true;
    st_server();
  } else if (input.startsWith(MSG_SERVER_CLOSED)) {
    F_SERVER = false;
    st_fail();
  } else if (input.startsWith(MSG_UNIT_DISABLED) || input.startsWith(MSG_MISSING_CREDENTIALS)) {
    F_FAILSTATE = true;
    st_fail();
  } else {
    command_interpreter(input);
  }
}



void wifi_loop() {
  if(wifi.available() > 0) {
    serialEvent();
  }
}
