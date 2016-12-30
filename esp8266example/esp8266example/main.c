
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include "esp8266.h"
#include "printf.h"
FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, USART0ReceiveByte, _FDEV_SETUP_RW);



int main (void)
{

	USART0Init(8);
	stdin=stdout=&usart0_str;
	_delay_ms(2000);
	
	char request1[]="POST /user_and_device_signup?name=taha&username=taha&password=897988935556&admin=false&location=balingen&deviceid=656556-xf2sdf2-sdf5f-sdf&email=taha@gmail.com HTTP/1.1";
	char request2[]="Host: atmega2560-esp8266.herokuapp.com";
	char request3[]="User-Agent: test";
	int length1=strlen(request1);
	int length2=strlen(request2);
	int length3=strlen(request3);
	int Totallength=length3+length2+length1+8;
	char DataByte[];
	itoa(Totallength,DataByte);

	WifiReset();
	_delay_ms(5000);
	WifiConnectionMode('1');
	_delay_ms(2000);
	WifiConnection("adiguzelfamilie","Seyda2515gstl.");
	_delay_ms(10000);
	WifiConnectionStart("atmega2560-esp8266.herokuapp.com","80");
	_delay_ms(2000);
	WifiSendByte(DataByte);
	_delay_ms(2000);
	PostRequest(request1,request2,request3);
	
	


	printf("Totallength=%d",Totallength);

	while(1)
	{
 
		 
		
		
	}
}

