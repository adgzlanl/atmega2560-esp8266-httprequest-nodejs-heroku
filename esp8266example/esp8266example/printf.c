#include <stdio.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "printf.h"



void USART0Init(unsigned char UBRR_VALUE)
{
	
	UBRR0H = (uint8_t)(UBRR_VALUE>>8);
	UBRR0L = (uint8_t)UBRR_VALUE;
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
}
int USART0SendByte(char u8Data, FILE *stream)
{
	if(u8Data == '\n')
	{
		USART0SendByte('\r', 0);
	}
	
	while(!(UCSR0A&(1<<UDRE0))){};

	UDR0 = u8Data;
	return 0;
}

void USART0SendChar(char u8Data)
{
	while(!(UCSR0A&(1<<UDRE0))){};

	UDR0 = u8Data;
	return 0;
}


int USART0ReceiveByte(FILE *stream)
{
	uint8_t u8Data;

	while(!(UCSR0A&(1<<RXC0))){};
	u8Data=UDR0;

	USART0SendByte(u8Data,stream);

	return u8Data;
}
void printInit(void)
{
	FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, USART0ReceiveByte, _FDEV_SETUP_RW);
	stdin=stdout=&usart0_str;
}