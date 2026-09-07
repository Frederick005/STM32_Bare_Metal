/*
 * uart.h
 *
 *  Created on: Aug 12, 2026
 *      Author: anany
 */

#ifndef UART_H_
#define UART_H_
#include "stm32f4xx.h"
#include "stdint.h"

void uart_tx_init(void);
void uart_rx_init(void);
void uart_tx_rx_init(void);
char uart_read(void);

#endif /* UART_H_ */
