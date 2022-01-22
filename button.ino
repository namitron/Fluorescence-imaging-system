// PROYEK SRILANKA 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define power 10
#define power_uv 12

long i = 0;
int led_power = 4;
int led_power_uv = 7;

int sensor = A3;
int potensio = 0;
int potensio2 = 0;
int potensio3 = 0;
int power_lcd = 8;
int HPL = 9;

int kondisi_pw = 0;
int kondisi_p_uv = 0;




void setup() {

  Serial.begin(9600);     
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); 
  display.display();
  
  pinMode(led_power, OUTPUT);
  pinMode(led_power_uv, OUTPUT);
  pinMode(power_lcd, OUTPUT);
  pinMode(HPL, OUTPUT);
  pinMode(power,INPUT_PULLUP);
  pinMode(power_uv,INPUT_PULLUP);

  digitalWrite(led_power, LOW);
  digitalWrite(led_power_uv, LOW);
  digitalWrite(HPL, LOW);


}

void loop() {
  potensio = analogRead(sensor);
  int v = potensio;
  int nilai =map(v,600, 700,0,100);

  if (v< 600){
    nilai = 0;
  }  
  Serial.print("potensio=              ");
  Serial.println(potensio);
  Serial.print("potensio2= ");
  Serial.println(potensio2);
  Serial.print("potensio3=     ");
  Serial.println(potensio3);
  

  potensio3 = potensio+5;

  if(digitalRead(power) == LOW && kondisi_pw == 0){
      delay(200);
      digitalWrite(led_power, HIGH);
      digitalWrite(power_lcd, HIGH);
      kondisi_pw = 1;
     
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(5,9);
      display.print("Loading.");
      display.display(); 
      delay(500);
      display.setCursor(5,9);
      display.print("Loading..");
      display.display();
      delay(500);
      display.setCursor(5,9);
      display.print("Loading...");
      display.display(); 
      delay(500);
      display.setCursor(5,9);
      display.print("Loading....");
      display.display(); 
      display.clearDisplay();
      delay(500);
      display.setCursor(5,9);
      display.print("Loading.....");
      display.display(); 
      display.clearDisplay();

      display.setCursor(5,9);
      display.print("Fluoresens Imaging");
      display.display(); 
      display.setCursor(7,17);
      display.print("System");
      display.display(); 
      display.clearDisplay();


  }

 
  if (digitalRead(power_uv) == LOW && kondisi_p_uv == 0 && kondisi_pw ==1){
         delay(200);
          digitalWrite(led_power_uv, HIGH);
          digitalWrite(HPL, HIGH);
          display.clearDisplay();
          display.setCursor(5,9);
          display.print("UV_ON");
          display.display(); 
          kondisi_p_uv = 1;
          

      
  }
   
  if (digitalRead(power_uv) == LOW && kondisi_p_uv == 1&& kondisi_pw ==1){
         delay(200);
         digitalWrite(led_power_uv, LOW);
         digitalWrite(HPL, LOW);
         display.clearDisplay();
         display.setCursor(5,9);
         display.print("UV_OFF");
         display.display(); 
         kondisi_p_uv = 0; 
      }




  if(digitalRead(power) == LOW && kondisi_pw == 1){
      delay(200);
      digitalWrite(led_power, LOW);
      digitalWrite(power_lcd, LOW);
      digitalWrite(led_power_uv, LOW);
      digitalWrite(HPL, LOW);
      kondisi_pw = 0;
      display.clearDisplay(); 
      display.display();
      
  }
  

if (potensio2 >= potensio && kondisi_p_uv == 1 ){
      display.clearDisplay();
      display.setCursor(10,9);
      display.print("UV_ON");
      display.setCursor(30,9);
      display.print(potensio);
      display.display(); 
    
}
if (potensio3 >= potensio && kondisi_p_uv == 1){
      display.clearDisplay();
      display.setCursor(10,9);
      display.print("UV_ON");
      display.setCursor(40,9);
      display.print(nilai);
      display.display(); 
}
  
}
