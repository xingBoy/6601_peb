/***********************************************
File:	读取主机MCU PA0-PA7、PB2-PB9的状态;检
			测PA8,当PA8为低，PA15 输出200MS低电平，
			平时PA15保持高电平。
************************************************/

#include "peb_6601.h" 
#include "stdio.h"

uint8_t PA_BUFF[1];		//PA0-PA7状态缓存区
uint8_t PB_BUFF[1];		//PB0-PB7状态缓存区

/*---------------------------------------------------
	函数名： PEB_6601
	输  入： 无
	输  出： 无
	说  明： 读取PA0-7.PB2-9状态,通过IIC发送给从机,
           检测PA8,当PA8为低，PA15输出200MS低电平
	返回值： 无
 ---------------------------------------------------*/
void PEB_6601(void)
{
	
	PA8_detec();
	Re_Port();
}


/*---------------------------------------------------
	函数名： Re_Port
	输  入： 无
	输  出： 无
	说  明： 读取PA0-PA7、PB2-PB9的状态
	返回值： 无
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
	
 

	
	while(HAL_I2C_Master_Transmit_IT(&hi2c2 ,0x0b,&PA_BUFF[0], 1)!= HAL_OK){}   //发送PA状态
	
	
		
	PB_BUFF[0] = HAL_GPIO_ReadPin(GPIOB ,PB2_Pin) << 7;
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB3_Pin) << 6 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB4_Pin) << 5 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB5_Pin) << 4 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB6_Pin) << 3 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB7_Pin) << 2 );
	PB_BUFF[0] = PB_BUFF[0] | ( HAL_GPIO_ReadPin(GPIOB ,PB8_Pin) << 1 );
	PB_BUFF[0] = PB_BUFF[0] | HAL_GPIO_ReadPin(GPIOB ,PB9_Pin);
	
	printf("PB = 0x%x\r\n",PB_BUFF[0]);
	
	while(HAL_I2C_Master_Transmit_IT(&hi2c2 ,0x0b,&PB_BUFF[0], 1)!= HAL_OK){}   //发送PA状态

}



/*--------------------------------------------------
	函数名： pa8_detec
	输  入： 无
	输  出： 无
	说  明： 检测PA8,当PA8为低，PA15输出200MS低电平
	返回值： 无
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
