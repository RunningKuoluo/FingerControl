#include "bsp_systick.h"


#if 0
/*inline �������� ���������������Ĵ��뱻���� ���ű��У���ʹ��ʱֱ�ӽ����滻�������һ��չ������û���˵��õĿ�����Ч��Ҳ�ܸߡ�*/
/*ticks����ʱ��ֵ����ticks=72ʱΪus��ʱ����ticks=72000ʱΪms��ʱ*/
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
	/*�ж�tick��ֵ�Ƿ����2^24 ��������򲻷��Ϲ���*/
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
   
  /*��ʼ��reload�Ĵ�����ֵ*/	
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
	/*�����ж����ȼ�������Ϊ15��Ϊ��͵����ȼ� 2^4-1=15*/	
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M3 System Interrupts */
	
	/*��ʼ��counter��ֵΪ0*/
  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
	
	/*����systick��ʱ��Ϊ72M*/
	/*ʹ���ж�*/
	/*ʹ��systick*/
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}

#endif

/*΢����ʱ����*/
void SysTick_Delay_us(uint32_t us)
{
	uint32_t i;
	/*ticks=72  us��ʱ*/
	SysTick_Config(72);
	
	for(i=0;i<us;i++)
	{
		/*��counter��reloadֵ���µݼ���0��ʱ��CTRL�Ĵ�����λ16��countflag����1���Ҷ�ȡ��λ��ֵ����0*/
		/*����������˼�����countflag����1��һֱ�ȴ������ʵ����ʱ*/
		while(!((SysTick->CTRL) & (1<<16)));
	}
	/*��0 �ر� SysTick ��ʱ��*/
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}


/*������ʱ����*/
void SysTick_Delay_ms(uint32_t ms)
{
	uint32_t i;
	/*ticks=72000  ms��ʱ*/
	SysTick_Config(72000);
	
	for(i=0;i<ms;i++)
	{
		/*��counter��reloadֵ���µݼ���0��ʱ��CTRL�Ĵ�����λ16��countflag����1���Ҷ�ȡ��λ��ֵ����0*/
		/*����������˼�����countflag����1��һֱ�ȴ������ʵ����ʱ*/
		while(!((SysTick->CTRL) & (1<<16)));
	}
	/*��0 �ر� SysTick ��ʱ��*/
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}


