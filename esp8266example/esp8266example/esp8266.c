/*
 * esp8266.c
 *
 * Created: 12/29/2016 10:23:33 PM
 *  Author: aniladiguzel
 */ 
 #include "printf.h"
 #include <stdio.h>
 
 void WifiReset(void)
 {
	 char ATCommand[]="AT+RST";
	 printf("%s",ATCommand);
	 USART0SendChar(13);
	 USART0SendChar(10);

 }
 void WifiConnectionMode(char mode)
 {
	 char ATCommand[]="AT+CWMODE=";
	 
	 printf("%s%c",ATCommand,mode);
	 USART0SendChar(13);
	 USART0SendChar(10);



 }
 void WifiConnection(char SSID[],char Password[])
 {
	 char ATCommand[]="AT+CWJAP=";
	 printf("%s\"%s\",\"%s\"",ATCommand,SSID,Password);
	 USART0SendChar(13);
	 USART0SendChar(10);
 }

 void WifiRestore(void)
 {
	 char ATCommand[]="AT+RESTORE";
	 printf("%s",ATCommand);
	 USART0SendChar(13);
	 USART0SendChar(10);
 }


 void WifiList(void)
 {
	 char ATCommand[]="AT+CWLAP";
	 printf("%s",ATCommand);
	 USART0SendChar(13);
	 USART0SendChar(10);

 }

 void WifiIP(void)
 {
	 char ATCommand[]="AT+CIFSR";
	 printf("%s",ATCommand);
	 USART0SendChar(13);
	 USART0SendChar(10);

 }
 
 
 void WifiConnectionStart(char host[], char Port[])
 {
	
			 char ATCommand[]="AT+CIPSTART=\"TCP\",";
			 printf("%s\"%s\",%s",ATCommand,host,Port);
			 USART0SendChar(13);
			 USART0SendChar(10);
		
 }

 void WifiSendByte(char SendByte[])
 {
		 char ATCommand[]="AT+CIPSEND=";
		 printf("%s%s",ATCommand,SendByte);
		 USART0SendChar(13);
		 USART0SendChar(10);
 }

 void PostRequest(char Request1[],char Request2[],char Request3[])
 
 {
	
		printf("%s",Request1);
		USART0SendChar(13);
		USART0SendChar(10);
		printf("%s",Request2);
		USART0SendChar(13);
		USART0SendChar(10);
		printf("%s",Request3);
		USART0SendChar(13);
		USART0SendChar(10);
		USART0SendChar(13);
		USART0SendChar(10);
 }

 unsigned char PostLength()
 {
	char RequesString[]="";
 }