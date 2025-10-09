#include <IPSTWiFi.h>

IPSTWiFi ipstw;             // Create IPST-WiFi object
const int analogPin = 34;   // ADC pin to read analog input

void setup() {
    Serial.begin(115200);   // Initialize serial communication at 115200 baud
    ipstw.begin();          // Initialize IPST-WiFi board
    Serial.print("Reading from analog pin: ");
    Serial.println(analogPin);
}

void loop() {
    int analogValue = ipstw.analogRead(analogPin); // Read the analog value from the specified pin

    // Print the result to the Serial Monitor
    Serial.print("Analog Value : ");
    Serial.println(analogPin);
    Serial.println(analogValue);

    // Wait 500 ms before the next reading
    delay(500); 
}
