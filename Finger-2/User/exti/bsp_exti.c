#include "bsp_exti.h"

///*�ж����ȼ����ú��� static��ʾ�˺������ڲ�����ֻ��������ļ��б�����*/
//static void EXTI_NVIC_Config(void)
//{
//	NVIC_InitTypeDef NVIC_InitStruct;
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//�ж����ȼ��������ú���
//	
//	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;//�����ж�Դ
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//������ռ���ȼ�Ϊ:1 ����ж�ʱ���ȱȽ���ռ���ȼ��ٱȽ������ȼ�
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;//���������ȼ�Ϊ:1
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//ʹ���ж�ͨ��
//	
//	NVIC_Init(&NVIC_InitStruct);//NVIC����д��Ĵ���
//}
//void EXTI_Key_Config(void)
//{
//	   
//	  /*GPIO��ʼ���ṹ��*/
//	GPIO_InitTypeDef GPIO_InitStruct;
//	
//		/*EXTI��ʼ���ṹ��*/
//	EXTI_InitTypeDef EXTI_InitStruct;
//	
//	/*�����ж����ȼ�*/
//	EXTI_NVIC_Config();
//	
//	
//	//��ʼ��GPIO
//	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK|KEY2_INT_GPIO_CLK, ENABLE);//��ʱ��
//	
//	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;//PA0
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������

//	GPIO_Init(KEY1_INT_GPIO_PORT,&GPIO_InitStruct);//�˿�����д��Ĵ���
//	
//	GPIO_InitStruct.GPIO_Pin = KEY2_INT_GPIO_PIN;//PC13
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
//	
//	GPIO_Init(KEY2_INT_GPIO_PORT,&GPIO_InitStruct);//�˿�����д��Ĵ���
//	
//	//��ʼ��EXTI
//	/*��AFIO��ʱ��-EXTI��ʱ��*/
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
//	/*����������*/
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
//	
//	/*����EXTI��ʼ���ṹ��*/
//	EXTI_InitStruct.EXTI_Line = EXTI_Line0;//������0
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//�ж�ģʽ
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//�����ش���
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;//������ʹ��
//	
//	EXTI_Init(&EXTI_InitStruct);//EXTI��ʼ������д��Ĵ���
//}

/*�ж����ȼ����ú��� static��ʾ�˺������ڲ�����ֻ��������ļ��б�����*/
static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//�ж����ȼ��������ú���
	/*����KEY1*/
	NVIC_InitStruct.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;//�����ж�Դ
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//������ռ���ȼ�Ϊ:1 ����ж�ʱ���ȱȽ���ռ���ȼ��ٱȽ������ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;//���������ȼ�Ϊ:1
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//ʹ���ж�ͨ��
	
	NVIC_Init(&NVIC_InitStruct);//NVIC����д��Ĵ���
	
	/*����KEY2*/
	NVIC_InitStruct.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;//�����ж�Դ
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//������ռ���ȼ�Ϊ:1 ����ж�ʱ���ȱȽ���ռ���ȼ��ٱȽ������ȼ�
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;//���������ȼ�Ϊ:1
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//ʹ���ж�ͨ��
	
	NVIC_Init(&NVIC_InitStruct);//NVIC����д��Ĵ���
}
void EXTI_Key_Config(void)
{
	   
	  /*GPIO��ʼ���ṹ��*/
	GPIO_InitTypeDef GPIO_InitStruct;
	
		/*EXTI��ʼ���ṹ��*/
	EXTI_InitTypeDef EXTI_InitStruct;
	
	/*�����ж����ȼ�*/
	EXTI_NVIC_Config();
	
	
	/*��ʼ��GPIO*/
		/*��GPIOA��GPIOC��ʱ�Ӻʹ�AFIO��ʱ��-EXTI��ʱ��*/
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK|KEY2_INT_GPIO_CLK, ENABLE);//��ʱ��
	
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;//PA0
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������

	GPIO_Init(KEY1_INT_GPIO_PORT,&GPIO_InitStruct);//�˿�����д��Ĵ���
	
	GPIO_InitStruct.GPIO_Pin = KEY2_INT_GPIO_PIN;//PC13
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	
	GPIO_Init(KEY2_INT_GPIO_PORT,&GPIO_InitStruct);//�˿�����д��Ĵ���
	
	/*��ʼ��EXTI*/
	/*��AFIO��ʱ��-EXTI��ʱ��*/
	/*�����Ѿ�ʵ��*/
	/*����������*/
	GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE);
	
	/*����EXTI��ʼ���ṹ��*/
	EXTI_InitStruct.EXTI_Line = KEY1_INT_EXTI_LINE;//������0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//�����ش���
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;//������ʹ��
	
	EXTI_Init(&EXTI_InitStruct);//EXTI��ʼ������д��Ĵ���
	
	/*����������*/
	GPIO_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE, KEY2_INT_EXTI_PINSOURCE);
	
	/*����EXTI��ʼ���ṹ��*/
	EXTI_InitStruct.EXTI_Line = KEY2_INT_EXTI_LINE;//������13
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//�����ش���
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;//������ʹ��
	
	EXTI_Init(&EXTI_InitStruct);//EXTI��ʼ������д��Ĵ���
	
	
}

