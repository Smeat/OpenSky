#ifndef __HAL_UART__H_
#define __HAL_UART__H_
#include "config.h"
#include "hal_uart.h"
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void hal_uart_init(void);
void hal_uart_start_transmission(uint8_t ch);
void hal_uart_tx_data(uint8_t ch);

#define hal_uart_int_enable()  { }
#define hal_uart_int_disable()  { }

uint8_t hal_uart_int_enabled(void);
void hal_uart_interrupt(void);
uint8_t hal_uart_isr_is_set();

void hal_uart_isr_disable();
void hal_uart_isr_clear_flag(void);


#define DEBUG_ISR(void) hal_uart_interrupt(void)
#define HAL_UART_ISR_FLAG_SET() hal_uart_isr_is_set()
#define HAL_UART_ISR_CLEAR_FLAG() hal_uart_isr_clear_flag()
#define HAL_UART_ISR_DISABLE() hal_uart_isr_disable()
#define HAL_UART_TX_DATA(data) hal_uart_tx_data(data)


#endif // __HAL_UART__H_
