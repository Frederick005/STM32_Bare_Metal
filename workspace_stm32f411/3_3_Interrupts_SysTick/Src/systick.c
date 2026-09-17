#include <systick.h>

/* We are using the internal clock whose frequency is approx
 * 16Mhz i.e., 16000000 ticks per second. approx 1ms (1/1000)
 * then will have 16000 ticks.
 * Hence that's what will be fed to the SYSTICK RELOAD register
*/
#define SYSTICK_DELAY_1MS        16000

#define SYSTICK_EN               (1U<<0)
#define SYSTICK_CLK	             (1U<<2)
#define SYSTICK_COUNT_FLAG       (1U<<16)
#define SYSTICK_INTERRUPT_EN     (1U<<1)


void systick_init(void)
{
	// Clearing the control register.
	SysTick->CTRL = 0U;

	// Adding the Reload value to the Systick reload register
	SysTick->LOAD = SYSTICK_DELAY_1MS - 1;

	//Clearing the counter register
	SysTick->VAL = 0U;

	/*NVIC_EnableIRQ() is for external/device IRQs;
	 * SysTick has its own exception-enable mechanism through
	 * TICKINT.
	 * And NVIC_SetPriority() is still relevant because
	 * SysTick's priority is configurable even though
	 * it isn't an external IRQ.*/

	// NVIC_EnableIRQ(SysTick_IRQn);

	// Enabling the interrupt in NVIC and giving it the lowest priority
	NVIC_SetPriority(SysTick_IRQn, ((1U << __NVIC_PRIO_BITS) - 1U));

	//Enabling the clock and the Systick enable.
	SysTick->CTRL |= SYSTICK_CLK | SYSTICK_INTERRUPT_EN | SYSTICK_EN;
}


void systick_delay (uint32_t delay)
{
	/* So the delay variable tells us how many ms the user
	* wants the delay for. and we know that the setting
	* is such that each time the counter reaches 0 it
	* signals 1ms hence setting a for loop for the delay
	* gives is the proper wait time */

	for (uint32_t i = 0; i < delay; i++)
	{
		while ((SysTick->CTRL & SYSTICK_COUNT_FLAG) == 0){}
	}
}
