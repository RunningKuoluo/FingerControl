#include  "stm32f10x.h"  //相当于51单片机中的   #include <reg51.h>//<>是去系统的安装目录里找//""是去当前工程目录里找，如果找不到再去keil的根目录里找
#include  "bsp_led.h"
#include  "bsp_key.h"
#include  "bsp_exti.h"
#include  "bsp_systick.h"
#include  "bsp_usart.h"

#define GPIOB_ODR_Addr                 (GPIOB_BASE+0x0C)
#define PBout(n)       *(unsigned int*)((GPIOB_ODR_Addr & 0xF0000000)+0x02000000+((GPIOB_ODR_Addr & 0x00FFFFFF)<<5)+(n<<2))
//带参宏定义//

#define GPIOA_IDR_Addr                 (GPIOA_BASE+0x08)
#define PAin(n)       *(unsigned int*)((GPIOA_IDR_Addr & 0xF0000000)+0x02000000+((GPIOA_IDR_Addr & 0x00FFFFFF)<<5)+(n<<2))
//带参宏定义//

#define GPIOC_IDR_Addr                 (GPIOC_BASE+0x08)
#define PCin(n)       *(unsigned int*)((GPIOC_IDR_Addr & 0xF0000000)+0x02000000+((GPIOC_IDR_Addr & 0x00FFFFFF)<<5)+(n<<2))


uint8_t KEY_Select;

int main(void)
{
 //来到这里的时候，系统的时钟已经被配置成72M。
	
	uint8_t SendBuffer[15]={0x55,0xAA,0x0A,0xFF,0xF2,0x01,0x00,0x00,0x02,0x14,0x00,0x03,0x00,0x00,0x00};
	uint8_t i,sum=0;
	//uint8_t SendBuffer1[9]={0x55,0xAA,0x04,0x01,0x03,0x37,0x14,0x05,0x58};
	
	/*串口初始化配置*/
	USART_Config();
	
	/*外部中断按键初始化配置*/
	EXTI_Key_Config();
	

//	Usart_SendArray(DEBUG_USARTx,SendBuffer,9);
	
	while(1)
	{
      switch (KEY_Select)
        {
          case 0:
            SendBuffer[6] = 0xE8;
            SendBuffer[7] = 0x03;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x05;

            SendBuffer[12] = 0xE8;
            SendBuffer[13] = 0x03;
            break;
           case 1:
            SendBuffer[6] = 0xE8;
            SendBuffer[7] = 0x02;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x05;

            SendBuffer[12] = 0xE8;
            SendBuffer[13] = 0x03;
            break;
          case 2:
            SendBuffer[6] = 0xE8;
            SendBuffer[7] = 0x03;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x05;

            SendBuffer[12] = 0x58;
            SendBuffer[13] = 0x02;
            break;
          case 3:
            SendBuffer[6] = 0xE8;
            SendBuffer[7] = 0x03;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x00;

            SendBuffer[12] = 0xE8;
            SendBuffer[13] = 0x03;
            break;

          case 4:
            SendBuffer[6] = 0x00;
            SendBuffer[7] = 0x00;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x05;

            SendBuffer[12] = 0x00;
            SendBuffer[13] = 0x00;
            break;

          case 5:
            SendBuffer[6] = 0x00;
            SendBuffer[7] = 0x00;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x03;

            SendBuffer[12] = 0x00;
            SendBuffer[13] = 0x00;
            break;

          case 6:
            SendBuffer[6] = 0x00;
            SendBuffer[7] = 0x00;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x05;

            SendBuffer[12] = 0x00;
            SendBuffer[13] = 0x00;
            break;

          default:
            SendBuffer[6] = 0xE8;
            SendBuffer[7] = 0x03;

            SendBuffer[9] = 0x14;
            SendBuffer[10] = 0x05;

            SendBuffer[12] = 0xE8;
            SendBuffer[13] = 0x03;
            break;
        }
		
			for(i=2;i<14;i++)
		{
			sum=sum+SendBuffer[i];
		}
		SendBuffer[14]=sum;
		sum=0;
		SysTick_Delay_ms(20);
		Usart_SendArray(DEBUG_USARTx,SendBuffer,15);
//		SysTick_Delay_ms(100);
	}

	
}


