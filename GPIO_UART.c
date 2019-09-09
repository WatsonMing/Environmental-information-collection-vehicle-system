#include "STC15F2K60S2.h"
#include "Uart.h"/*
void PwmInit(void)
{
	TH0=0xFE;		 
  TL0=0x0c; 
	ET0 = 1;
  TR0=0;
}*/

void UartInit(void)		//115200bps@11.0592MHz
{
		SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	TL1 = 0xE8;		//设定定时初值
	TH1 = 0xFF;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	ES = 1;
	EA = 1;
}
