/* 
 * File:   Timer1.h
 * Author: evaota
 *
 * Created on 2017/02/26, 14:38
 */

#ifndef TIMER1_H
#define	TIMER1_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <math.h>
#include "main.h"
    
#define Timer1_Start()  TMR1ON = 1;
#define Timer1_Stop()   TMR1ON = 0;

#define Timer1_Read()   (uint16_t)TMR1
#define Timer1_Write(x)  {Timer1_Stop();\
                        TMR1 = (uint16_t)x;\
                        Timer1_Start();\
                        }   
#define Timer1_Clear()  Timer1_Write(0x0000)
    
void Timer1_Init(void);

#define DETECT_NUM_OF_COUNT 10UL
uint32_t Timer1_GetCountSum(void);
uint16_t Timer1_GetError(void);
uint16_t Timer1_GetCPM(void);

void Timer1_Count200us(void);
uint8_t Timer1_DetectAssignCount(void);//put into interrupt function

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER1_H */

