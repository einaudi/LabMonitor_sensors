#include <Arduino.h>
#include "sensor_lib.h"

// Sensor db parameters
static String tab_name = "tab_name";
static String localization = "localization";
static String device = "device_name";

const String payload_sensor = "tab_name=" + tab_name + "&localization=" + localization + "&device=" + device;

// Any specific class instances should be constructed here

void init_sensor() {
    // Initialization of the sensor
}

String read_DHT22() {
    // Data readout
    // This function should return string in url format which will be accepted by the database server

    return payload_sensor + data;
}
