#include "delay.h"
#include <INTRINS.H>
void Delay15us()		//@11.0592MHz
{
    _nop_();  _nop_();  _nop_();
    _nop_();  _nop_();  _nop_();
    _nop_();  _nop_();  _nop_();
    _nop_();  _nop_();  _nop_();
}
void Delay15ms(void)
{   
	unsigned char i, j, k;
	_nop_();
	_nop_();
	i = 1;
	j = 162;
	k = 89;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
/*****************??????************************/
void Delay1000ms(void)		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 26;
	j = 55;
	k = 171;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
/*****************?????************************/
void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 85;
	j = 12;
	k = 155;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void Delay60ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 3;
	j = 134;
	k = 115;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
/**************************************************/
void Delay30us() 
{
unsigned char i, j;


i = 1;
j = 162;
do
{
while (--j);
} while (--i);
}


void Delay40us() 
{
	unsigned char i;
	i = 108;
	while (--i);
}


void Delay18ms() 
{
	unsigned char i, j, k;

	i = 1;
	j = 194;
	k = 160;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}