/*���������ֹ����ļ����ó��ֱ���*/
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

// \C������������з������治�����κζ���
#define LED_G(a)     if(a) \
	                        GPIO_ResetBits(LED_GPIO_PORT,LED_G_GPIO_PIN);/*PB0��0���̵���*/\
                     else   GPIO_SetBits(LED_GPIO_PORT,LED_G_GPIO_PIN);/*PB0��1���̵���*/
#define LED_B(a)     if(a) \
	                        GPIO_ResetBits(LED_GPIO_PORT,LED_B_GPIO_PIN);/*PB1��0��������*/\
                     else   GPIO_SetBits(LED_GPIO_PORT,LED_B_GPIO_PIN);/*PB1��1��������*/
#define LED_R(a)     if(a) \
	                        GPIO_ResetBits(LED_GPIO_PORT,LED_R_GPIO_PIN);/*PB5��0�������*/\
                     else   GPIO_SetBits(LED_GPIO_PORT,LED_R_GPIO_PIN);/*PB5��1�������*/

//^���C���Ե�һ�������Ƶ������
//����Ϊ1����ͬΪ0�����ڶ�Ӧ������λһֱ��1��������1���Ϊ0����0���Ϊ1��ODR�Ĵ�����ֵʵ��0��1��ת
#define LED_G_TOGGLE              {LED_GPIO_PORT->ODR ^= LED_G_GPIO_PIN;}
#define LED_B_TOGGLE              {LED_GPIO_PORT->ODR ^= LED_B_GPIO_PIN;}
#define LED_R_TOGGLE              {LED_GPIO_PORT->ODR ^= LED_R_GPIO_PIN;}
               

void LED_GPIO_Config(void);//�˿����ú���
#endif /*_BSP_LED_H*/

