#include "STC15F2K60S2.h"
#include "MOTO.h"
#include "lcd.h"
#include "delay.h"
sbit ENA=P0^0;
sbit ENB=P0^1;
sbit ENC=P0^2;
sbit END=P0^3;

sbit ENL=P0^4;
sbit ENR=P0^5;

#define stop ENL=0;ENR=0;
#define start ENL=1;ENR=1;

#define Straight ENA=1;ENB=0;ENC=1;END=0;
#define Back ENA=0;ENB=1;ENC=0;END=1;
#define Left ENA=1;ENB=0;ENC=0;END=1;
#define Right ENA=0;ENB=1;ENC=1;END=0;

/******************************************************************/

void moto(unsigned char i)
{
	writeString(0,1,"Moving....");
	switch(i)
	{
		case 0x01:start;writeString(0,2,"<<-- Left ");Left; Delay1000ms(); stop; break;
		case 0x02:start;writeString(0,2,"Straight ^");Straight;Delay1000ms(); stop;break;
		case 0x03:start;writeString(0,2,"Right -->>");Right; Delay1000ms();stop; break;
		case 0x04:start;writeString(0,2,"---Back---");Back;  Delay1000ms();stop; break;
	}
}