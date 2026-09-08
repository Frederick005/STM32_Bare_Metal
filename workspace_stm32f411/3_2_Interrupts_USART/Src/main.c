#include "stdio.h"
#include "stm32f4xx.h"
#include "stdint.h"
#include "exti.h"
#include "uart.h"

#define USART2_SR_RXNE   (1U<<5)
char key;

int main()
{
	// Initializing the user led pin
	RCC->AHB1ENR |= (1U<<0);
	GPIOA->MODER = (GPIOA->MODER & ~(3U<<10))|(1U<<10);

	// Initializing UART
	uart_tx_rx_interrupt_init();

	while (1)
	{
	}

}

void USART2_IRQHandler(void)
{
	/* 1. The USART ISR is a single funnel shared by all events (RX, TX, Errors).
	 * 2. We must check the Status Register (SR) to verify exactly *why* it fired.
	 * 3. Without this, future TX or Error interrupts would falsely trigger this RX logic.
	 * 4. (Note: Reading the Data Register (DR) automatically clears the RXNE flag). */

	if (USART2->SR & USART2_SR_RXNE)
	{

		key = (char)USART2->DR;

		if (key=='1')
		{
			printf("USART2 Interrupt Generated\n\r");
			GPIOA->ODR |= (1U<<5);
		}
		else
		{
			GPIOA->ODR &= ~(1U<<5);
		}
	}
}

