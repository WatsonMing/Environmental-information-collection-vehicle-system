#include "lcd.h"
#include "font.h"
/*****************************************/
sbit CLK = P2^4;     //串行时钟			//上升沿写入数据
sbit DIN = P2^3;     //串行数据输入		//先高后低
sbit DC  = P2^2;     //数据指令控制端	//高电平数据，低电平指令
sbit RST = P2^1;     //LCD复位端		//低电平复位
sbit CS  = P2^0;     //片选使能			//低电平有效
/**********************************************/
/*--------------------------------------------------------------*/
//写入一个字节(数据或指令)
//wByte:	待写入的数据
//datOrCmd:	1-数据, 0-指令
void writeByte(unsigned char wByte, unsigned char datOrCmd)
{
    unsigned char i;
    CS = 0;			//使能
    DC = datOrCmd;	//1-数据	//0-指令
    for(i = 8; i; i--)	//8位数据, 先高后低
    {
        if(wByte & 0x80) 
				{
            DIN = 1;
        }
        else			 
				{
            DIN = 0;
        }
        CLK = 0;
        wByte <<= 1;	//移位(延时)
        CLK = 1;	//上升沿写入
    }
    CS = 1;			//禁止
}

void clear()//清屏
{
	  unsigned int i;
    writeCmd(0x80);
    writeCmd(0x40);
    for(i = 504; i; i--){
		writeDat(0x00);//将所有RAM写0
	}
}

//x: 0 - 83
//y: 0 - 5
void moveTo(unsigned char x, unsigned char y)//设置写数据位置
{
    writeCmd(x|0x80);
    writeCmd(y|0x40);
}

//x:0~9
//y:0~2
void writeChar(unsigned char x, unsigned char y, unsigned char c) //写一个字符
{
    unsigned char i, j;
    c -= 32;
    x <<= 3;		
    y <<= 1;		
    for(j = 0; j < 2; j++)
    {
        moveTo(x, (y + j));
        for(i = 0; i < 8; i++)
            writeDat(font[c][8 * j + i]);
    }
}

//x:0~9
//y:0~2
void writeString(unsigned char x, unsigned char y, unsigned char *str)//写一个字符串
{
    while(*str && x < 10)
    {
        writeChar(x++, y, *str);
        str++;
    }
}

void LCDInit(void)
{
    RST = 0; 
	  RST = 1;//硬件复位

    writeCmd(0x21);		//工作模式, 水平寻址, 扩展指令
	  writeCmd(0x07);		//VLCD温度系数,设置0x04~0x07,越小越黑
    writeCmd(0x13);		//设置偏置系统(BSx) 1:48,设置为0x10~0x17	
  	writeCmd(128+65); //设置电压VLCD = 3.06 + 0.06*Vop, 对比度调整,设置为0x80~0xff;128+(0~127)

    writeCmd(0x20);		//工作模式, 水平寻址, 常规指令
    writeCmd(0x0c);		//普通模式
    writeCmd(0x80);	 	//起始页地址0
    writeCmd(0x40);		//起始列地址0
    clear();				  //清全屏
}

