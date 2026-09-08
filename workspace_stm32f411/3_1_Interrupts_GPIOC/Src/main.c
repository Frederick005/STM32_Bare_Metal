#include "stdio.h"
#include "stm32f4xx.h"
#include "stdint.h"
#include "exti.h"
#include "uart.h"

static void exti13_callback (void);

int main()
{

	// Initializing UART
	uart_tx_rx_init();

	// Initializing the user led pin
	RCC->AHB1ENR |= (1U<<0);
	GPIOA->MODER = (GPIOA->MODER & ~(3U<<10))|(1U<<10);

	// Initializing the PC13 pin as an interrupt pin
	// NOTE: Try to enable the interrupts only after the
	// peripherals and required by the ISR have been initialized,
	// so that the interrupt cannot arrive before the system
	// is ready to handle it.
	exti_pc13_init();

	while (1)
	{
	}

}

static void exti13_callback(void)
{
	printf("BTN pressed \n\r");
	GPIOA->ODR ^= (1U<<5);
}

void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR & EXTI_LINE_13) != 0)
		{
			// Clear the pr flag
			EXTI->PR |= EXTI_LINE_13;

			// execute this funcion
			exti13_callback();
		}
}

