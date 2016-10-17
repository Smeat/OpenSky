/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

   author: fishpepper <AT> gmail.com, jimmyw <AT> github
*/

#include "hal_timeout.h"

#include "debug.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static uint32_t timer_1 = 0;
static uint32_t timer_2 = 0;


/*
 *  CS22     CS21    CS20    DESCRIPTION
 *  0        0       0       Timer/Counter2 Disabled
 *  0        0       1       No Prescaling
 *  0        1       0       Clock / 8
 *  0        1       1       Clock / 32
 *  1        0       0       Clock / 64
 *  1        0       1       Clock / 128
 *  1        1       0       Clock / 256
 *  1        1       1       Clock / 1024
 */

void hal_timeout_init(void) {

    //CTC mode
    TCCR0A = (1<<WGM21);
    TCCR0B  = (0 << CS22) | (1 << CS21) | (1 << CS20); // Clock / 32

    //set up overflow every 1.0ms.
    OCR0A   = F_CPU/32L/1000L/2L;
    hal_timeout_set(0);

#ifdef TEST
    debug("timer test\n");
    DDRB = (1<<0) | (1<<1);
    sei();
    while(1){
        hal_timeout_set(1); // 1ms
        PORTB &= ~ (1 << 0);
        while(timer_1 > 0){
        }
        PORTB |= (1 << 0);
        hal_timeout_set(10); // 10ms
        PORTB &= ~ (1 << 0);
        while(timer_1 > 0){
        }
        PORTB |= (1 << 0);
    }
#endif
}

static volatile c = 0;
ISR(TIMER0_COMPA_vect, ISR_NAKED){
  if (c) {
    PORTB &= ~ (1 << 1);
    c = 0;
  } else {
    PORTB |= (1 << 1);
    c = 1;
  }

    if (timer_1 > 0)
      timer_1--;
    if (timer_2 > 0)
      timer_2--;

    // Disable interrupt.
    if (timer_1 == 0) {
      TIMSK0 &= ~(1 << OCIE2A);
    }

    reti();
}

void hal_timeout_set(__IO uint32_t ms) {
    //debug("timeout1 set "); debug_put_hex32(ms); debug_put_newline();
    //disable OVF interrupts:
    TIMSK0 &= ~(1 << OCIE2A);

    //clear counter
    TCNT0 = 0;

    //clear pending ints
    TIFR0 |= (1<<OCF2A);

    //prepare timeout val
    timer_1 = ms;

    if (timer_1 == 0){
        return;
    }

    //clear pending ints
    TIFR0 |= (1<<OCF2A);

    //re enable interrupts
    TIMSK0 |= (1 << OCIE2A);
}

void hal_timeout2_set(__IO uint32_t ms) {
    debug("timeout2 set "); debug_put_uint8(ms); debug_put_newline();

    //disable OVF interrupts:
    TIMSK2 &= ~(1 << OCIE2A);

    //clear counter
    TCNT2 = 0;

    //clear pending ints
    TIFR2 |= (1<<OCF2A);

    //prepare timeout val:
    timer_2 = ms;

    if (timer_2 == 0){
        return;
    }

    //clear pending ints
    TIFR2 |= (1<<OCF2A);

    //re enable interrupts
    TIMSK2 |= (1 << OCIE2A);
}

uint8_t hal_timeout_timed_out(void) {
  return timer_1 == 0;
}

uint8_t hal_timeout2_timed_out(void) {
  return timer_2 == 0;
}

