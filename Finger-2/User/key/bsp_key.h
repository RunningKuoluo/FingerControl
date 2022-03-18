//条件编译宏
#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"


#define KEY_ON          1
#define KEY_OFF         0


#define KEY1_GPIO_PIN                   GPIO_Pin_0
#define KEY2_GPIO_PIN                   GPIO_Pin_13

#define KEY1_GPIO_CLK                   RCC_APB2Periph_GPIOA
#define KEY2_GPIO_CLK                   RCC_APB2Periph_GPIOC
#define KEY1_GPIO_PORT                  GPIOA
#define KEY2_GPIO_PORT                  GPIOC

void KEY_GPIO_Config(void);//按键引脚配置函数
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);//按键扫描函数

#endif /*__BSP_KEY_H*/

