#include <IPSTWiFi.h>

IPSTWiFi ipstw; // Create IPST-WiFi object

void setup() {
    ipstw.begin();  // Initialize IPST-WiFi board
}

void loop() {
    ipstw.sled(0, 255, 0, 0);  // LED 0 -> Red
    delay(1000);     

    ipstw.sled(1, 0, 255, 0);  // LED 1 -> Green
    delay(1000); 

    ipstw.sled(2, 0, 0, 255);  // LED 2 -> Blue
    delay(1000);

    ipstw.sledFill(255, 255, 255); // All LEDs -> White
    delay(1000);    

    ipstw.sledClear();         // All LEDs -> Off
    delay(1000);    
}
