#ifndef __HAL_DELAY_H__
#define __HAL_DELAY_H__
#include "hal_timeout.h"

#define hal_delay_ms(ms) hal_timeout_delay_ms(ms)
void hal_delay_us(uint32_t us);

#endif // __HAL_DELAY_H__
