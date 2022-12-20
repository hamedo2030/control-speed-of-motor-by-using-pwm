/*
 * sample__dc_motor.c
 *
 * Created: 12/20/2022 
 *  Author: mostafa_hamedo
 */ 


#include <avr/io.h>
#include "std_macros.h"
#include "DIO_Drives.h"
#define F_CPU 8000000 
#include <util/delay.h>
#include "ADC_Drive.h"
#include "timer.h"


int main(void)
{
	ADC_init() ;
	DIO_set_port_direction('d',0xff) ;
	unsigned short data ;
	unsigned char pulse  ;
    while(1)
    {
		
	 data= ADC_u16read(0) ;	   //
		pulse=data/4;          // to reduce the senstivity of sensor from 1024 to 256 
		
	   pwm_motor(pulse);            
       DIO_write_pin('d',0,1);    
	   DIO_write_pin('d',1,0);    
	
		
	
    }
}