#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK miniSTM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 
#define    KEY0_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    KEY0_GPIO_PORT    GPIOC			   
#define    KEY0_GPIO_PIN		 GPIO_Pin_5

#define    KEY1_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    KEY1_GPIO_PORT    GPIOA		   
#define    KEY1_GPIO_PIN		  GPIO_Pin_15

#define KEY0  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)//��ȡ����1
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����2 
 

#define KEY0_PRES	1		//KEY0  
#define KEY1_PRES	2		//KEY1 
#define WKUP_PRES	3		//WK_UP  

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��	
//uint8_t KEY_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
#endif
