//bsp:board support package �弶֧�ְ� ��ֻ���ض��Ŀ�����ƥ��
#include "bsp_led.h"//ֻҪ���ͷ�ļ��ͱ���Ҫ��C/C++�����ͷ�ļ���·��

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);//��ʱ��
	
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN|LED_B_GPIO_PIN|LED_R_GPIO_PIN;//Pin0��1��5
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//����50MHz
	
	GPIO_Init(LED_GPIO_PORT,&GPIO_InitStruct);//�˿�����д��Ĵ���
	
}

