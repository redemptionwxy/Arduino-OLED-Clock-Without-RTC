/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


int hour = 20;
int minute = 22;
int second = 10;

unsigned long current_time = 0;
unsigned long previous_time = 0;
unsigned long interval = 1000;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);

  
}

void loop() {
    display.setTextSize(1);
    display.setCursor(30,20);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.print("Hello World!");
    
    
    display.setTextSize(2);
    display.setCursor(20,40);
    display.setTextColor(WHITE);
    
    if (hour > 9){
      display.print(hour);
      }
    if (hour < 10){
      display.print("0");
      display.print(hour);
      }
    display.print(":");
    if (minute > 9){
      display.print(minute);
      }
    if (minute < 10){
      display.print("0");
      display.print(minute);
      }
    display.print(":");
    if (second > 9){
      display.print(second);
      }
    if (second < 10){
      display.print("0");
      display.print(second);
      }
    display.display();
  
  current_time = millis();
  if (current_time - previous_time >= interval){
    second += 1;
    if (second == 60){
      minute += 1;
      second = 0;
      if (minute == 60){
        hour += 1;
        minute = 0;
        if (hour == 24){
          hour = 0;
        }
      }
    }
    previous_time = current_time;
  }
  
}
