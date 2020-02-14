#include "Seeed_BMP280.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>
#include <SoftwareSerial.h>
BMP280 bmp280;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
SoftwareSerial UNO(1, 0);
int led = 6;

void setup(){
  
  
  pinMode(13, OUTPUT);

  Serial.begin(115200);
  UNO.begin(4800);
  if(!bmp280.init()){
    Serial.println("Device error!");
  }
  pinMode(led, OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Starting...");
  delay(1000);
}

void loop(){
  while(UNO.available()>0){
    float val = UNO.parseFloat();
    if(UNO.read() == '\n'){
      Serial.println(val);
    }
    delay(100);
  }
  
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  lcd.begin();
  lcd.setCursor(0, 0);

  float pressure;

  //get and print temperatures
  lcd.print(bmp280.getTemperature());
  lcd.print("C ");

  //get and print atmospheric pressure data
  lcd.print(pressure = bmp280.getPressure());
  lcd.println("Pa");

  lcd.setCursor(0, 1);
  
  //get and print altitude data
  lcd.print(bmp280.calcAltitude(pressure));
  lcd.print("m");

  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  
  int CDS = analogRead(A0);
  lcd.print(CDS);
  if (CDS > 50){
    digitalWrite(led, LOW);
    delay(1000); 
  }
  else {
    digitalWrite(led, HIGH);
    delay(1000); 
  }
}
