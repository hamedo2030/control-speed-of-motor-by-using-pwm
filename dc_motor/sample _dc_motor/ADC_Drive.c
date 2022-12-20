/*
 * ADC_Drive.c
 *
 * Created: 10/14/2022 8:29:12 AM
 *  Author: happy
 */ 
#include "std_macros.h"
#include <avr/io.h>

void ADC_init(void)
{
	//SET_BIT(ADMUX,ADLAR);
	
	SET_BIT(ADMUX,REFS0);// AVCC voltage( 5 volt) and connect 
							//capacitor (10micro f) at AREF pin 
	
	SET_BIT(ADCSRA,ADEN); // ADC ENABLE 
	
	SET_BIT(ADCSRA,ADPS1); // prescaler select factor 128 
 	SET_BIT(ADCSRA,ADPS2);

}

unsigned short ADC_u16read(unsigned char channel)
{
	unsigned short read_value ;
	channel&=0x07;
	ADMUX=(ADMUX&0xf8)|channel;
	
	SET_BIT(ADCSRA,ADSC);				// enable ADC start conversion 
	while(READ_BIT(ADCSRA,ADSC)==1);    // wait until finish conversion 
	read_value=ADCL;					// read adc low data register 
	read_value|=(ADCH<<8);				// then read adc high data register
	return read_value;

}