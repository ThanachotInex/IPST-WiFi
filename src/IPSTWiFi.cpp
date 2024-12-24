#include "IPSTWiFi.h"
#define OLED_RESET -1
#define ALL 12
#define ON   1
#define OFF  0
#define _NUMSLEDs  3
#define _PINSLEDs  12
#define BUZZER_PIN          25
#define SOUND_PWM_CHANNEL   0
#define SOUND_RESOLUTION    8
#define SOUND_ON            (1<<(SOUND_RESOLUTION-1))
#define SOUND_OFF           0
IPSTWiFi::IPSTWiFi() : _oled(OLED_RESET), _sled(_NUMSLEDs,_PINSLEDs, NEO_GRB + NEO_KHZ800) {}

void IPSTWiFi::begin() {
    Wire.begin();
    // Initialize OLED display
    _oled.begin(SSD1309_SWITCHCAPVCC, 0x3C);
    _oled.textSize(1);
    _oled.clear();
    _oled.show();
    _sled.begin();
    _sled.setBrightness(10);
    _sled.setPixelColor(0,0,0,0);
    _sled.setPixelColor(1,0,0,0);
    _sled.setPixelColor(2,0,0,0);
    _sled.show();
}

int IPSTWiFi::SW1(){
    pinMode(0,INPUT_PULLUP);
    if (digitalRead(0)==0){
        return(1);
    }
    else{
        return(0);
    }
}

int IPSTWiFi::waitSW1(){
  while(1)
  {
    pinMode(0,INPUT_PULLUP);
    if (digitalRead(0)!=0)
	{ if ((millis()&0x0100)==0)
	  {
		pinMode(18,OUTPUT);
		digitalWrite(18,LOW);
		delay(5);
	  }
	  else
	  { digitalWrite(18,HIGH);}
	}
	else
	{ pinMode(18,OUTPUT); 
	  digitalWrite(18,LOW);
	  pinMode(0,INPUT_PULLUP);
	  break;
	}
  }
}

int IPSTWiFi::digitalRead(int pin){
    pinMode(pin, INPUT); 
    return ::digitalRead(pin);
}

int IPSTWiFi::analogRead(uint8_t pin){
	return ::analogRead(pin);
}

void IPSTWiFi::digitalWrite(int pin, bool state) {
    pinMode(pin, OUTPUT);        
    ::digitalWrite(pin, state);   
}


void IPSTWiFi::analogWrite(int pin, int value) {
    pinMode(pin, OUTPUT);       
    ::analogWrite(pin, value);     
}

void IPSTWiFi::setLED(int pin, bool state) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, state);
}

int IPSTWiFi::KNOB(){
    int __knobValue;
    __knobValue=analogRead(36);
    return(__knobValue);

}

int IPSTWiFi::KNOB(int scaleCCW,int scaleCW){
    {
    long value;
    value=KNOB();
    if (scaleCW>=scaleCCW)
    {
        value=value/(4095/((scaleCW+1)-scaleCCW));
        value+=scaleCCW;
        if (value>scaleCW){
        value=scaleCW;
        }
    }
    else
    {
        value=4095-value;
        value=value/(4095/((scaleCCW+1)-scaleCW));
        value+=scaleCW;
        if (value>scaleCCW)
        {
        value=scaleCCW;
        }
    }
    return(value);
    }
}

int IPSTWiFi::KNOB(int scale){
    long value;
    value=KNOB();
    value=((value*(scale))/4095);
    if (value>scale)
    {
        value=scale;
    }
    return(value);
}

void IPSTWiFi::playTone(int frequency, int duration) {
    if (duration > 0) {
        tone(BUZZER_PIN, frequency, duration);
    } else {
        tone(BUZZER_PIN, frequency);
    }
}

void IPSTWiFi::stopTone() {
    noTone(BUZZER_PIN);
}

void IPSTWiFi::beep(void)
{	
	playTone(500,100);
}


void IPSTWiFi::sled(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
      _sled.setPixelColor(n,r,g,b);
      _sled.show();
}
void IPSTWiFi::sledFill(uint8_t r, uint8_t g, uint8_t b) {
	 for(int i=0;i<3;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
     _sled.setPixelColor(i,r,g,b);
     _sled.show();
     delay(1); // Delay for a period of time (in milliseconds).
  }    
}

void IPSTWiFi::sled(uint16_t n, uint8_t r, uint8_t g, uint8_t b,uint8_t BRIGHTNESS) {
	  _sled.setBrightness(BRIGHTNESS);
      _sled.setPixelColor(n,r,g,b);
      _sled.show();
}

