#include "header.h"

char lut[]={ 0X0E,0X11,0X11,0X11,0X0E,0X00,0X0E,0X00, 
						 0X0E,0X11,0X11,0X1F,0X0E,0X00,0X0E,0X00, 
						 0X0E,0X11,0X1F,0X1F,0X0E,0X00,0X0E,0X00, 
						 0X0E,0X1F,0X1F,0X1F,0X0E,0X00,0X0E,0X00 };

void init(void)
{
	IODIR0|=lcd|rs|e;
	cmd(0X01);
	cmd(0X02);
	cmd(0X0C);
	cmd(0X28);
}
void cmd(char c)
{
	IOCLR0=lcd;
	IOSET0=(c & 0xF0) << 4;
	IOCLR0=rs;
	IOSET0=e;
	delay_ms(2);
	IOCLR0=e;
	
	IOCLR0=lcd;
	IOSET0=(c & 0x0F) << 8;
	IOCLR0=rs;
	IOSET0=e;
	delay_ms(2);
	IOCLR0=e;
}
void data(char d)
{
	IOCLR0=lcd;
	IOSET0=(d & 0xF0) << 4;
	IOSET0=rs;
	IOSET0=e;
	delay_ms(2);
	IOCLR0=e;
	
	IOCLR0=lcd;
	IOSET0=(d & 0x0F) << 8;
	IOSET0=rs;
	IOSET0=e;
	delay_ms(2);
	IOCLR0=e;
}
void title(char*t)
{
	while(*t)
	{
		delay_ms(50);
		data(*t++);
	}
}
void str(char*s)
{
	while(*s)
	{
		delay_ms(10);
		data(*s++);
	}
}
void cgram(char cg)
{
	char i;
	cmd(0x40);
	for(i=0;i<cg;i++)
			data(lut[i]);
	cmd(0x80);
}
