#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME "EV Battery Status"
#define BLYNK_AUTH_TOKEN ""

//#include <WiFi.h>
//#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "hello";
char pass[] = "123456789";

int value = 0;
float voltage, battery, q = 18;

void eee(){
    value = analogRead(A0);
    value = value-5;
    voltage = value * 0.034;
    battery = (voltage*100)/q;
    Blynk.virtualWrite(V0,voltage);
    Blynk.virtualWrite(V1,battery);
    Serial.print("Voltage = ");
    Serial.println(voltage);
    Serial.print("Value = ");
    Serial.println(value);
    Serial.print("Battery level = ");
    Serial.print(battery);
}

void setup(){
    Serial.begin(9200);
    Blynk.begin(auth, ssid, pass);
    timer.setInterval(100L,eee);
}

void loop(){
    Blynk.run();
    timer.run();
}