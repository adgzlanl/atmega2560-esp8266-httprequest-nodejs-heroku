
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include "esp8266.h"
#include "printf.h"
#define SIGRD 5
#include <avr/boot.h>

FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, USART0ReceiveByte, _FDEV_SETUP_RW);

uint32_t jenkins_one_at_a_time_hash(char *key, size_t len)
{
	uint32_t hash, i;
	for(hash = i = 0; i < len; ++i)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

int main (void)
{

	USART0Init(8);
	stdin=stdout=&usart0_str;
	_delay_ms(2000);
	

	
	
	printf("%d\n",jenkins_one_at_a_time_hash("aniladiguzel@gmail.com",20));
	WifiReset();
	_delay_ms(5000);
	WifiConnectionMode('1');
	_delay_ms(2000);
	WifiConnection("adiguzelfamilie","Seyda2515gstl.");
	_delay_ms(10000);
	WifiConnectionStart("atmega2560-esp8266.herokuapp.com","80");
	_delay_ms(2000);
	
	//UserSignupRequest("gulcin","glcn","12321334234","false","balingen","1232132jklj-123kj123-sdf213-asd","glcn@gmail.com");

	DeviceParamRequest("glcn","1232132jklj-123kj123-sdf213-asd","glcn@gmail.com","true","true","true","true","true","true","true","true","true","true","true","true");
	
	


	

	while(1)
	{
 
		 
		
		
	}
}

