#ifndef SENSOR_DHT22_H
#define SENSOR_DHT22_H

#include <Arduino.h>
#include "DHT.h"

#define DHTPIN0 D3
#define DHTTYPE0 DHT22
#define DHTPIN1 D1
#define DHTTYPE1 DHT22

void init_DHT22(int id);

String read_DHT22(int id);

#endif // SENSOR_DHT22_H