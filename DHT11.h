#ifndef __DHT11_H_
#define __DHT11_H_

extern unsigned char Temp_H(void);
extern unsigned char Temp_L(void);
extern unsigned char Humi_H(void);
extern unsigned char Humi_L(void);
extern void read_Humi_Temp(void);
#endif