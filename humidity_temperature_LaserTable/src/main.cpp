#include <Arduino.h>
#include "requests.h"
#include "sensor_DHT22.h"


int resetCounter = 0;

void setup() {
  // Sensors
  init_DHT22();
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

    payload = read_DHT22();
    send_data(payload);

    updateFlagToFalse();

    resetCounter++;
  }

  if(wdtFlagStatus()) {
    ESP.wdtFeed();
    wdtFlagToFalse();
  }

  if(resetCounter >= 720) {
    ESP.restart();
  }

  delay(10);
}