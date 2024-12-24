#include <IPSTWiFi.h>
IPSTWiFi w;

#define LED_PIN 5     // Digital Output
#define PWM_PIN 19      // PWM Output

void setup() {
    Serial.begin(115200);
    w.begin(); // เริ่มต้นการทำงานของไลบรารี
}

void loop() {
    // Digital Output: เปิด LED (HIGH)
    w.digitalWrite(LED_PIN, HIGH);
    delay(1000);

    // Digital Output: ปิด LED (LOW)
    w.digitalWrite(LED_PIN, LOW);
    delay(1000);

    // PWM Output: เพิ่มค่าความสว่าง
    for (int i = 0; i <= 255; i += 5) {
        w.analogWrite(PWM_PIN, i);
        delay(50);
    }

    // PWM Output: ลดค่าความสว่าง
    for (int i = 255; i >= 0; i -= 5) {
        w.analogWrite(PWM_PIN, i);
        delay(50);
    }
}