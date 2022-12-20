/*
 * DIO_Drives.c
 *
 * Created: 7/22/2022 3:15:28 PM
 *  Author: Mostafa hamedo 
 */

#include <avr/io.h>
#include "std_macros.h"

void DIO_set_pin_direction(char portname ,char pinnumber,char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
			if(direction==1)
			{
				DDRA|=(1<<pinnumber);
			}
			else
			{
				DDRA&=~(1<<pinnumber);
			}		
		break;
			case 'B':
			case 'b':
			if(direction==1)
			{
				DDRB|=(1<<pinnumber);
			}
			else
			{
				DDRB&=~(1<<pinnumber);
			}
		break;
			case 'C':
			case 'c':
			if(direction==1)
			{
				DDRC|=(1<<pinnumber);
			}
			else
			{
				DDRC&=~(1<<pinnumber);
			}
		
		break;
			case 'D':
			case 'd':
			if (direction==1)
			{
				DDRD|=(1<<pinnumber);
			}
			else
			{
				DDRD&=~(1<<pinnumber);
			}
		break;
		
	}
}	
// the write pin code

void DIO_write_pin(char portname, char pinnumber,char value)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if (value==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
	break;
		case 'B':
		case 'b':
		if (value==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);	
		}
	break;
		case 'C':
		case 'c':
		if (value==1)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else 
		{
			CLR_BIT(PORTC,pinnumber);
		}
	break;
		case 'D':
		case 'd':
		if (value==1)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else 
		{
			CLR_BIT(PORTD,pinnumber);
		}
	break;
	
	}
}	
	
// the toggle pin code 

void DIO_toggle_pin(char portname,char pinnumber)
{
	switch (portname)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pinnumber);
	break;
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pinnumber);
	break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pinnumber);
	break;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pinnumber);
	break;
		}	
}	

// the read pin code 

unsigned char DIO_read_pin(char portname, char pinnumber)
{
	unsigned char value=0;
	switch(portname)
	{
		case 'A':
		case 'a':
		value=READ_BIT(PINA,pinnumber);
	break;
		case 'B':
		case 'b':
		value=READ_BIT(PINB,pinnumber);
	break;
		case 'C':
		case 'c':
		value=READ_BIT(PINC,pinnumber);
	break;
		case 'D':
		case 'd':
		value=READ_BIT(PIND,pinnumber);
	break;
	
	}
	return value ;
}

// the set port direction 
void DIO_set_port_direction(char portname,char direction )
{
	switch(portname)
		{
			case 'A':
			case 'a':
			DDRA=direction;  
			break; 
			//.........................
			case 'B':
			case 'b': 
			DDRB=direction ;
			break;
			//.........................
			case 'C':
			case 'c':
			DDRC=direction;
			break;
			//..........................
			case 'D':
			case 'd':
			DDRD=direction;
			break;
			//..........................
		}					
}


// the write port code 
void DIO_write_port(char portname , char outputvalue)	
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA=outputvalue;
		break;
		//......................
		case 'B':
		case 'b':
		PORTB=outputvalue;
		break;
		//......................
		case 'C':
		case 'c':
		PORTC=outputvalue;
		break;
		//......................
		case 'D':
		case 'd':
		PORTD=outputvalue;
		break;
		//......................
	}
}
	
// THE Toggle port code 

void DIO_toggle_port(char portname)	
{
	switch (portname)
	{
		case 'A':
		case 'a':
		PORTA=~PORTA;
		break; 
		//....................
		case 'B':
		case 'b':
		PORTB=~PORTB;
		break;
		//....................
		case 'C':
		case 'c':
		PORTC=~PORTC;
		break;
		//....................
		case 'D':
		case 'd':
		PORTD=~PORTD;
		break;
		//....................	
	}	
}
	
// THE READ PORT CODE 	
unsigned char DIO_read_port(char portname)
{
	unsigned char value=0 ; 
	switch (portname)
	{
		case 'A':
		case 'a':
		value=PIND ;
		break;
		//....................
		
		case 'B':
		case 'b':
		value=PINB ;
		break;
		//....................
		
		case 'C':
		case 'c':
		value=PINC ;
		break;
		//....................
		
		case 'D':
		case 'd':
		value=PIND ;
		break;
	}
	
	return value ;
}
void DIO_connect_pull_up(char portname,char pinnumber,char enable)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if(enable==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		//---------
		case 'B':
		case 'b':
		if(enable==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
	//-------------------------
		case 'C':
		case 'c':
		if(enable==1)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}	
		break;
		//---------------
		case 'D':
		case 'd':
		if(enable==1)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		}
	
	
	
}

void write_low_nibble(unsigned char portname ,unsigned char nibble_number)
{
	DIO_write_pin(portname,0,READ_BIT(nibble_number,0));
	DIO_write_pin(portname,1,READ_BIT(nibble_number,1));
	DIO_write_pin(portname,2,READ_BIT(nibble_number,2));
	DIO_write_pin(portname,3,READ_BIT(nibble_number,3));
}
void write_high_nibble(unsigned char portname ,unsigned char nibble_number)
{
	DIO_write_pin(portname,3,READ_BIT(nibble_number,0));
	DIO_write_pin(portname,4,READ_BIT(nibble_number,1));
	DIO_write_pin(portname,5,READ_BIT(nibble_number,2));
	DIO_write_pin(portname,6,READ_BIT(nibble_number,3));
	/*nibble_number<<=4;
	switch(portname)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=nibble_number;
		case 'B':
		PORTB&=0x0f;
		PORTB|=nibble_number;
		case 'C':
		PORTC&=0x0f;
		PORTC|=nibble_number;
		case 'D':
		PORTD&=0x0f;
		PORTD|=nibble_number;
	}*/
}