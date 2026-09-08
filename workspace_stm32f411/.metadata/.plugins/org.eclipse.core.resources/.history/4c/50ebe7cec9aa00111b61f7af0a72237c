#include "uart.h"

#define PERIPH_CLK        16000000
#define BAUDRATE          115200
#define USART2_OVER8_EN   (1U<<15)
#define USART2_APB1_EN    (1U<<17)
#define USART2_GPIOA_EN   (1U<<0)
#define USART2_PA2_MODER  (1U<<5)
#define USART2_PA3_MODER  (1U<<7)
#define USART2_TX_EN      (1U<<3)
#define USART2_RX_EN      (1U<<2)
#define USART2_EN         (1U<<13)


static void set_baud_rate(USART_TypeDef * USARTx, uint32_t periph_clk, uint32_t baudrate);
static uint16_t calculate_baud_rate(uint32_t periph_clk, uint32_t baudrate);


void uart_write(int ch);

int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}

void uart_tx_rx_init(void)
{
	// Initializing and enabling the USART2

	// Enabling clock for USART
	RCC->APB1ENR |= USART2_APB1_EN;

	// Enable clock for GPIOA
	RCC->AHB1ENR |= USART2_GPIOA_EN;

	// Set the mode of the GPIOA pin 2 and 3
	// For USART TX pin 2
	GPIOA->MODER = (GPIOA->MODER & ~(3U<<4)) | USART2_PA2_MODER;

	// For USART RX pin 3
	GPIOA->MODER = (GPIOA->MODER & ~(3U<<6)) | USART2_PA3_MODER;

	// Set up the alternate function which was af07 which is "111"
		// each pin uses 4 bits and are number afrl0....afrl7
		// i.e All pin 0s use afrl0 and so on.
		// For pins beyond 7, the afrh registers need to be accessed.

	GPIOA->AFR[0] &= ~(15U<<8);
	GPIOA->AFR[0] |= ((1U<<8)|(1U<<9)|(1U<<10));

	// Setting the alternate function for the GPIOA PA3
	GPIOA->AFR[0] &= ~(15U<<12);
	GPIOA->AFR[0] |= (1U<<12)|(1U<<13)|(1U<<14);

	// Clear USART2 Control registers to prevent errors
	USART2->CR1 = 0x00000000;
	USART2->CR2 = 0x00000000;
	USART2->CR3 = 0x00000000;

	// Enable Tx and Rx direction in USART2.
	USART2->CR1 |= (USART2_TX_EN | USART2_RX_EN);

	// Set oversampling to 8
	USART2->CR1 |= USART2_OVER8_EN;

	// Set the Baudrate
	set_baud_rate (USART2, PERIPH_CLK, BAUDRATE);

	// Enabling USART2
	USART2->CR1 |= USART2_EN;
}

char uart_read(void)
{
	while ((USART2->SR & (1U<<5))== 0){}

	return USART2->DR;
}

void uart_write(int ch)
{
	while((USART2->SR & (1U<<7))==0){}

	//Filling values in the data register.
	USART2->DR = (ch & 0xFF);
}

static void set_baud_rate(USART_TypeDef * USARTx, uint32_t periph_clk, uint32_t baudrate)
{
	// We need to calculate the baudrate for both oversampling frequencies

	if ((USARTx->CR1 & (USART2_OVER8_EN))==0)
	{
		USARTx->BRR = calculate_baud_rate(periph_clk, baudrate);
	}
	else
	{
		uint32_t intermediate_baudrate = calculate_baud_rate(periph_clk, baudrate);

		// because we are oversampling by 8 hence division has to be by 8 i.e 3 bits
		uint32_t mantissa = intermediate_baudrate >> 3;

		// Calculate the fraction part
		uint32_t fraction = intermediate_baudrate & (7U);

		// Finally assigning the baudrate to the BRR register
		USARTx->BRR = (mantissa<<4) | fraction;

		// Note that the mantissa is being shifted by 4 to accomodate the
		// 3rd bit which has to be assigned as 0
	}
}

static uint16_t calculate_baud_rate(uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate / 2U))/baudrate);
}
