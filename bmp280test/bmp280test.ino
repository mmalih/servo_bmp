#include <Adafruit_BMP280.h>

/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMEP280 Breakout 
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required 
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Servo.h> //on importe la bibliothèque Servo

#define BMP_SCK D5
#define BMP_MISO D6
#define BMP_MOSI D7 
#define BMP_CS D1

Adafruit_BMP280 bmp; // I2C
int pinServo=D8; // variable pour stocker le pin pour la commande
Servo leServo; // on définit un objet Servo nommé leServo
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
  leServo.attach(pinServo); // on relie l'objet au pin de commande
  Serial.println(F("BMP280 test"));
  
  if (!bmp.begin()) {  
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}

void loop() {
  char result = bmp.startMeasurment();
    int temperature = bmp.getTemperature()
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    if (temperature < 20) {
      leServo.write(1);
  delay(1000);
    
    } else {
      leServo.write(179);
    delay(1000);
    }
   /* Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    */
    Serial.println();
    delay(2000);
}