void IPSTWiFi::sled(uint16_t n, const  String& colorName) {
    uint32_t color = 0; 
    if(colorName =="red"){
        color = _sled.Color(255, 0, 0);
    }
    else if(colorName =="green"){
        color = _sled.Color(0, 255, 0);
    }
    else if(colorName =="blue"){
        color = _sled.Color(0, 0, 255);
    } else if (colorName == "yellow") {
        color = _sled.Color(255, 255, 0);
    } else if (colorName == "cyan") {
        color = _sled.Color(0, 255, 255);
    } else if (colorName == "magenta") {
        color = _sled.Color(255, 0, 255);
    } else if (colorName == "white") {
        color = _sled.Color(255, 255, 255);
    } else if (colorName == "orange") {
        color = _sled.Color(255, 165, 0);
    } else if (colorName == "purple") {
        color = _sled.Color(128, 0, 128);
    } else if (colorName == "pink") {
        color = _sled.Color(255, 192, 203);
    } else if (colorName == "black") {
        color = _sled.Color(0, 0, 0);
    }
    _sled.setPixelColor(n,color);
      _sled.show();
}


void IPSTWiFi::sledBrightness(uint8_t BRIGHTNESS){
	  _sled.setBrightness(BRIGHTNESS);
}

void IPSTWiFi::sledClear() {
	 for(int i=0;i<3;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
     _sled.setPixelColor(i,0,0,0);
     _sled.show();
     delay(1); // Delay for a period of time (in milliseconds).
  }    
}

// OLED Display
void IPSTWiFi::textSize(int size){
    _oled.textSize(size);
}

void IPSTWiFi::text(int x, int y, char* c){
    _oled.text(x,y,c);
}

void IPSTWiFi::text(int x, int y, char* c,int size){
    _oled.textSize(size);
    _oled.text(x,y,c);
}

void IPSTWiFi::show(){
    _oled.show();
}

void IPSTWiFi::clear(){
    _oled.clear();
}

void IPSTWiFi::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
	_oled.drawLine(x0, y0, x1, y1, color);
}

void IPSTWiFi::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color){
	_oled.drawRect(x, y, w, h, color);
}
void IPSTWiFi::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color){
	_oled.fillRect(x, y, w, h, color);
}

void IPSTWiFi::drawCircle(int16_t x, int16_t y, int16_t r, uint16_t color) {
    _oled.drawCircle(x, y, r, color);
}
void IPSTWiFi::fillCircle(int16_t x, int16_t y, int16_t r, uint16_t color) {
    _oled.fillCircle(x, y, r, color);
}
void IPSTWiFi::drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2,int16_t y2, uint16_t color) {
    _oled.drawTriangle(x0, y0, x1, y1, x2, y2, color);
}
void IPSTWiFi::fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2,int16_t y2, uint16_t color) {
    _oled.fillTriangle(x0, y0, x1, y1, x2, y2, color);
}
void IPSTWiFi::fillScreen(uint16_t color){
    _oled.fillScreen(color);
}
// void IPSTWiFi::displayText(const char* text, int x, int y) {
//     _oled.clearDisplay();
//     _oled.setTextSize(1);
//     _oled.setTextColor(SSD1306_WHITE);
//     _oled.setCursor(x, y);
//     _oled.println(text);
//     _oled.display();
// }


// #include "Wire.h"
// #include "Arduino.h"
// #include "Adafruit_GFX.h"
// #include "OLED_I2C_SSD1309.h"
// #include "Adafruit_NeoPixel.h"
// #include "ESP32_Servo.h"
// #define OLED_RESET -1
// #define ALL 12
// #define ON   1
// #define OFF  0

// #define BUZZER_PIN          25
// #define SOUND_PWM_CHANNEL   0
// #define SOUND_RESOLUTION    8
// #define SOUND_ON            (1<<(SOUND_RESOLUTION-1))
// #define SOUND_OFF           0

// #define LED  18

// OLED_I2C_SSD1309 oled(OLED_RESET);
// Servo servo1;
 
// #define _NUMSLEDs  3
// #define _PINSLEDs  12
// Adafruit_NeoPixel sleds = Adafruit_NeoPixel(_NUMSLEDs,_PINSLEDs, NEO_GRB + NEO_KHZ800);

// // init libraries ipst-wifi
// void init(void){
// 	// Wire.begin();
	
// 	oled.begin(SSD1309_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
//     
// 	sleds.begin(); 
// 	sleds.setBrightness(10);
// 	sleds.setPixelColor(0,0,0,0);
// 	sleds.setPixelColor(1,0,0,0);
// 	sleds.setPixelColor(2,0,0,0);
//     sleds.show();
// }

// int in(uint8_t ch){
// 	pinMode(ch,INPUT_PULLUP);
// 	return digitalRead(ch);
// }

// void out(int8_t ch, bool state){
// 	  pinMode(ch,OUTPUT);
// 	  digitalWrite(ch,state);
// }


