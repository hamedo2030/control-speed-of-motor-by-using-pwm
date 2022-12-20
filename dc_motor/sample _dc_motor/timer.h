/*
 * timer.h
 *
 * Created: 12/11/2022 2:30:14 AM
 *  Author: Lenovo
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void timer_ctc_init(void) ;
void pwm_timer0(void) ;
void pwm_phase_correct_timer0(void);
void pwm_motor(unsigned char value ) ;   
   
   
   
   
#endif /* TIMER_H_ */