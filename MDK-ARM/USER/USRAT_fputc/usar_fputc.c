#include "stdio.h"
#include "stm32f0xx_hal.h"

extern UART_HandleTypeDef huart1;
uint8_t ch;
uint8_t ch_r;

//��д�������,�ض���printf����������
/*fputc*/
int fputc(int c, FILE * f)
{
    ch=c;
    HAL_UART_Transmit(&huart1,&ch,1,1000);//���ʹ���
    return c;
}



//�ض���scanf���������� ��˼����˵���ܴ��ڷ�����������
/*fgetc*/
int fgetc(FILE * F)    
{
    HAL_UART_Receive (&huart1,&ch_r,1,0xffff);//����
    return ch_r;
}
