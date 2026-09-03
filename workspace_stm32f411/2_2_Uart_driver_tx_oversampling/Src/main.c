#include "stdio.h"
#include "stm32f4xx.h"
#include "stdint.h"
#include "uart.h"

int main()
{
	uart_tx_init();

	while (1)
	{
		printf("Hello you fine people!!\n");
	}

}



