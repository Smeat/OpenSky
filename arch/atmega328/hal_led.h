#ifndef __HAL_LED__H_
#define __HAL_LED__H_
#include "config.h"
#include <stdint.h>
#include <avr/io.h>

void hal_led_init(uint16_t pin);

#define GREEN_LED_BIT _BV(PC2)
#define RED_LED_BIT _BV(PC2)

#define hal_led_green_init() { }
#define hal_led_green_on()  { PORTC |= GREEN_LED_BIT; }
#define hal_led_green_off()  { PORTC &= ~ GREEN_LED_BIT; }
#define hal_led_green_toggle() { PORTC ^= GREEN_LED_BIT; }

#define hal_led_red_init() { }
#define hal_led_red_on()   { PORTC |= RED_LED_BIT; }
#define hal_led_red_off()  { PORTC &= ~ RED_LED_BIT; }
#define hal_led_red_toggle() { PORTC ^= RED_LED_BIT; }

#endif //__HAL_LED__H_

