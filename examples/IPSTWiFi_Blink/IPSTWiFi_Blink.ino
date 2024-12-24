#include <IPSTWiFi.h>
IPSTWiFi w;

#define LED_PIN 18     // Digital Output

void setup() {
    Serial.begin(115200);
    w.begin(); // เริ่มต้นการทำงานของไลบรารี
}

void loop() {
    w.digitalWrite(LED_PIN, HIGH);
    delay(1000);
    w.digitalWrite(LED_PIN, LOW);
    delay(1000);
}