#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "stm32f10x.h"
#include <stdio.h>
/**
串口宏定义，不同的串口挂载的总线和 IO 不一样，移植时需要修改这几个宏
**/

#define DEBUG_USART1           0
#define DEBUG_USART2           1
#define DEBUG_USART3           0
#define DEBUG_USART4           0
#define DEBUG_USART5           0


#if  DEBUG_USART1
// 串口 1-USART1
#define DEBUG_USARTx                                         USART1
#define DEBUG_USART_CLK                                      RCC_APB2Periph_USART1
#define DEBUG_USART_APBxClkCmd                               RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE                                 115200
 
// USART GPIO 引脚宏定义
#define DEBUG_USART_GPIO_CLK                                 (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_APBxClkCmd                           RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT                              GPIOA
#define DEBUG_USART_TX_GPIO_PIN                               GPIO_Pin_9
#define DEBUG_USART_RX_GPIO_PORT                              GPIOA
#define DEBUG_USART_RX_GPIO_PIN                               GPIO_Pin_10

#define DEBUG_USART_IRQ                                       USART1_IRQn
#define DEBUG_USART_IRQHandler                                USART1_IRQHandler

#elif DEBUG_USART2
// 串口 2-USART2
#define DEBUG_USARTx                                         USART2
#define DEBUG_USART_CLK                                      RCC_APB1Periph_USART2
#define DEBUG_USART_APBxClkCmd                               RCC_APB1PeriphClockCmd
#define DEBUG_USART_BAUDRATE                                 115200
 
// USART GPIO 引脚宏定义
#define DEBUG_USART_GPIO_CLK                                 (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_APBxClkCmd                           RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT                              GPIOA
#define DEBUG_USART_TX_GPIO_PIN                               GPIO_Pin_2
#define DEBUG_USART_RX_GPIO_PORT                              GPIOA
#define DEBUG_USART_RX_GPIO_PIN                               GPIO_Pin_3

#define DEBUG_USART_IRQ                                       USART2_IRQn
#define DEBUG_USART_IRQHandler                                USART2_IRQHandler

#elif DEBUG_USART3
// 串口 3-USART3
#define DEBUG_USARTx                                         USART3
#define DEBUG_USART_CLK                                      RCC_APB1Periph_USART3
#define DEBUG_USART_APBxClkCmd                               RCC_APB1PeriphClockCmd
#define DEBUG_USART_BAUDRATE                                 115200
 
// USART GPIO 引脚宏定义
#define DEBUG_USART_GPIO_CLK                                 (RCC_APB2Periph_GPIOB)
#define DEBUG_USART_GPIO_APBxClkCmd                           RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT                              GPIOB
#define DEBUG_USART_TX_GPIO_PIN                               GPIO_Pin_10
#define DEBUG_USART_RX_GPIO_PORT                              GPIOB
#define DEBUG_USART_RX_GPIO_PIN                               GPIO_Pin_11

#define DEBUG_USART_IRQ                                       USART3_IRQn
#define DEBUG_USART_IRQHandler                                USART3_IRQHandler

#elif DEBUG_USART4
// 串口 4-USART4
#define DEBUG_USARTx                                         USART4
#define DEBUG_USART_CLK                                      RCC_APB1Periph_USART4
#define DEBUG_USART_APBxClkCmd                               RCC_APB1PeriphClockCmd
#define DEBUG_USART_BAUDRATE                                 115200
 
// USART GPIO 引脚宏定义
#define DEBUG_USART_GPIO_CLK                                 (RCC_APB2Periph_GPIOC)
#define DEBUG_USART_GPIO_APBxClkCmd                           RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT                              GPIOC
#define DEBUG_USART_TX_GPIO_PIN                               GPIO_Pin_10
#define DEBUG_USART_RX_GPIO_PORT                              GPIOC
#define DEBUG_USART_RX_GPIO_PIN                               GPIO_Pin_11

#define DEBUG_USART_IRQ                                       USART4_IRQn
#define DEBUG_USART_IRQHandler                                USART4_IRQHandler

#elif DEBUG_USART5
// 串口 5-USART5
#define DEBUG_USARTx                                         USART5
#define DEBUG_USART_CLK                                      RCC_APB1Periph_USART5
#define DEBUG_USART_APBxClkCmd                               RCC_APB1PeriphClockCmd
#define DEBUG_USART_BAUDRATE                                 115200
 
// USART GPIO 引脚宏定义
#define DEBUG_USART_GPIO_CLK                                 (RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD)
#define DEBUG_USART_GPIO_APBxClkCmd                           RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT                              GPIOC
#define DEBUG_USART_TX_GPIO_PIN                               GPIO_Pin_12
#define DEBUG_USART_RX_GPIO_PORT                              GPIOD
#define DEBUG_USART_RX_GPIO_PIN                               GPIO_Pin_2

#define DEBUG_USART_IRQ                                       USART5_IRQn
#define DEBUG_USART_IRQHandler                                USART5_IRQHandler
#endif


/*串口初始化配置*/
void USART_Config(void);

/*串口发送一个字节函数*/
void Usart_SendByte(USART_TypeDef* pUSARTx,uint8_t data);

/*串口发送两个字节函数*/
void Usart_SendHalfWord(USART_TypeDef* pUSARTx,uint16_t data);

/*发送8位字节数组的函数*/
void Usart_SendArray(USART_TypeDef* pUSARTx,uint8_t *array,uint8_t num);

/*发送字符串的函数*/
void Usart_SendStr(USART_TypeDef* pUSARTx,uint8_t *str);



#endif /*__BSP_USART_H*/ 

