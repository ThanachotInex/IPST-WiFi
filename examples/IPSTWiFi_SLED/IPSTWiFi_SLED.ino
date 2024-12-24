#include <IPSTWiFi.h>

IPSTWiFi w;

void setup() {
    w.begin();
}

void loop() {
    w.sled(0, 255, 0, 0);  // Set the first LED (index 0) to red (RGB: 255, 0, 0)
    delay(1000);          
    w.sled(1, 0, 255, 0);  // Set the second LED (index 1) to green (RGB: 0, 255, 0)
    delay(1000);       
    w.sled(2, 0, 0, 255);  // Set the third LED (index 2) to blue (RGB: 0, 0, 255)
    delay(1000);            
    w.sledFill(255, 255, 255);  // Set all LEDs to white (RGB: 255, 255, 255)
    delay(1000);                // Wait for 1 second
    w.sledClear(); // Set all LEDs to black
    delay(1000);    
}