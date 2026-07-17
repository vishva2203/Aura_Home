#include "header.h"

int main()
{
	IODIR0 |= light1|light2|light3|light4;
	IOSET0 = light1|light2|light3|light4;
	init();
	uart_init();
	display();
	uart();
	PINSEL0 |= 0;
	PINSEL1 |= 0;	
}
void display(void)
{
	cgram(32);
	delay_ms(100);
	cmd(0x1);
	cmd(0x80);
	title("AURA_HOME:");
	cmd(0x8B);
	data(0);
	delay_ms(300);
	cmd(0xC3);
	title("IOT-BASED");
	cmd(0x8C);
	data(1);
	delay_ms(200);
	cmd(0x97);
	title("SMART HOME");
	cmd(0x8D);
	data(2);
	delay_ms(100);
	cmd(0xD7);
	title("AUTOMATION");
	cmd(0x8E);
	data(3);
	delay_ms(1500);
	cmd(0x01);
}
void uart_init(void)
{
	PINSEL0|=0X05;
	U0LCR=0X83;
	U0DLL=97;
	U0LCR=0X03;
}
void tx(char tb)
{
	while(((U0LSR>>5)&1)==0);
	U0THR=tb;
}
char rx(void)
{
	while((U0LSR&1)==0);
	return U0RBR;
}
void uart(void)
{
	char rb;
	cmd(0x80);
	str("LIGHT 1: OFF");
	cmd(0xC0);
	str("LIGHT 2: OFF");
	cmd(0x94);
	str("LIGHT 3: OFF");
	cmd(0xD4);
	str("LIGHT 4: OFF");
	while(1)
	{
		rb=rx();
		switch(rb)
		{
			case '1':
			case '0': 
								lyt1(rb);
								break;

			case '2':
			case '3':
								lyt2(rb);
								break;

			case '4':
			case '5':
								lyt3(rb);
								break;

			case '6':
			case '7':
								lyt4(rb);
								break;

			default:
								break;
		}
	}
}
void lyt1(char rb)
{
    cmd(0x89);

    if(rb=='1')
    {
		IOCLR0=light1;
        str("ON ");
        cmd(0x8D);
        data(3);          
    }
    else
    {
		IOSET0=light1;
        str("OFF");
        cmd(0x8D);
        data(0);          
    }
}
void lyt2(char rb)
{
    cmd(0xC9);

    if(rb=='2')
    {
		IOCLR0=light2;
        str("ON ");
        cmd(0xCD);
        data(3);
    }
    else
    {
		IOSET0=light2;
        str("OFF");
        cmd(0xCD);
        data(0);
    }
}
void lyt3(char rb)
{
    cmd(0x9D);

    if(rb=='4')
    {
		IOCLR0=light3;
        str("ON ");
        cmd(0xA1);
        data(3);
    }
    else
    {
		IOSET0=light3;
        str("OFF");
        cmd(0xA1);
        data(0);
    }
}
void lyt4(char rb)
{
    cmd(0xDD);

    if(rb=='6')
    {
		IOCLR0=light4;
        str("ON ");
        cmd(0xE1);
        data(3);
    }
    else
    {
		IOSET0=light4;
        str("OFF");
        cmd(0xE1);
        data(0);
    }
}
