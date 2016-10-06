#ifndef __HAL_SPI__H_
#define __HAL_SPI__H_
#include <stdint.h>
#include "config.h"
#include "delay.h"

void hal_spi_init(void);

void hal_spi_dma_xfer(uint8_t *buffer, uint8_t len);
void hal_spi_csn_lo();
void hal_spi_csn_hi();
void hal_spi_wait_ready();
uint8_t hal_spi_get_gdo();
uint8_t hal_spi_tx(uint8_t address);
uint8_t hal_spi_rx(void);
uint8_t hal_spi_read_address(uint8_t address);

#endif // __HAL_SPI__H_

