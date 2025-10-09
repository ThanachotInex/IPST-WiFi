#include <IPSTWiFi.h>

IPSTWiFi ipstw;     // Create IPST-WiFi object

void setup() {
    Serial.begin(115200);  // Initialize serial communication
    ipstw.begin();           // Initialize IPST-WiFi board 

    ipstw.clear();
    ipstw.text(0,0,"size 1",1); //Show text size 1 
    ipstw.text(1,0,"size 2",2); //Show text size 2
    ipstw.show();   // Update the OLED display to show text 
    delay(2000);

    ipstw.clear();
    ipstw.drawLine(0, 0, 127, 63, 1);                // Draw a line from top-left to bottom-right
    ipstw.drawRect(10, 10, 50, 30, 1);               // Draw a rectangle at (10,10) width 50, height 30
    ipstw.drawCircle(64, 32, 20, 1);                 // Draw a circle centered at (64,32) with radius 20
    ipstw.drawTriangle(10, 50, 30, 10, 50, 50, 1);   // Draw a triangle with three vertices
    ipstw.show();  // Update the OLED display to show the drawings

    Serial.println("OLED graphics drawn successfully.");
}

void loop() {
    // Main loop is empty because graphics are static
}
