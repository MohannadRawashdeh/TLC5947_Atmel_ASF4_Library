/*
 * Adafruit_TLC5947.h
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


#ifndef ADAFRUIT_TLC5947_H_
#define ADAFRUIT_TLC5947_H_
#include <string.h>
#include <stdlib.h>
#include "atmel_start.h"

bool Enable;
uint16_t numdrivers;
uint16_t *pwmbuffer;
uint16_t numdrivers;
uint16_t clkpin,datapin,latchpin,enablepin;


void setTLC5947(uint16_t n,uint16_t clk,uint16_t data,uint16_t latch,uint16_t Blink);

bool tlc5947_begin(void);
void tlc5947_setPWM(uint16_t chan, uint16_t pwm);
void tlc5947_setLED(uint16_t lednum, uint16_t r, uint16_t g, uint16_t b);
void tlc5947_write(void);
void tlc5947_enable(bool en);





#endif /* ADAFRUIT_TLC5947_H_ */