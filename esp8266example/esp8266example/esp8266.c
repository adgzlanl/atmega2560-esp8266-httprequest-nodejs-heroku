/*
 * esp8266.c
 *
 * Created: 12/29/2016 10:23:33 PM
 *  Author: aniladiguzel
 */ 
 #include "printf.h"
 #include <stdio.h>
 #include <avr/delay.h>
 
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


 void UserSignupRequest(char name[],char username[],char password[],char status[],char location[],char deviceID[],char email[])
 
 {


	char PostName[]="POST /user_and_device_signup?name=%s&username=%s&password=%s&status=%s&location=%s&deviceid=%s&email=%s HTTP/1.1";
 	char Host[]="Host: atmega2560-esp8266.herokuapp.com";
 	char UserAgent[]="User-Agent: test";
	int length9=strlen(email);
	int length8=strlen(deviceID);
	int length7=strlen(location);
	int length6=strlen(status);
	int length5=strlen(password);
	int length4=strlen(username);
	int length3=strlen(name);
	int length2=strlen(Host);
	int length1=strlen(UserAgent);
	int length0=strlen(PostName);
 	unsigned int Totallength=length9+length8+length7+length6+length5+length4+length3+length2+length1+length0+8-14;
	char *ATCommand="AT+CIPSEND=";
	printf("%s%d",ATCommand,Totallength);
	USART0SendChar(13);
	USART0SendChar(10);
	_delay_ms(1000);

	printf("POST /user_and_device_signup?name=%s&username=%s&password=%s&status=%s&location=%s&deviceid=%s&email=%s HTTP/1.1",name,username,password,status,location,deviceID,email);
	USART0SendChar(13);
	USART0SendChar(10);
	printf("%s",Host);
	USART0SendChar(13);
	USART0SendChar(10);
	printf("%s",UserAgent);
	USART0SendChar(13);
	USART0SendChar(10);
	USART0SendChar(13);
	USART0SendChar(10);


 }

  void DeviceParamRequest(char username[],char deviceID[],char email[],char param1[],char param2[],char param3[],char param4[],char param5[],char param6[],char param7[],char param8[],char param9[],char param10[],char param11[],char param12[])
  
  {


	  char PostName[]="POST /update_device_param?username=%s&deviceid=%s&email=%s&deviceparam1=%s&deviceparam2=%s&deviceparam3=%s&deviceparam4=%s&deviceparam5=%s&deviceparam6=%s&deviceparam7=%s&deviceparam8=%s&deviceparam9=%s&deviceparam10=%s&deviceparam11=%s&deviceparam12=%s HTTP/1.1";
	  char Host[]="Host: atmega2560-esp8266.herokuapp.com";
	  char UserAgent[]="User-Agent: test";
	  int length9=strlen(email);
	  int length8=strlen(deviceID);
	  int length7=strlen(username);
	  int length6=strlen(param1);
	  int length5=strlen(param2);
	  int length4=strlen(param3);
	  int length3=strlen(param4);
	  int length2=strlen(Host);
	  int length1=strlen(UserAgent);
	  int length0=strlen(PostName);
	  int length10=strlen(param1);
	  int length11=strlen(param2);
	  int length12=strlen(param3);
	  int length13=strlen(param4);
	  int length14=strlen(param1);
	  int length15=strlen(param2);
	  int length16=strlen(param3);
	  int length17=strlen(param4);
	  unsigned int Totallength=length17+length16+length15+length14+length13+length12+length11+length10+length9+length8+length7+length6+length5+length4+length3+length2+length1+length0+8-30;
	  char *ATCommand="AT+CIPSEND=";
	  printf("%s%d",ATCommand,Totallength);
	  USART0SendChar(13);
	  USART0SendChar(10);
	  _delay_ms(1000);

	  printf("POST /update_device_param?username=%s&deviceid=%s&email=%s&deviceparam1=%s&deviceparam2=%s&deviceparam3=%s&deviceparam4=%s&deviceparam5=%s&deviceparam6=%s&deviceparam7=%s&deviceparam8=%s&deviceparam9=%s&deviceparam10=%s&deviceparam11=%s&deviceparam12=%s HTTP/1.1",username,deviceID,email,param1,param2,param3,param4,param5,param6,param7,param8,param9,param10,param11,param12);
	  USART0SendChar(13);
	  USART0SendChar(10);
	  printf("%s",Host);
	  USART0SendChar(13);
	  USART0SendChar(10);
	  printf("%s",UserAgent);
	  USART0SendChar(13);
	  USART0SendChar(10);
	  USART0SendChar(13);
	  USART0SendChar(10);


  }

