#ifndef _PEB_6601_H
#define _PEB_6601_H

#include "stdio.h"	
#include "stm32f0xx_hal.h"

/*	这里主机7位地址设置为101 0000，从机7位地址设置为101 1000	*/
//#define salve_add  0xb0 	//从机地址+RW：101 1000 = 0x58，第8位R/W为0，表示写数据给从机
 
extern I2C_HandleTypeDef hi2c2;
extern UART_HandleTypeDef huart1;
void PEB_6601(void);
void PA8_detec(void);
void Re_Port(void);
 

#endif

