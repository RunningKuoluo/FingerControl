#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include "stm32f10x.h"

/*�ں˵�ͷ�ļ�*/
#include "core_cm3.h"



/*΢����ʱ����*/
void SysTick_Delay_us(uint32_t us);

/*������ʱ����*/
void SysTick_Delay_ms(uint32_t ms);

#endif /*__BSP_SYSTICK_H*/

