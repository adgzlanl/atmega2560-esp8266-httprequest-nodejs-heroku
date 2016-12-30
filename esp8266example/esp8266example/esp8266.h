/*
 * esp8266.h
 *
 * Created: 12/29/2016 10:23:57 PM
 *  Author: aniladiguzel
 */ 


#ifndef ESP8266_H_
#define ESP8266_H_


void WifiReset(void);
void WifiConnectionMode(char mode);
void WifiConnection(char SSID[],char Password[]);
void WifiRestore(void);
void WifiList(void);
void WifiIP(void);




#endif /* ESP8266_H_ */