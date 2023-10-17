/*
  DS1307 RTC (Real-Time-Clock) Example

  Uno       A4 (SDA), A5 (SCL)
  Mega      20 (SDA), 21 (SCL)
  Leonardo   2 (SDA),  3 (SCL)
*/

#include <Wire.h>
#include <DS1307.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2); // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case,it could be 0x3f in many cases

DS1307 rtc; // Initialize the RTC


void setup()
{
  //init Serial port
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  while (!Serial); //wait for serial port to connect - needed for Leonardo only

  //init RTC
  Serial.println("Init RTC...");
  rtc.begin();

  //only set the date+time one time
  rtc.set(0, 0, 8, 17, 04, 2021); //08:00:00 24.12.2014 //sec, min, hour, day, month, year

  //stop/pause RTC
  // rtc.stop();

  //start RTC
  rtc.start();
}


void loop()
{
  uint8_t sec, min, hour, day, month;
  uint16_t year;

  //get time from RTC
  rtc.get(&sec, &min, &hour, &day, &month, &year);

  //serial output
  Serial.print("nTime: ");
  Serial.print(hour, DEC);
  Serial.print(":");
  Serial.print(min, DEC);
  Serial.print(":");
  Serial.print(sec, DEC);
  Serial.print("nDate: ");
  Serial.print(day, DEC);
  Serial.print(".");
  Serial.print(month, DEC);
  Serial.print(".");
  Serial.print(year, DEC);
  // set cursor to first line
  lcd.setCursor(5, 0);
  lcd.backlight();
  lcd.print("Hello!");
  lcd.setCursor(1, 1);
  lcd.print("MICRODIGISOFT");
  //wait a second
  delay(10);

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Date:");
  lcd.print(day);
  lcd.print("/");
  lcd.print(month);
  lcd.print("/");
  lcd.print(year);
  lcd.setCursor(1, 1);
  lcd.print("Time:");
  lcd.print(hour);
  lcd.print(":");
  lcd.print(min);
  lcd.print(":");
  lcd.print(sec);
  delay(1000);
  lcd.clear();

}
