#include <Arduino.h>
#include "sensor_XGS600.h"

// Sensor db parameters
static String tab_name = "main";
static String localization = "KCs";
static String device = "XGS600";

const String payload_XGS600 = "tab_name=" + tab_name + "&localization=" + localization + "&device=" + device;

void init_XGS600() {
    Serial.begin(BAUDRATE);
    while(!Serial);

    delay(100);
    Serial.swap();
    delay(500);
}

String read_XGS600() {
    String pressure;

    Serial.println("#0002UIMG1");
    pressure = Serial.readStringUntil('\n');
    pressure = pressure.substring(1);

    return payload_XGS600 + "&pressure=" + pressure;    
}