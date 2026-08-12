#include "stm32f4xx.h"

int main()
{
	RCC->AHB1ENR |= (1U<<0);
	RCC->AHB1ENR |= (1U<<2);
	GPIOA->MODER = (GPIOA->MODER & ~(3U<<10))|(1U<<10);
	GPIOC->MODER &= ~(3U<<26);

	while(1)
	{
		if ((GPIOC->IDR & (1U<<13)) == 0)
		{
			GPIOA->ODR |= (1U<<5);
		}
		GPIOA->ODR &= ~(1U<<5);
	}
	return 0;
}
