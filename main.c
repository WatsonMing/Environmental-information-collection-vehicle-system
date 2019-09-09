#include "ultrasonic.h"
#include "Uart.h"
#include "MOTO.h"
#include "lcd.h"
#include "delay.h"
#include "DHT11.h"
/**********************************************************************************************************/
//sbit MOTO_WATER = P2^6;//µÍµçÆ½ÓÐÐ§
sbit GPS = P1^0;//µÍµçÆ½ÓÐÐ§
//int distance;
//bit Flag;
//int timer;
/**********************************
void ultrasonic(int length)
{
		if((distance>0)&&(distance<length))
		{
			 writeString(0,1,"Ultrasonic");
			 MOTO_WATER=0;
			 writeString(0,2,"Potting...");
			 Delay1000ms();
			 MOTO_WATER=1;
			 writeString(0,2,"Continue..");
			 distance=0;
		}
}**/
/******************************************************************************************************
void int0() interrupt 0 //¾àÀë»ñÈ¡
{
    distance = (TH0 * 256 + TL0)/58;
    TH0 = 0;  
    TL0 = 0;
}***** 
void time0() interrupt 1 //¾àÀëÒç³ö
{
   TH0 = 0xFE;  //é‡æ–°èµ‹åˆå€¼
   TL0 = 0x0C;
   timer++;    
   // distance = 0;
}
/************************/
unsigned char received_Buf=0;
/**************************************/
void isr_uart(void) interrupt 4
{
    if(RI)
    {
        RI = 0;
			  received_Buf=SBUF;
		}   
		else TI=0;
}
/**********************************************************************************************************/
void main()
{
		UartInit();
    RI=0;TI=0;//Flag=1;
    P0=0xFF;P1=0xFF;P2=0xFF;
		//distance=0;
    LCDInit();
		writeString(0,0,"CollectCar");
    writeString(0,1,"--Status--");
    writeString(0,2,"Reading...");
	  Delay2000ms();
		writeString(0,1,"Ultrasonic");
		writeString(0,2,"Operation-");
    //timer=0;
/***********************************************************************************/
    while(1)
		{
			  //ES=0;
			  //ultrasonic_Init();
				//ultrasonic(30);
			  //ES=1;
			  read_Humi_Temp();
				switch(received_Buf)
				{
						case 0x01:moto(0x01);received_Buf=0;break;
						case 0x02:moto(0x02);received_Buf=0;break;
						case 0x03:moto(0x03);received_Buf=0;break;
						case 0x04:moto(0x04);received_Buf=0;break;
						case 0x05:
							//read_Humi_Temp();
							writeString(0,2,"Data->Send");
							SBUF=Humi_H();
							while(!TI);
							SBUF=Humi_L();
							while(!TI);
							SBUF=Temp_H();
							while(!TI);
							SBUF=Temp_L();
							while(!TI);
							received_Buf=0;
						  writeString(0,2,"Continue..");
							break;
						case 0x06:GPS=0;writeString(0,1,"----GPS---");writeString(0,2,"----ON----");received_Buf=0;break;//GPS ON
						case 0x07:GPS=1;writeString(0,1,"----GPS---");writeString(0,2,"----OFF---");received_Buf=0;break;//GPS OFF
						default://Delay60ms();
						break;
				}
				writeString(0,1,"Operation-");
		    writeString(0,2,"Reading...");
		}
}