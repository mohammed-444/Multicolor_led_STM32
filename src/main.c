/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"

#include "gpio.h"


int main(void)
{

	//Enable clock to GBIOA
	 GPIO_Init (GPIOB,3,0,1);

	// Set Mode to output  in pin [0,1,2] and input in pin 3 GPIOA
	 GPIO_Init (GPIOB,0,1,1);
	 GPIO_Init (GPIOB,1,1,1);
	 GPIO_Init (GPIOB,2,1,1);

	// Set Mode to pull up  in pin 3 GPIOA
	GPIOB->PUPDR |=(1<<6);
	GPIOB->PUPDR  &= (~(1<<7));


	uint8_t arr[] = {0x00,0x01,0x02,0x04,0x03,0x05,0x06,0x07};
	int num = 1,flag = 1;

	// super loop
	while(1)
	{
		if((!GPIO_Read(GPIOB,3))){
			for (int var = 0; var < 50000; ++var) {}
				if(!GPIO_Read(GPIOB,3)){
					if(flag){
						GPIO_Write(GPIOB,0,arr[num]&(1<<0));
						GPIO_Write(GPIOB,1,arr[num]&(1<<1));
						GPIO_Write(GPIOB,2,arr[num]&(1<<2));

						num= (num>=7)? 0:(++num);
						flag=0;
						}
			}
			}else{flag=1;}
	}

}
