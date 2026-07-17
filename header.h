#ifndef HEADER_H
#define HEADER_H

#include <lpc21xx.h>
#include <string.h>
#define lcd 0xf<<8
#define rs 1<<2
#define e 1<<3
#define light1 1<<14
#define light2 1<<15
#define light3 1<<16
#define light4 1<<17

void delay_ms(int);
void delay_sec(int);

void init(void);
void cmd(char);
void data(char);
void title(char*);
void str(char*);
void cgram(char);
void display(void);

void uart_init(void);
void tx(char);
char rx(void);

void uart(void);
void lyt1(char);
void lyt2(char);
void lyt3(char);
void lyt4(char);

#endif
