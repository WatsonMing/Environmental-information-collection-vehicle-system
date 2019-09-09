#ifndef LCD_H
#define LCD_H
#include "STC15F2K60S2.H"

/******************************************************************/
#define writeCmd(cmd)	writeByte(cmd, 0)	//写入指令
#define writeDat(dat)	writeByte(dat, 1)	//写入数据

#define showBlank()		writeCmd(0x08)		//显示空白
#define showNormal()	writeCmd(0x0c)		//正常显示
#define showBlack()		writeCmd(0x09)		//显示全黑
#define showReverse() writeCmd(0x0d)		//反色显示

extern void writeByte(unsigned char wByte, unsigned char datOrCmd);
extern void clear();//清屏
extern void moveTo(unsigned char x, unsigned char y);
extern void writeChar(unsigned char x, unsigned char y, unsigned char c);
extern void writeString(unsigned char x, unsigned char y, unsigned char *str);
extern void LCDInit(void);

#endif