#ifndef SENSOR_XGS600_H
#define SENSOR_XGS600_H

#include <Arduino.h>

#define BAUDRATE 9600

void init_XGS600();

String read_XGS600();

#endif // SENSOR_XGS600_H