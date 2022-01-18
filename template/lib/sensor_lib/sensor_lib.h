#ifndef SENSOR_LIB_H
#define SENSOR_LIB_H

#include <Arduino.h>


// Functions below should have unique names so they're not redefined in another file
void init_sensor();

String read_sensor();

#endif // SENSOR_LIB_H