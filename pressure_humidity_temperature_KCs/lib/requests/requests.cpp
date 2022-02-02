#include <Arduino.h>
#include "requests.h"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include "ESP8266TimerInterrupt.h"
#include "ESP8266_ISR_Timer.h"

//
// WIFI SECTION
//

const char* ssid = "Ultra_Cold";
const char* password = "cold-centre-1";

const String monitorURL = "http://172.17.32.108:7000/data?";

void init_wifi() {
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    blink(2);
}

void send_data(String payload) {
    HTTPClient http;

    String url = monitorURL + payload;

    http.begin(url.c_str());
    http.GET();

    http.end();
}

//
// TIMER SECTION
//

// Init ESP8266 timer 1
ESP8266Timer ITimer;

// Init ESP8266_ISR_Timer
ESP8266_ISR_Timer ISR_Timer;


void IRAM_ATTR TimerHandler()
{
  ISR_Timer.run();
}

// ISRs
void on3s() {
    // updateFlagToTrue();
    wdtFlagToTrue();
    // ESP.wdtFeed();
}

void on60s() {
    updateFlagToTrue();
}

void init_timer()
{ 
  // Interval in microsecs
  ITimer.attachInterruptInterval(HW_TIMER_INTERVAL_MS * 1000, TimerHandler);
  
  // Just to demonstrate, don't use too many ISR Timers if not absolutely necessary
  // You can use up to 16 timer for each ISR_Timer
  ISR_Timer.setInterval(TIMER_INTERVAL_3S, on3s);
  ISR_Timer.setInterval(TIMER_INTERVAL_60S, on60s);

  ESP.wdtDisable();
}

//
// Misc
//

bool flag = true;
bool wdtFlag = false;

void blink(int n) {
    pinMode(LED_BUILTIN, OUTPUT);
    for(int i=0; i<n; i++) {
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
    }
}

bool updateFlag() {
    return flag;
}

void updateFlagToTrue() {
    flag = true;
}

void updateFlagToFalse() {
    flag = false;
}

bool wdtFlagStatus() {
    return wdtFlag;
}

void wdtFlagToTrue() {
    wdtFlag = true;
}

void wdtFlagToFalse() {
    wdtFlag = false;
}
