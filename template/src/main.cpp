#include <Arduino.h>
#include "requests.h"

// Include sensor libraries here

int resetCounter = 0;

void setup() {
  // Sensors
  // initialize sensors here
  // Requests
  init_wifi();
  init_timer();

  delay(500);

  // Serial.begin(115200);
  // while(!Serial) {};
}

void loop() {
  if(updateFlag()) {
    String payload;
    // Read sensors
    // read from available sensors here with format:
    // payload = read_sensor_function();
    // send_data(payload);

    updateFlagToFalse();

    resetCounter++;
  }

  if(resetCounter >= 720) {
    ESP.restart();
  }

  delay(10);
}