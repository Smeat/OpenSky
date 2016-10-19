#ifndef __HAL_IO_H__
#define __HAL_IO_H__
#include <stdint.h>

void hal_io_init(void);
uint8_t hal_io_bind_request(void);

void hal_io_csn_lo();
void hal_io_csn_hi();
void hal_io_wait_miso_low();
uint8_t hal_io_get_gdo();

#endif // __HAL_IO_H__
