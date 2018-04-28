# TLC5947_Atmel_ASF4_Library
C library to control adafruit TLC5947 PWM/LED driver using atmel studio and asf4 for all Xplained pro boards
you need to import the library to your project , a full article about it in my blog 
https://mb-raw.blogspot.com/2018/04/adafruit-tlc5947-and-sam-d21-library.html

and here's the library reference , if you are familiar with adafruit's library so it will not be that difficult to you to understand it



void setTLC5947(uint16_t n,uint16_t clk,uint16_t data,uint16_t latch,uint16_t Blink);
set the pins that you want to use it to control TLC5947

 where:
 n: number of device you have .
clk: clock pin .
data : data input (din) pin .
latch: lat pin .
Blink: enable pin (OE).

bool tlc5947_begin(void);
start the tlc5947 

void tlc5947_setPWM(uint16_t chan, uint16_t pwm);
set the pwm value for a specific channel 
 
where
chan : number of channel (0-23)
pwm : pwm value (from 0 - 4095)


void tlc5947_setLED(uint16_t lednum, uint16_t r, uint16_t g, uint16_t b);

control an RGB led using this command , remember you need to have a common anode RGB led 

where 
lednum : the led number you want to control(0-7)
r : red color value(0-4095);
g : green color value(0-4095);
b : blue color value(0-4095);


void tlc5947_write(void);
update the values to TLC5947 , you need to call it everytime you want to change the LED /PWM output.


void tlc5947_enable(bool en);

enable / disable the device
en = true : enable the device output
en = false: disable the device output

hint: I recommended you to disable the device before update the values using (tlc5947_write)and then enable it , that's will eliminate any led flicker 

example : 

tlc5947_enable(false);
tlc5947_write();
tlc5947_enable(true);
