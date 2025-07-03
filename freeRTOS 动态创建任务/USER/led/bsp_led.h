#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "sys.h"
#include "stm32f10x.h"

#define LED1_GPIO_CLK  RCC_APB2Periph_GPIOA
#define LED1_GPIO_PORT GPIOA
#define LED1_GPIO_PIN GPIO_Pin_8

#define LED2_GPIO_CLK  RCC_APB2Periph_GPIOD
#define LED2_GPIO_PORT GPIOD
#define LED2_GPIO_PIN GPIO_Pin_2


#define LED1_ON GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN) 
#define LED1_OFF GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN) 	
#define LED2_ON GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN) 
#define LED2_OFF GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)
void LED_Init(void);



#endif 

