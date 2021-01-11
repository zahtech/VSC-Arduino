#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
#include <LiquidCrystal.h>

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup()
{
    dht.begin();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    // Odczyt temperatury i wilgotności powietrza
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (isnan(t) || isnan(h))
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("error");
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
        delay(100);
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
        delay(100);
    }
    else
    {
        digitalWrite(13, HIGH);
        lcd.begin(16, 2);
        lcd.print("Wilgoc:");
        lcd.print(h);
        lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Temp:");
        lcd.print(t);
        lcd.print("*C");
        digitalWrite(13, LOW);
        digitalWrite(13, HIGH);
        int sensorValue = analogRead(A5);
        float swiatlo = sensorValue * (100.0 / 1023.0);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("swiatlo: ");
        lcd.print(swiatlo);
        lcd.print("%");
        digitalWrite(13, LOW);
        delay(2000);
        digitalWrite(13, HIGH);
    }
}