#include <IPSTWiFi.h>
IPSTWiFi w;

void setup() {
    Serial.begin(115200);
    w.begin(); // เริ่มต้นการทำงานของไลบรารี
}

void loop() {
    int analogValue = w.analogRead(34); // อ่านค่าจากพิน 33
    Serial.print("Analog Value (34): ");
    Serial.println(analogValue); // แสดงผลค่าที่อ่านได้
    delay(500); // หน่วงเวลา 500 มิลลิวินาที
}