#ifndef _PEB_6601_H
#define _PEB_6601_H

#include "stdio.h"	
#include "stm32f0xx_hal.h"

/*	��������7λ��ַ����Ϊ101 0000���ӻ�7λ��ַ����Ϊ101 1000	*/
//#define salve_add  0xb0 	//�ӻ���ַ+RW��101 1000 = 0x58����8λR/WΪ0����ʾд���ݸ��ӻ�
 
extern I2C_HandleTypeDef hi2c2;
extern UART_HandleTypeDef huart1;
void PEB_6601(void);
void PA8_detec(void);
void Re_Port(void);
 

#endif

