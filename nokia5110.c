#include "lcd.h"
#include "font.h"
/*****************************************/
sbit CLK = P2^4;     //����ʱ��			//������д������
sbit DIN = P2^3;     //������������		//�ȸߺ��
sbit DC  = P2^2;     //����ָ����ƶ�	//�ߵ�ƽ���ݣ��͵�ƽָ��
sbit RST = P2^1;     //LCD��λ��		//�͵�ƽ��λ
sbit CS  = P2^0;     //Ƭѡʹ��			//�͵�ƽ��Ч
/**********************************************/
/*--------------------------------------------------------------*/
//д��һ���ֽ�(���ݻ�ָ��)
//wByte:	��д�������
//datOrCmd:	1-����, 0-ָ��
void writeByte(unsigned char wByte, unsigned char datOrCmd)
{
    unsigned char i;
    CS = 0;			//ʹ��
    DC = datOrCmd;	//1-����	//0-ָ��
    for(i = 8; i; i--)	//8λ����, �ȸߺ��
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
        wByte <<= 1;	//��λ(��ʱ)
        CLK = 1;	//������д��
    }
    CS = 1;			//��ֹ
}

void clear()//����
{
	  unsigned int i;
    writeCmd(0x80);
    writeCmd(0x40);
    for(i = 504; i; i--){
		writeDat(0x00);//������RAMд0
	}
}

//x: 0 - 83
//y: 0 - 5
void moveTo(unsigned char x, unsigned char y)//����д����λ��
{
    writeCmd(x|0x80);
    writeCmd(y|0x40);
}

//x:0~9
//y:0~2
void writeChar(unsigned char x, unsigned char y, unsigned char c) //дһ���ַ�
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
void writeString(unsigned char x, unsigned char y, unsigned char *str)//дһ���ַ���
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
	  RST = 1;//Ӳ����λ

    writeCmd(0x21);		//����ģʽ, ˮƽѰַ, ��չָ��
	  writeCmd(0x07);		//VLCD�¶�ϵ��,����0x04~0x07,ԽСԽ��
    writeCmd(0x13);		//����ƫ��ϵͳ(BSx) 1:48,����Ϊ0x10~0x17	
  	writeCmd(128+65); //���õ�ѹVLCD = 3.06 + 0.06*Vop, �Աȶȵ���,����Ϊ0x80~0xff;128+(0~127)

    writeCmd(0x20);		//����ģʽ, ˮƽѰַ, ����ָ��
    writeCmd(0x0c);		//��ͨģʽ
    writeCmd(0x80);	 	//��ʼҳ��ַ0
    writeCmd(0x40);		//��ʼ�е�ַ0
    clear();				  //��ȫ��
}

