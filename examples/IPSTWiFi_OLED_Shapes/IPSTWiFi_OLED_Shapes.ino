#include <IPSTWiFi.h>
IPSTWiFi w;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  w.begin();
  w.drawLine(0,0,127,63, 1);
  w.drawRect(10, 10, 50, 30, 1);
  w.drawCircle(64, 32, 20, 1);
  w.drawTriangle(10, 50, 30, 10, 50, 50,1);
  w.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}
