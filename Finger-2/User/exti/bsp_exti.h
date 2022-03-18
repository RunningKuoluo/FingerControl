#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "stm32f10x.h"
/*KEY1*/
#define KEY1_INT_GPIO_PIN               GPIO_Pin_0
#define KEY1_INT_GPIO_PORT              GPIOA
#define KEY1_INT_GPIO_CLK               (RCC_APB2Periph_GPIOA\
                                        |RCC_APB2Periph_AFIO)
//#define KEY1_INT_GPIO_CLK             RCC_APB2Periph_GPIOA
#define KEY1_INT_EXTI_PORTSOURCE        GPIO_PortSourceGPIOA
#define KEY1_INT_EXTI_PINSOURCE         GPIO_PinSource0
#define KEY1_INT_EXTI_LINE              EXTI_Line0
#define KEY1_INT_EXTI_IRQ               EXTI0_IRQn

/*KEY2*/
#define KEY2_INT_GPIO_PIN               GPIO_Pin_13
#define KEY2_INT_GPIO_PORT              GPIOC
#define KEY2_INT_GPIO_CLK               (RCC_APB2Periph_GPIOC\
                                        |RCC_APB2Periph_AFIO)
//#define KEY2_INT_GPIO_CLK             RCC_APB2Periph_GPIOC
#define KEY2_INT_EXTI_PORTSOURCE        GPIO_PortSourceGPIOC
#define KEY2_INT_EXTI_PINSOURCE         GPIO_PinSource13
#define KEY2_INT_EXTI_LINE              EXTI_Line13
#define KEY2_INT_EXTI_IRQ               EXTI15_10_IRQn







void EXTI_Key_Config(void);

#endif /*__BSP_EXTI_H*/
