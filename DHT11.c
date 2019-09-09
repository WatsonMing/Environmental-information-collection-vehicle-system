#include "STC15F2K60S2.h"
#include "delay.h"
//#include "DHT11.h"
sbit dht11_io=P2^7;   //P2.0口作为数据读取接口
unsigned int   DHT11_Flag;
unsigned char  temp;
unsigned char  T_data_H,T_data_L,H_data_H,H_data_L,comdata;
void read_byte()
{
	  unsigned char i;
	  for(i=0;i<8;i++)
		{
			DHT11_Flag=2;
			while((!dht11_io)&&DHT11_Flag++);//超时3毫秒跳出
			Delay30us();
			temp=0;
			if(dht11_io)temp=1;
			DHT11_Flag=2;
			while((dht11_io)&&DHT11_Flag++);//超时3毫秒跳出
			if(DHT11_Flag==1)break;
			comdata<<=1;
			comdata|=temp;
		}
}
void read_Humi_Temp()
{
	  unsigned char  T_data_H_Temp,T_data_L_Temp,H_data_H_Humi,H_data_L_Humi,checkdata;
	  DHT11_Flag=0;
		dht11_io = 1;
		dht11_io=0;
		Delay18ms();
		dht11_io=1;
		Delay40us();
		dht11_io=1;
		if(!dht11_io)
		{
				 DHT11_Flag=2;
				 while((!dht11_io)&&DHT11_Flag++);//超时3毫秒跳出
			   DHT11_Flag=2;
				 while((dht11_io)&&DHT11_Flag++);//超时3毫秒跳出
			
				 read_byte();
				 H_data_H_Humi=comdata;
				 read_byte();
				 H_data_L_Humi=comdata;
			
				 read_byte();
				 T_data_H_Temp=comdata;
				 read_byte();
				 T_data_L_Temp=comdata;
			
				 read_byte();
				 checkdata=comdata;
			
				 dht11_io=1;
				 temp=T_data_L_Temp+T_data_H_Temp+H_data_H_Humi+H_data_L_Humi;
				 if(temp==checkdata)
				 {
						H_data_H=H_data_H_Humi;
						H_data_L=H_data_L_Humi;
					 
						T_data_H=T_data_H_Temp;
						T_data_L=T_data_L_Temp;
					 
						checkdata=checkdata;
				 }
		}
}

unsigned char Humi_H(void)
{
	return H_data_H;
}
unsigned char Humi_L(void)
{
	return H_data_L;
}
unsigned char Temp_H(void)
{
	return T_data_H;
}
unsigned char Temp_L(void)
{
	return T_data_L;
}
