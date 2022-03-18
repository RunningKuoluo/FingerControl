//bsp:board support package 板级支持包 即只和特定的开发板匹配
#include "bsp_led.h"//只要添加头文件就必须要在C/C++里添加头文件的路径

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);//打开时钟
	
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN|LED_B_GPIO_PIN|LED_R_GPIO_PIN;//Pin0、1、5
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//速率50MHz
	
	GPIO_Init(LED_GPIO_PORT,&GPIO_InitStruct);//端口配置写入寄存器
	
}

