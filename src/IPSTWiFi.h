// IPST-WiFi Arduino Library
// Version 1.0.0
// Header File

#ifndef IPSTWiFi_h
#define IPSTWiFi_h

#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "OLED_I2C_SSD1309.h"
#include "Adafruit_NeoPixel.h"


class IPSTWiFi {
public:
    // Constructor
    IPSTWiFi();

    // Initialize all components
    void begin();

    // LED control
    void setLED(int pin, bool state);
    void blinkLED(int pin, int duration);

    // Input & Button
    int SW1();
    int waitSW1();
    bool readButton(int pin);
    int digitalRead(int pin);
    int analogRead(uint8_t pin);

    // KNOB(Potentiometer)
    int KNOB();
    int KNOB(int scale);
    int KNOB(int scaleCCW,int scaleCW);

    //PIEZO
    void playTone(int frequency, int duration = 0);
    void stopTone();
    void beep();

    // Servo motor
    void attachServo(int pin);
    void setServoAngle(int angle);

    // Ultrasonic sensor
    float readSonar(int trigPin, int echoPin);

    // OUTPUT
    void digitalWrite(int pin, bool state);
    void analogWrite(int pin, int value);
    // RGB LED
    void sled(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void sled(uint16_t n, uint8_t r, uint8_t g, uint8_t b,uint8_t BRIGHTNESS);
    void sled(uint16_t n, const String& colorName);
    void sledFill(uint8_t r, uint8_t g, uint8_t b);
    void sledClear();
    void sledBrightness(uint8_t BRIGHTNESS);

    // OLED display
    void show();
    void clear();
    void textSize(int size);
    void text(int x, int y, char* c);
    void text(int x, int y, char* c,int s);

    void fillScreen(uint16_t color);
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,uint16_t color);
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color);
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color);
    void drawCircle(int16_t x, int16_t y, int16_t r, uint16_t color);
    void fillCircle(int16_t x, int16_t y, int16_t r, uint16_t color);
    void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2,int16_t y2, uint16_t color);
    void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2,int16_t y2, uint16_t color);

private:
    int _servoPin;
    OLED_I2C_SSD1309 _oled;
    Adafruit_NeoPixel _sled;
};

#endif