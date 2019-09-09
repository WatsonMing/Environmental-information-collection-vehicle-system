#ifndef LCD_H
#define LCD_H
#include "STC15F2K60S2.H"

/******************************************************************/
#define writeCmd(cmd)	writeByte(cmd, 0)	//д��ָ��
#define writeDat(dat)	writeByte(dat, 1)	//д������

#define showBlank()		writeCmd(0x08)		//��ʾ�հ�
#define showNormal()	writeCmd(0x0c)		//������ʾ
#define showBlack()		writeCmd(0x09)		//��ʾȫ��
#define showReverse() writeCmd(0x0d)		//��ɫ��ʾ

extern void writeByte(unsigned char wByte, unsigned char datOrCmd);
extern void clear();//����
extern void moveTo(unsigned char x, unsigned char y);
extern void writeChar(unsigned char x, unsigned char y, unsigned char c);
extern void writeString(unsigned char x, unsigned char y, unsigned char *str);
extern void LCDInit(void);

#endif