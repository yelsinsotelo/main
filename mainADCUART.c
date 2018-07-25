#define  F_CPU 20000000
#define BAUD 9600
#define  MYUBRR F_CPU/BAUD/16-1
#include <avr/io.h>
#include "avrpin.h"
#include "stdio.h"
#include <math.h>	
#include <util/delay.h>

void I_sys (){
	initADC();
	initUSART(MYUBRR);
	}
int main(void)
{
	I_sys();
	//float adc_lecture;
	char out_str[30];
	DDRB=0xFF;
	DDRD=0b11100000;
    while (1) 
    {
		
		PORTB=readADC(pinADC5);
		//adc_lecture=readADC(pinADC5);
		unsigned int entero= readADC(pinADC5);
		//unsigned int decimales= ((int)(adc_lecture*1000))%1000;		
		sprintf(out_str, " %u\n\r ", entero);
		TxString(out_str);
		  }
}

