#include <Arduino.h>
#include "sensor_DHT22.h"

// Sensor db parameters
static String tab_name = "main";
static String localization = "LaserTable";
static String device = "DHT22";

const String payload_DHT22 = "tab_name=" + tab_name + "&localization=" + localization + "&device=" + device;


// Init sensor
DHT dht(DHTPIN, DHTTYPE);

void init_DHT22() {
    dht.begin();
}

String read_DHT22() {
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    while(isnan(t) || isnan(h)) {
        t = dht.readTemperature();
        h = dht.readHumidity();
    }

    return payload_DHT22 + "&temperature=" + String(t) + "&humidity=" + String(h);
}
