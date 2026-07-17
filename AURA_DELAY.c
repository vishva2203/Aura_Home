#include "header.h"

void delay_sec(int sec)
{
    T0PR  = 15000000-1;
    T0TCR = 0x01;

    while(T0TC < sec);

    T0TCR = 0x03;
    T0TCR = 0x00;
}

void delay_ms(int ms)
{
    T0PR  = 15000-1;
    T0TCR = 0x01;

    while(T0TC < ms);

    T0TCR = 0x03;
    T0TCR = 0x00;
}
