#ifndef SENSOR_DHT22_H
#define SENSOR_DHT22_H

#include <Arduino.h>
#include "DHT.h"

#define DHTPIN D5
#define DHTTYPE DHT22

void init_DHT22();

String read_DHT22();

#endif // SENSOR_DHT22_H