#include <IPSTWiFi.h>

IPSTWiFi ipstw;
#define BUTTON_PIN 0  // Digital pin connected to the button

void setup() {
  Serial.begin(115200);
  ipstw.begin();  // Initialize IPST-WiFi library
}

void loop() {
  int buttonState = ipstw.digitalRead(BUTTON_PIN);  // Read the current button state

  if (buttonState == LOW) {
    Serial.println("Button is pressed!");
  } else {
    Serial.println("Button is not pressed.");
  }
  delay(500);  // Wait 0.5 second
}
