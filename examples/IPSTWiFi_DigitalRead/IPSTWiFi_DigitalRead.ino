#include <IPSTWiFi.h>
IPSTWiFi w;

void setup() {
    Serial.begin(115200);
    w.begin(); // เริ่มต้นการทำงานของไลบรารี
}

void loop() {
    int buttonState = w.digitalRead(5); // อ่านค่าจากพินดิจิทัล 5
    if (buttonState == LOW) {
        Serial.println("Button is pressed!");
    } else {
        Serial.println("Button is not pressed.");
    }
    delay(500); // หน่วงเวลา 500 มิลลิวินาที
}