#ifndef __HAL_UART__H_
#define __HAL_UART__H_
#include "config.h"
#include "hal_uart.h"
#include <stdint.h>

extern volatile uint8_t hal_usart_txe_is_on;

void hal_uart_init(void);
void hal_uart_start_transmission(uint8_t ch);

#define hal_uart_int_enable()  { }
#define hal_uart_int_disable()  { }

uint8_t hal_uart_int_enabled(void);

void hal_uart_init_nvic(uint8_t enable);

#define DEBUG_ISR(void) DEBUG_USART_IRQHANDLER(void)
#define HAL_UART_ISR_FLAG_SET() (1)
#define HAL_UART_ISR_CLEAR_FLAG() { }
#define HAL_UART_ISR_DISABLE() { }
#define HAL_UART_TX_DATA(data) { }


#endif // __HAL_UART__H_
