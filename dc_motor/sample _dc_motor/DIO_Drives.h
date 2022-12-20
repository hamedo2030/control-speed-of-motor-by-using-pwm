/*
 * DIO_Drives.h
 *
 * Created: 7/22/2022 5:03:06 PM
 *  Author: happy
 */ 


#ifndef DIO_DRIVES_H_
#define DIO_DRIVES_H_
// pin_header_function.............
void DIO_set_pin_direction(char portname ,char pinnumber,char direction);
void DIO_write_pin(char portname, char pinnumber,char value);
void DIO_toggle_pin(char portname,char pinnumber);
unsigned char DIO_read_pin(char portname, char pinnumber);
//................................
//........Port_header_function ...... 
void DIO_set_port_direction(char portname,char direction );
void DIO_write_port(char portname , char outputvalue);
void DIO_toggle_port(char portname);
unsigned char DIO_read_port(char portname);
void DIO_connect_pull_up(char portname,char pinnumber,char enable);

void write_low_nibble(unsigned char portname ,unsigned char nibble_number);
void write_high_nibble(unsigned char portname ,unsigned char nibble_number);



#endif /* DIO_DRIVES_H_ */