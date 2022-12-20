/*
 * timer.c
 *
 * Created: 12/11/2022 2:29:55 AM
 *  Author: Lenovo
 */ 

#include "std_macros.h"
#include<avr/interrupt.h>
#include <avr/io.h>




void timer_ctc_init(void)
{
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	OCR0=78 ;
	
	SET_BIT(TCCR0,WGM01) ;
	
	
	sei();
	SET_BIT(TIMSK,OCIE0);

}



void pwm_timer0(void)
{
	//set oc0 as output pin 
	SET_BIT(DDRB,3) ;
	
	//SET_OCR0 VALUE
	
	OCR0=64 ; 
	
	//select timer clock as 1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// select fast pwm mode 
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	// select oc0 mode (compare output mode)
	// (non_inverting mode) 
	
	SET_BIT(TCCR0,COM01);

}



void pwm_phase_correct_timer0(void)
{
	//set oc0 as output pin
	SET_BIT(DDRB,3) ;
	
	//SET_OCR0 VALUE
	
	OCR0=128 ;
	
	//select timer clock as 1024
	//SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// select pwm phase correct mode
	SET_BIT(TCCR0,WGM00);
	
	// select oc0 mode (compare output mode)
	// (non_inverting mode)
	
	
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	

}
void pwm_motor(unsigned char value )
{
	//set oc0 as output pin
	SET_BIT(DDRB,3) ;
	
	//SET_OCR0 VALUE
	
	OCR0=value  ;
	
	//select timer clock as 1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// select fast pwm mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	// select oc0 mode (compare output mode)
	// (non_inverting mode)
	
	SET_BIT(TCCR0,COM01);

}
