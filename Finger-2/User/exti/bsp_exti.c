#include "bsp_exti.h"

///*中断优先级配置函数 static表示此函数是内部函数只能在这个文件中被调用*/
//static void EXTI_NVIC_Config(void)
//{
//	NVIC_InitTypeDef NVIC_InitStruct;
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//中断优先级分组配置函数
//	
//	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;//配置中断源
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//配置抢占优先级为:1 多个中断时首先比较抢占优先级再比较子优先级
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;//配置子优先级为:1
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//使能中断通道
//	
//	NVIC_Init(&NVIC_InitStruct);//NVIC配置写入寄存器
//}
//void EXTI_Key_Config(void)
//{
//	   
//	  /*GPIO初始化结构体*/
//	GPIO_InitTypeDef GPIO_InitStruct;
//	
//		/*EXTI初始化结构体*/
//	EXTI_InitTypeDef EXTI_InitStruct;
//	
//	/*配置中断优先级*/
//	EXTI_NVIC_Config();
//	
//	
//	//初始化GPIO
//	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK|KEY2_INT_GPIO_CLK, ENABLE);//打开时钟
//	
//	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;//PA0
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入

//	GPIO_Init(KEY1_INT_GPIO_PORT,&GPIO_InitStruct);//端口配置写入寄存器
//	
//	GPIO_InitStruct.GPIO_Pin = KEY2_INT_GPIO_PIN;//PC13
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
//	
//	GPIO_Init(KEY2_INT_GPIO_PORT,&GPIO_InitStruct);//端口配置写入寄存器
//	
//	//初始化EXTI
//	/*打开AFIO的时钟-EXTI的时钟*/
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
//	/*配置输入线*/
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
//	
//	/*配置EXTI初始化结构体*/
//	EXTI_InitStruct.EXTI_Line = EXTI_Line0;//输入线0
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//中断模式
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//上升沿触发
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;//输入线使能
//	
//	EXTI_Init(&EXTI_InitStruct);//EXTI初始化配置写入寄存器
//}

/*中断优先级配置函数 static表示此函数是内部函数只能在这个文件中被调用*/
static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//中断优先级分组配置函数
	/*按键KEY1*/
	NVIC_InitStruct.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;//配置中断源
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//配置抢占优先级为:1 多个中断时首先比较抢占优先级再比较子优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;//配置子优先级为:1
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//使能中断通道
	
	NVIC_Init(&NVIC_InitStruct);//NVIC配置写入寄存器
	
	/*按键KEY2*/
	NVIC_InitStruct.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;//配置中断源
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//配置抢占优先级为:1 多个中断时首先比较抢占优先级再比较子优先级
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;//配置子优先级为:1
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//使能中断通道
	
	NVIC_Init(&NVIC_InitStruct);//NVIC配置写入寄存器
}
void EXTI_Key_Config(void)
{
	   
	  /*GPIO初始化结构体*/
	GPIO_InitTypeDef GPIO_InitStruct;
	
		/*EXTI初始化结构体*/
	EXTI_InitTypeDef EXTI_InitStruct;
	
	/*配置中断优先级*/
	EXTI_NVIC_Config();
	
	
	/*初始化GPIO*/
		/*打开GPIOA和GPIOC的时钟和打开AFIO的时钟-EXTI的时钟*/
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK|KEY2_INT_GPIO_CLK, ENABLE);//打开时钟
	
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;//PA0
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入

	GPIO_Init(KEY1_INT_GPIO_PORT,&GPIO_InitStruct);//端口配置写入寄存器
	
	GPIO_InitStruct.GPIO_Pin = KEY2_INT_GPIO_PIN;//PC13
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	
	GPIO_Init(KEY2_INT_GPIO_PORT,&GPIO_InitStruct);//端口配置写入寄存器
	
	/*初始化EXTI*/
	/*打开AFIO的时钟-EXTI的时钟*/
	/*上面已经实现*/
	/*配置输入线*/
	GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE);
	
	/*配置EXTI初始化结构体*/
	EXTI_InitStruct.EXTI_Line = KEY1_INT_EXTI_LINE;//输入线0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//上升沿触发
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;//输入线使能
	
	EXTI_Init(&EXTI_InitStruct);//EXTI初始化配置写入寄存器
	
	/*配置输入线*/
	GPIO_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE, KEY2_INT_EXTI_PINSOURCE);
	
	/*配置EXTI初始化结构体*/
	EXTI_InitStruct.EXTI_Line = KEY2_INT_EXTI_LINE;//输入线13
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//上升沿触发
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;//输入线使能
	
	EXTI_Init(&EXTI_InitStruct);//EXTI初始化配置写入寄存器
	
	
}

