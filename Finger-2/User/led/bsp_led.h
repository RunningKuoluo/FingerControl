/*条件编译防止多个文件调用出现报错*/
#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"


#define LED_G_GPIO_PIN                  GPIO_Pin_0
#define LED_B_GPIO_PIN                  GPIO_Pin_1
#define LED_R_GPIO_PIN                  GPIO_Pin_5

#define LED_GPIO_CLK                    RCC_APB2Periph_GPIOB
#define LED_GPIO_PORT                   GPIOB



#define    ON        1
#define    OFF       0

#define LED_FLAG     1

// \C语言里面叫续行符，后面不能有任何东西
#define LED_G(a)     if(a) \
	                        GPIO_ResetBits(LED_GPIO_PORT,LED_G_GPIO_PIN);/*PB0置0，绿灯亮*/\
                     else   GPIO_SetBits(LED_GPIO_PORT,LED_G_GPIO_PIN);/*PB0置1，绿灯灭*/
#define LED_B(a)     if(a) \
	                        GPIO_ResetBits(LED_GPIO_PORT,LED_B_GPIO_PIN);/*PB1置0，蓝灯亮*/\
                     else   GPIO_SetBits(LED_GPIO_PORT,LED_B_GPIO_PIN);/*PB1置1，蓝灯灭*/
#define LED_R(a)     if(a) \
	                        GPIO_ResetBits(LED_GPIO_PORT,LED_R_GPIO_PIN);/*PB5置0，红灯亮*/\
                     else   GPIO_SetBits(LED_GPIO_PORT,LED_R_GPIO_PIN);/*PB5置1，红灯灭*/

//^异或，C语言的一个二进制的运算符
//相异为1，相同为0，由于对应的引脚位一直是1，所以与1异或为0，与0异或为1，ODR寄存器的值实现0、1翻转
#define LED_G_TOGGLE              {LED_GPIO_PORT->ODR ^= LED_G_GPIO_PIN;}
#define LED_B_TOGGLE              {LED_GPIO_PORT->ODR ^= LED_B_GPIO_PIN;}
#define LED_R_TOGGLE              {LED_GPIO_PORT->ODR ^= LED_R_GPIO_PIN;}
               

void LED_GPIO_Config(void);//端口配置函数
#endif /*_BSP_LED_H*/

