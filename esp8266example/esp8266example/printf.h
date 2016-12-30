/*
 * printf.h
 *
 * Created: 12/29/2016 10:16:34 PM
 *  Author: aniladiguzel
 */ 


#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdio.h>
#include <avr/pgmspace.h>
void printInit(void);
void USART0Init(unsigned char UBRR_VALUE);
int USART0SendByte(char u8Data, FILE *stream);
void USART0SendChar(char u8Data);
int USART0ReceiveByte(FILE *stream);
#endif /* PRINTF_H_ */