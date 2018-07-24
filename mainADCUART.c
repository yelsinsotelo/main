#define  F_CPU 20000000
#define BAUD 9600
#define  MYUBRR F_CPU/BAUD/16-1
#include <avr/io.h>
#include "avrpin.h"
#include "stdio.h"
#include <util/delay.h>

void I_sys (){
	initADC();
	initUSART(MYUBRR);
	}
int main(void)
{
	I_sys();
	//unsigned int adc_lecture;
	DDRB=0b00111111;
	DDRD=0b11100000;
    while (1) 
    {
		//adc_lecture=5/1023*readADC(pinADC5);
		TxData(10);
		
    }
}

