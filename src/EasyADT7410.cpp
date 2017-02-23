/* 
 ADT7410 Temperature Sensor Library
 By: Geoffrey Van Landeghem
 Date: February 23nd, 2017
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 Get temperature from the ADT7410 sensor.
 
 */

#include <Wire.h>
#include <EasyADT7410.h>

ADT7410::ADT7410()
{
}

void ADT7410::begin(void)
{
	Wire.begin();
}


float ADT7410::readTemperature(void)
{
	//set read register
	Wire.beginTransmission(ADT7410_I2C_ADDRESS);
	Wire.write(TEMPREGISTER);
	Wire.endTransmission();
	//receive data
	Wire.requestFrom(ADT7410_I2C_ADDRESS, 2);
	byte MSB = Wire.read();
	byte LSB = Wire.read();

	//check for positive or negative sign
	boolean sign;
	if(MSB>0xA0) {
		sign=0; //negative
	} else {
		sign=1; //positive
	}

	//concat MSB&LSB
	float tempValue = MSB * 256;
	tempValue+=LSB;

	//BIN to DEC
	if(!(sign)){
		tempValue-=65536;
	}
	tempValue/=128;

	return tempValue;
}

void ADT7410::set16bitMode(void)
{
	Wire.beginTransmission(ADT7410_I2C_ADDRESS);
	Wire.write(CONFIGREGISTER);
	Wire.write(MODE16BITREGISTER);
}

