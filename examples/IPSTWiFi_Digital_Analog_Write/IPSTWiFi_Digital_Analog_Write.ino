#include <IPSTWiFi.h>

IPSTWiFi ipstw;

#define LED_PIN 5    // Digital output pin for LED
#define PWM_PIN 19   // PWM output pin for LED

void setup() {
    Serial.begin(115200);
    ipstw.begin(); // Initialize IPST-WiFi library
}

void loop() {
     // Turn LED ON
    ipstw.digitalWrite(LED_PIN, HIGH);
    delay(1000);

    // Turn LED OFF
    ipstw.digitalWrite(LED_PIN, LOW);
    delay(1000);

    // PWM Output: Fade In
    for (int i = 0; i <= 255; i += 5) {
        ipstw.analogWrite(PWM_PIN, i);
        delay(50);
    }

    // PWM Output: Fade Out
    for (int i = 255; i >= 0; i -= 5) {
        ipstw.analogWrite(PWM_PIN, i);
        delay(50);
    }
}
