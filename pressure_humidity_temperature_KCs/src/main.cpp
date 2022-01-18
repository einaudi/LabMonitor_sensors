#include <Arduino.h>
#include "requests.h"
#include "sensor_XGS600.h"
#include "sensor_DHT22.h"


int resetCounter = 0;

void setup() {
  // Sensors
  init_XGS600();
  init_DHT22(0);
  init_DHT22(1);
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
    payload = read_XGS600();
    send_data(payload);

    payload = read_DHT22(0);
    send_data(payload);

    payload = read_DHT22(1);
    send_data(payload);

    updateFlagToFalse();

    resetCounter++;
  }

  if(resetCounter >= 720) {
    ESP.restart();
  }

  delay(10);
}