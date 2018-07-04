#include <Wire.h>
#include <DS1302RTC.h>
#include <Time.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

DS1302RTC RTC(10,9,8);
#define DS1302_GND_PIN A0
#define DS1302_VCC_PIN A1

void setup(){
  
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);
  digitalWrite(DS1302_VCC_PIN, HIGH);
  pinMode(DS1302_VCC_PIN, OUTPUT);
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("jam digital");
  lcd.print("RTC activated");
  setSyncProvider(RTC.get);
  delay ( 500 );
  //setTime(10,12,00,7,10,2018);
  lcd.clear();
}

void loop(){
    tampil();
}
void tampil(){
  
  lcd.setCursor(0,1);
  lcd.print("Time : ");
  printdigits(hour());
  lcd.print(":");
  printdigits(minute());
  lcd.print(":");
  printdigits(second());
  delay(100);
  RTC.set(now());
}

void printdigits(int angka) {
  if (angka >= 0 && angka < 10) {
    lcd.write('0');
  }
  lcd.print(angka);
}
