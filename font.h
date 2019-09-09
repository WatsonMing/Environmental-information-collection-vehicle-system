#ifndef FONT_H
#define FONT_H

/*--------------------------------------------------------------*/
//	  字体:	Fixedsys
//取码规则:	低位在前, 列行扫描, 阴码(1-亮, 0-灭)
//查表方法: 要显示的ASCII码-32就可以得到字库码的指针
unsigned char code font[][16] = {
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},// 0
{0x00,0x00,0x70,0xF8,0xF8,0x70,0x00,0x00,0x00,0x00,0x00,0x0D,0x0D,0x00,0x00,0x00},//!1
{0x00,0x38,0x38,0x00,0x00,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//"2
{0x00,0x20,0xF8,0xF8,0x20,0xF8,0xF8,0x20,0x00,0x02,0x0F,0x0F,0x02,0x0F,0x0F,0x02},//#3
{0x00,0x30,0x78,0xCE,0x8E,0x18,0x10,0x00,0x00,0x04,0x0C,0x38,0x39,0x0F,0x06,0x00},//$4
{0x18,0x3C,0x24,0xBC,0xD8,0x60,0x30,0x00,0x00,0x06,0x03,0x0D,0x1E,0x12,0x1E,0x0C},//%5
{0x00,0xB0,0xF8,0x48,0x78,0x30,0x00,0x00,0x00,0x07,0x0F,0x08,0x09,0x07,0x0F,0x09},//&6
{0x00,0x00,0x00,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//'7
{0x00,0x00,0xC0,0xF0,0x38,0x08,0x00,0x00,0x00,0x00,0x07,0x1F,0x38,0x20,0x00,0x00},//(8
{0x00,0x00,0x08,0x38,0xF0,0xC0,0x00,0x00,0x00,0x00,0x20,0x38,0x1F,0x07,0x00,0x00},//)9
{0x00,0x80,0xA0,0xE0,0xC0,0xE0,0xA0,0x80,0x00,0x00,0x02,0x03,0x01,0x03,0x02,0x00},//*10
{0x00,0x80,0x80,0xE0,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00},//+11
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2C,0x3C,0x1C,0x00,0x00},//,12
{0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//-13
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x0C,0x00,0x00},//.14
{0x00,0x00,0x00,0x80,0xE0,0x78,0x18,0x00,0x00,0x18,0x1E,0x07,0x01,0x00,0x00,0x00},///15
{0x00,0x00,0xF0,0xF8,0x08,0x68,0xF8,0xF0,0x00,0x00,0x07,0x0F,0x0B,0x08,0x0F,0x07},//016
{0x00,0x20,0x20,0x30,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00},//117
{0x00,0x30,0x38,0x08,0x88,0xF8,0x70,0x00,0x00,0x0C,0x0E,0x0B,0x09,0x08,0x08,0x00},//218
{0x00,0x30,0x38,0x88,0x88,0xF8,0x70,0x00,0x00,0x06,0x0E,0x08,0x08,0x0F,0x07,0x00},//319
{0x00,0x00,0xF8,0xF8,0x00,0xE0,0xE0,0x00,0x00,0x03,0x03,0x02,0x02,0x0F,0x0F,0x02},//420
{0x00,0xF8,0xF8,0x88,0x88,0x88,0x08,0x00,0x00,0x08,0x08,0x08,0x0C,0x07,0x03,0x00},//521
{0x00,0xC0,0xE0,0x78,0x58,0xC8,0x80,0x00,0x00,0x07,0x0F,0x08,0x08,0x0F,0x07,0x00},//622
{0x00,0x08,0x08,0x88,0xE8,0x78,0x18,0x00,0x00,0x00,0x0E,0x0F,0x01,0x00,0x00,0x00},//723
{0x00,0x70,0xF8,0xC8,0x88,0xF8,0x70,0x00,0x00,0x07,0x0F,0x08,0x09,0x0F,0x07,0x00},//824
{0x00,0xF0,0xF8,0x08,0x08,0xF8,0xF0,0x00,0x00,0x00,0x09,0x0D,0x0F,0x03,0x01,0x00},//925
{0x00,0x00,0x00,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x0C,0x00,0x00},//:26
{0x00,0x00,0x00,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x2C,0x3C,0x1C,0x00,0x00},//;27
{0x00,0x80,0xC0,0x60,0x30,0x18,0x08,0x00,0x00,0x00,0x01,0x03,0x06,0x0C,0x08,0x00},//<28
{0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},//=29
{0x00,0x08,0x18,0x30,0x60,0xC0,0x80,0x00,0x00,0x08,0x0C,0x06,0x03,0x01,0x00,0x00},//>30
{0x00,0x30,0x38,0x88,0xC8,0x78,0x30,0x00,0x00,0x00,0x00,0x0D,0x0D,0x00,0x00,0x00},//?31
{0xF0,0xF8,0x08,0x88,0xC8,0x48,0xF8,0xF0,0x07,0x0F,0x08,0x09,0x0B,0x0A,0x0B,0x0B},//@32
{0x00,0xE0,0xF0,0x18,0x18,0xF0,0xE0,0x00,0x00,0x0F,0x0F,0x01,0x01,0x0F,0x0F,0x00},//A33
{0x00,0xF8,0xF8,0x88,0x88,0xF8,0x70,0x00,0x00,0x0F,0x0F,0x08,0x08,0x0F,0x07,0x00},//B34
{0x00,0xF0,0xF8,0x08,0x08,0x38,0x30,0x00,0x00,0x07,0x0F,0x08,0x08,0x0E,0x06,0x00},//C35
{0x00,0xF8,0xF8,0x08,0x18,0xF0,0xE0,0x00,0x00,0x0F,0x0F,0x08,0x0C,0x07,0x03,0x00},//D36
{0x00,0xF8,0xF8,0x88,0x88,0x88,0x08,0x00,0x00,0x0F,0x0F,0x08,0x08,0x08,0x08,0x00},//E37
{0x00,0xF8,0xF8,0x88,0x88,0x88,0x08,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00},//F38
{0x00,0xF0,0xF8,0x08,0x08,0x38,0x30,0x00,0x00,0x07,0x0F,0x08,0x09,0x0F,0x0F,0x00},//G39
{0x00,0xF8,0xF8,0x80,0x80,0xF8,0xF8,0x00,0x00,0x0F,0x0F,0x00,0x00,0x0F,0x0F,0x00},//H40
{0x00,0x00,0x08,0xF8,0xF8,0x08,0x00,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00},//I41
{0x00,0x00,0x00,0x00,0x00,0xF8,0xF8,0x00,0x00,0x06,0x0E,0x08,0x08,0x0F,0x07,0x00},//J42
{0x00,0xF8,0xF8,0x80,0xE0,0x78,0x18,0x00,0x00,0x0F,0x0F,0x00,0x03,0x0F,0x0C,0x00},//K43
{0x00,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x08,0x08,0x08,0x08,0x00},//L44
{0x00,0xF8,0xF8,0x20,0xC0,0x20,0xF8,0xF8,0x00,0x0F,0x0F,0x00,0x01,0x00,0x0F,0x0F},//M45
{0x00,0xF8,0xF8,0x60,0xC0,0x80,0xF8,0xF8,0x00,0x0F,0x0F,0x00,0x00,0x01,0x0F,0x0F},//N46
{0x00,0xF0,0xF8,0x08,0x08,0xF8,0xF0,0x00,0x00,0x07,0x0F,0x08,0x08,0x0F,0x07,0x00},//O47
{0x00,0xF8,0xF8,0x88,0x88,0xF8,0x70,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00},//P48
{0x00,0xF0,0xF8,0x08,0x08,0xF8,0xF0,0x00,0x00,0x07,0x0F,0x08,0x18,0x3F,0x27,0x00},//Q49
{0x00,0xF8,0xF8,0x88,0x88,0xF8,0x70,0x00,0x00,0x0F,0x0F,0x00,0x01,0x0F,0x0E,0x00},//R50
{0x00,0x30,0x78,0xC8,0x88,0x18,0x10,0x00,0x00,0x04,0x0C,0x08,0x09,0x0F,0x06,0x00},//S51
{0x00,0x08,0x08,0xF8,0xF8,0x08,0x08,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00},//T52
{0x00,0xF8,0xF8,0x00,0x00,0xF8,0xF8,0x00,0x00,0x07,0x0F,0x08,0x08,0x0F,0x07,0x00},//U53
{0x00,0xF8,0xF8,0x00,0x00,0xF8,0xF8,0x00,0x00,0x03,0x07,0x0C,0x0C,0x07,0x03,0x00},//V54
{0x00,0xF8,0xF8,0x00,0xC0,0x00,0xF8,0xF8,0x00,0x01,0x0F,0x0E,0x01,0x0E,0x0F,0x01},//W55
{0x00,0x18,0x38,0xE0,0xC0,0x38,0x18,0x00,0x00,0x0E,0x0F,0x00,0x01,0x0F,0x0E,0x00},//X56
{0x00,0x78,0xF8,0x80,0x80,0xF8,0x78,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00},//Y57
{0x00,0x08,0x08,0x88,0xC8,0x78,0x38,0x00,0x00,0x0E,0x0F,0x09,0x08,0x08,0x08,0x00},//Z58
{0x00,0x00,0xF8,0xF8,0x08,0x08,0x00,0x00,0x00,0x00,0x7F,0x7F,0x40,0x40,0x00,0x00},//[59
{0x00,0x18,0x78,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x1E,0x18,0x00},//\60
{0x00,0x00,0x08,0x08,0xF8,0xF8,0x00,0x00,0x00,0x00,0x40,0x40,0x7F,0x7F,0x00,0x00},//]61
{0x00,0x08,0x0C,0x06,0x06,0x0C,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//^62
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40},//_63
{0x00,0x00,0x02,0x06,0x0E,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//`64
{0x00,0x00,0x20,0x20,0x20,0xE0,0xC0,0x00,0x00,0x06,0x0F,0x09,0x09,0x0F,0x0F,0x00},//a65
{0x00,0xF8,0xF8,0x20,0x20,0xE0,0xC0,0x00,0x00,0x0F,0x0F,0x08,0x08,0x0F,0x07,0x00},//b66
{0x00,0xC0,0xE0,0x20,0x20,0x60,0x40,0x00,0x00,0x07,0x0F,0x08,0x08,0x0C,0x04,0x00},//c67
{0x00,0xC0,0xE0,0x20,0x20,0xF8,0xF8,0x00,0x00,0x07,0x0F,0x08,0x08,0x0F,0x0F,0x00},//d68
{0x00,0xC0,0xE0,0x20,0x20,0xE0,0xC0,0x00,0x00,0x07,0x0F,0x09,0x09,0x09,0x01,0x00},//e69
{0x00,0x80,0xF0,0xF8,0x88,0x88,0x88,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00},//f70
{0x00,0xC0,0xE0,0x20,0x20,0xE0,0xE0,0x00,0x00,0x47,0x4F,0x48,0x48,0x7F,0x3F,0x00},//g71
{0x00,0xF8,0xF8,0x20,0x20,0xE0,0xC0,0x00,0x00,0x0F,0x0F,0x00,0x00,0x0F,0x0F,0x00},//h72
{0x00,0x20,0x20,0xEC,0xEC,0x00,0x00,0x00,0x00,0x08,0x08,0x0F,0x0F,0x08,0x08,0x00},//i73
{0x00,0x00,0x20,0x20,0xEC,0xEC,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x3F,0x00,0x00},//j74
{0x00,0xF8,0xF8,0x00,0x80,0xE0,0x60,0x00,0x00,0x0F,0x0F,0x01,0x03,0x0E,0x0C,0x00},//k75
{0x00,0x08,0x08,0xF8,0xF8,0x00,0x00,0x00,0x00,0x08,0x08,0x0F,0x0F,0x08,0x08,0x00},//l76
{0x00,0xE0,0xE0,0x20,0xE0,0x20,0xE0,0xC0,0x00,0x0F,0x0F,0x00,0x07,0x00,0x0F,0x0F},//m77
{0x00,0xE0,0xE0,0x20,0x20,0xE0,0xC0,0x00,0x00,0x0F,0x0F,0x00,0x00,0x0F,0x0F,0x00},//n78
{0x00,0xC0,0xE0,0x20,0x20,0xE0,0xC0,0x00,0x00,0x07,0x0F,0x08,0x08,0x0F,0x07,0x00},//o79
{0x00,0xE0,0xE0,0x20,0x20,0xE0,0xC0,0x00,0x00,0x7F,0x7F,0x08,0x08,0x0F,0x07,0x00},//p80
{0x00,0xC0,0xE0,0x20,0x20,0xE0,0xE0,0x00,0x00,0x07,0x0F,0x08,0x08,0x7F,0x7F,0x00},//q81
{0x00,0xE0,0xE0,0x80,0x40,0x60,0x60,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00},//r82
{0x00,0xC0,0xE0,0x20,0x20,0x20,0x20,0x00,0x00,0x08,0x09,0x09,0x09,0x0F,0x06,0x00},//s83
{0x00,0x20,0xF8,0xF8,0x20,0x20,0x20,0x00,0x00,0x00,0x07,0x0F,0x08,0x08,0x08,0x00},//t84
{0x00,0xE0,0xE0,0x00,0x00,0xE0,0xE0,0x00,0x00,0x07,0x0F,0x08,0x08,0x0F,0x0F,0x00},//u85
{0x00,0xE0,0xE0,0x00,0x00,0xE0,0xE0,0x00,0x00,0x03,0x07,0x0C,0x0C,0x07,0x03,0x00},//v86
{0x00,0xE0,0xE0,0x00,0xC0,0x00,0xE0,0xE0,0x00,0x03,0x0F,0x0C,0x03,0x0C,0x0F,0x03},//w87
{0x00,0x60,0xE0,0x80,0x80,0xE0,0x60,0x00,0x00,0x0C,0x0E,0x03,0x03,0x0E,0x0C,0x00},//x88
{0x00,0xE0,0xE0,0x00,0x00,0xE0,0xE0,0x00,0x40,0x47,0x4F,0x68,0x38,0x1F,0x07,0x00},//y89
{0x00,0x20,0x20,0x20,0xA0,0xE0,0x60,0x00,0x00,0x0C,0x0E,0x0B,0x09,0x08,0x08,0x00},//z90
{0x00,0x00,0x80,0xF0,0x78,0x08,0x00,0x00,0x00,0x01,0x03,0x1E,0x3C,0x20,0x00,0x00},//{91
{0x00,0x00,0x00,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x00,0x00,0x00},//|92
{0x00,0x00,0x08,0x78,0xF0,0x80,0x00,0x00,0x00,0x00,0x20,0x3C,0x1E,0x03,0x01,0x00},//}93
{0x30,0x18,0x08,0x18,0x30,0x20,0x30,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};//~94


#endif