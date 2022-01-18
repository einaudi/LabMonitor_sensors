#ifndef REQUESTS_H
#define REQUESTS_H

#include <Arduino.h>

#define HW_TIMER_INTERVAL_MS          50L

#define TIMER_INTERVAL_3S             3000L
#define TIMER_INTERVAL_60S            60000L

void init_timer();
void init_wifi();

void on3s();
void on60s();

void send_data(String payload);

bool updateFlag();
void updateFlagToTrue();
void updateFlagToFalse();

void blink(int n);

#endif // REQUESTS_H