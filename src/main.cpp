#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>
#include <TinyGPS++.h>
#include <String.h>
#
TinyGPSPlus gps;

void setup()
{

    Serial.begin(115200);
    Serial1.begin(9600);

    Wire.begin();
    oled.init(); // Initialze SSD1306 OLED display
    oled.clearDisplay();
    oled.setTextXY(0, 0);
}

void loop()
{
    
    while (Serial1.available())
    {
        gps.encode(Serial1.read());
    }

    Serial.print(String(gps.location.lat(), 5));
    Serial.print(",");
    Serial.println(String(gps.location.lng(),5));
    
    oled.setTextXY(0, 0);
    oled.putString(String(gps.location.lat(),5));
    oled.putString(",");
    oled.putString(String(gps.location.lng(),5));

    oled.setTextXY(2, 0);
    oled.putString(String(gps.date.day()));
    oled.putString(".");
    oled.putString(String(gps.date.month()));
    oled.putString(".");
    oled.putString(String(gps.date.year()));

    oled.setTextXY(4, 0);
    oled.putString(String(gps.time.hour()+2));
    oled.putString(":");
    oled.putString(String(gps.time.minute()));
    oled.putString(":");
    oled.putString(String(gps.time.second()));

    oled.setTextXY(6, 0);
    oled.putNumber(gps.satellites.value());
    
    /* while (Serial1.available())
    {
        Serial.write((Serial1.read()));
        oled.setTextXY(0, 0);

    } */
    //oled.putChar(C);

    //delay(10000);
}
