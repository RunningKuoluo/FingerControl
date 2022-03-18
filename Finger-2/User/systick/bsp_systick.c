#include "bsp_systick.h"


#if 0
/*inline 定义的类的 内联函数，函数的代码被放入 符号表中，在使用时直接进行替换，（像宏一样展开），没有了调用的开销，效率也很高。*/
/*ticks倒计时的值，当ticks=72时为us计时，当ticks=72000时为ms计时*/
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
	/*判断tick的值是否大于2^24 如果大于则不符合规则*/
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
   
  /*初始化reload寄存器的值*/	
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
	/*配置中断优先级，配置为15，为最低的优先级 2^4-1=15*/	
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M3 System Interrupts */
	
	/*初始化counter的值为0*/
  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
	
	/*配置systick的时钟为72M*/
	/*使能中断*/
	/*使能systick*/
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}

#endif

/*微秒延时函数*/
void SysTick_Delay_us(uint32_t us)
{
	uint32_t i;
	/*ticks=72  us计时*/
	SysTick_Config(72);
	
	for(i=0;i<us;i++)
	{
		/*当counter从reload值往下递减到0的时候，CTRL寄存器的位16：countflag会置1，且读取该位的值可清0*/
		/*下面代码的意思是如果countflag不置1就一直等待在这里，实现延时*/
		while(!((SysTick->CTRL) & (1<<16)));
	}
	/*清0 关闭 SysTick 定时器*/
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}


/*毫秒延时函数*/
void SysTick_Delay_ms(uint32_t ms)
{
	uint32_t i;
	/*ticks=72000  ms计时*/
	SysTick_Config(72000);
	
	for(i=0;i<ms;i++)
	{
		/*当counter从reload值往下递减到0的时候，CTRL寄存器的位16：countflag会置1，且读取该位的值可清0*/
		/*下面代码的意思是如果countflag不置1就一直等待在这里，实现延时*/
		while(!((SysTick->CTRL) & (1<<16)));
	}
	/*清0 关闭 SysTick 定时器*/
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}


