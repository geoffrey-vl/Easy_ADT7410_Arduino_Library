/* 
 ADT7410 Temperature Sensor Library
 By: Geoffrey Van Landeghem
 Date: February 23nd, 2017
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 Get temperature from the ADT7410 sensor.
 
 */

#ifndef EasyADT7410_h
#define EasyADT7410_h

#define ADT7410_I2C_ADDRESS 0x48
#define TEMPREGISTER 0x00
#define CONFIGREGISTER 0x03
#define MODE16BITREGISTER 0x80

#include "Arduino.h"
#include <Wire.h>

class ADT7410
{
	public:
		ADT7410();
		void begin(void);
		float readTemperature(void);
		void set16bitMode(void);
};

#endif
