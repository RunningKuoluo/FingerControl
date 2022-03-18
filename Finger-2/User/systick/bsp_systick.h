#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include "stm32f10x.h"

/*内核的头文件*/
#include "core_cm3.h"



/*微秒延时函数*/
void SysTick_Delay_us(uint32_t us);

/*毫秒延时函数*/
void SysTick_Delay_ms(uint32_t ms);

#endif /*__BSP_SYSTICK_H*/

