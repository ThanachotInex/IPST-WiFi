#include <IPSTWiFi.h>   

IPSTWiFi ipstw;        // Create IPST-WiFi object
#define LED_PIN 18     // Digital output pin for LED

void setup() {
    Serial.begin(115200);  // Initialize serial communication
    ipstw.begin();          // Initialize IPST-WiFi board

    pinMode(LED_PIN, OUTPUT); // LED pin mode is set
}

void loop() {
    // Turn the LED on
    ipstw.digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
    delay(1000);  // Wait 1 second

    // Turn the LED off
    ipstw.digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
    delay(1000);  // Wait 1 second
}
