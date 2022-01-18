#include <Arduino.h>
#include "sensor_DHT22.h"

// Sensor db parameters
static String tab_name = "main";
static String localization0 = "KCs";
static String localization1 = "KCsTop";
static String device = "DHT22";

const String payload_DHT22_0 = "tab_name=" + tab_name + "&localization=" + localization0 + "&device=" + device;
const String payload_DHT22_1 = "tab_name=" + tab_name + "&localization=" + localization1 + "&device=" + device;

String payloads[] = {payload_DHT22_0, payload_DHT22_1};

// Init sensor
DHT dht0(DHTPIN0, DHTTYPE0);
DHT dht1(DHTPIN1, DHTTYPE1);

DHT dhtList[] = {dht0, dht1};

void init_DHT22(int id) {
    dhtList[id].begin();
}

String read_DHT22(int id) {
    float t = dhtList[id].readTemperature();
    float h = dhtList[id].readHumidity();

    while(isnan(t) || isnan(h)) {
        t = dhtList[id].readTemperature();
        h = dhtList[id].readHumidity();
    }

    return payloads[id] + "&temperature=" + String(t) + "&humidity=" + String(h);
}
