/***********************************************
File:	��ȡ����MCU PA0-PA7��PB2-PB9��״̬;��
			��PA8,��PA8Ϊ�ͣ�PA15 ���200MS�͵�ƽ��
			ƽʱPA15���ָߵ�ƽ��
************************************************/

#include "peb_6601.h" 
#include "stdio.h"

uint8_t PA_BUFF[1];		//PA0-PA7״̬������
uint8_t PB_BUFF[1];		//PB0-PB7״̬������

/*---------------------------------------------------
	�������� PEB_6601
	��  �룺 ��
	��  ���� ��
	˵  ���� ��ȡPA0-7.PB2-9״̬,ͨ��IIC���͸��ӻ�,
           ���PA8,��PA8Ϊ�ͣ�PA15���200MS�͵�ƽ
	����ֵ�� ��
 ---------------------------------------------------*/
void PEB_6601(void)
{
	
	PA8_detec();
	Re_Port();
}


/*---------------------------------------------------
	�������� Re_Port
	��  �룺 ��
	��  ���� ��
	˵  ���� ��ȡPA0-PA7��PB2-PB9��״̬
	����ֵ�� ��
 --------------------------------------------------*/
void Re_Port(void)
{
//  //test A 1001 1101
//	HAL_GPIO_WritePin(GPIOA ,PA0_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA ,PA1_Pin,GPIO_PIN_RESET);	
//	HAL_GPIO_WritePin(GPIOA ,PA2_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA ,PA3_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA ,PA4_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA ,PA5_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA ,PA6_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA ,PA7_Pin,GPIO_PIN_SET);
//	
//		//test B 1010 0111
//	HAL_GPIO_WritePin(GPIOB ,PB2_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB ,PB3_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOB ,PB4_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB ,PB5_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOB ,PB6_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOB ,PB7_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB ,PB8_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB ,PB9_Pin,GPIO_PIN_SET);	
//	//==================================
//	
	PA_BUFF[0] = HAL_GPIO_ReadPin(GPIOA ,PA0_Pin) << 7;
	PA_BUFF[0] = PA_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOA ,PA1_Pin) << 6 );
	PA_BUFF[0] = PA_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOA ,PA2_Pin) << 5 );
	PA_BUFF[0] = PA_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOA ,PA3_Pin) << 4 );
	PA_BUFF[0] = PA_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOA ,PA4_Pin) << 3 );
	PA_BUFF[0] = PA_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOA ,PA5_Pin) << 2 );
	PA_BUFF[0] = PA_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOA ,PA6_Pin) << 1 );
	PA_BUFF[0] = PA_BUFF[0] | HAL_GPIO_ReadPin(GPIOA ,PA7_Pin);
	
	printf("PA = 0x%x\r\n",PA_BUFF[0]);
	
 

	
	while(HAL_I2C_Master_Transmit_IT(&hi2c2 ,0x0b,&PA_BUFF[0], 1)!= HAL_OK){}   //����PA״̬
	
	
		
	PB_BUFF[0] = HAL_GPIO_ReadPin(GPIOB ,PB2_Pin) << 7;
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB3_Pin) << 6 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB4_Pin) << 5 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB5_Pin) << 4 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB6_Pin) << 3 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB7_Pin) << 2 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB8_Pin) << 1 );
	PB_BUFF[0] = PB_BUFF[0] | HAL_GPIO_ReadPin(GPIOB ,PB9_Pin);
	
	printf("PB = 0x%x\r\n",PB_BUFF[0]);
	
	while(HAL_I2C_Master_Transmit_IT(&hi2c2 ,0x0b,&PB_BUFF[0], 1)!= HAL_OK){}   //����PA״̬

}



/*--------------------------------------------------
	�������� pa8_detec
	��  �룺 ��
	��  ���� ��
	˵  ���� ���PA8,��PA8Ϊ�ͣ�PA15���200MS�͵�ƽ
	����ֵ�� ��
 -------------------------------------------------*/
void PA8_detec(void)
{
	if( HAL_GPIO_ReadPin(GPIOA ,PA8_Pin) == RESET )
	//if(HAL_GPIO_TogglePin(GPIOA,PA8_Pin)==HAL_OK)	
	{
		HAL_GPIO_WritePin( GPIOA,PA15_Pin,GPIO_PIN_RESET );
		HAL_Delay(250);
		
	}
	if( HAL_GPIO_ReadPin(GPIOA ,PA8_Pin) == SET )
	{
		HAL_GPIO_WritePin(GPIOA,PA15_Pin,GPIO_PIN_SET);
		//HAL_Delay(250);
	}
}

/***************File_END*******************/
