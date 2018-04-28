/*
 * Adafruit_TLC5947.c
 *
 * Created: 4/28/2018
  *  Author: Mohannad Rawashdeh - Jordan

  This is a library for our Adafruit 24-channel PWM/LED driver
  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/1429
  These drivers uses SPI to communicate, 3 pins are required to  
  interface: Data, Clock and Latch. The boards are chainable
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************
  I re-write the library to be controlled by Atmel Xplained pro boards 
  and atmel studio , I used atmel start to set the configuration for this library
  and tested using SAM D21 xplained pro board
  written by : Mohannad Rawashdeh
 */ 

#include <Adafruit_TLC5947.h>
#include "atmel_start.h"
#include <hal_gpio.h>
#include <string.h>
#include <stdlib.h>
void setTLC5947(uint16_t n,uint16_t clk,uint16_t data,uint16_t latch,uint16_t Blink) {
	numdrivers = n;
	clkpin=clk;
	datapin=data;
	latchpin=latch;
	enablepin=Blink;
	//pwmbuffer = (uint16_t *)calloc(2, 24*n);
	pwmbuffer = (uint16_t *)malloc(2 * 24*n);
	memset(pwmbuffer, 0, 2*24*n);
}

void tlc5947_write(void) {
	gpio_set_pin_level(tlc_lat,false);
	// 24 channels per TLC5974
	for (int16_t c=24*numdrivers - 1; c >= 0 ; c--) {
		// 12 bits per channel, send MSB first
		for (int8_t b=11; b>=0; b--) {
			gpio_set_pin_level(clkpin, false);
			
			if (pwmbuffer[c] & (1 << b))
			{
				gpio_set_pin_level(datapin, true);
			}
			else
			{
				gpio_set_pin_level(datapin, false);
			}
			

			gpio_set_pin_level(clkpin, true);
		}
	}
	gpio_set_pin_level(clkpin, false);
	gpio_set_pin_level(latchpin, true);
}



void tlc5947_setPWM(uint16_t chan, uint16_t pwm) {
	if (pwm > 4095) pwm = 4095;
	if (chan > 24*numdrivers) return;
	pwmbuffer[chan] = pwm;
}


void tlc5947_setLED(uint16_t lednum, uint16_t r, uint16_t g, uint16_t b) {
	tlc5947_setPWM(lednum*3, r);
	tlc5947_setPWM(lednum*3+1, g);
	tlc5947_setPWM(lednum*3+2, b);
}


bool tlc5947_begin() {
	if (!pwmbuffer) return false;

	gpio_set_pin_direction(clkpin,GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(datapin, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(latchpin, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(enablepin,GPIO_DIRECTION_OUT);
	gpio_set_pin_level(latchpin, false);
	gpio_set_pin_level(enablepin, false);
	return true;
}
void tlc5947_enable(bool en)
{
	gpio_set_pin_level(enablepin,!en);
}