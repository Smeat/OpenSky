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

#include <avr/io.h>
#include <avr/interrupt.h>

/*
 *  CS22     CS21    CS20    DESCRIPTION
 *  0        0       0       Timer/Counter2 Disabled
 *  0        0       1       No Prescaling
 *  0        1       0       Clock / 8
 *  0        1       1       Clock / 32
 *  1        0       0       Clock / 64  <---  choosen
 *  1        0       1       Clock / 128
 *  1        1       0       Clock / 256
 *  1        1       1       Clock / 1024
 */

void hal_timeout_init(void) {
    TCCR2B = 1 << CS22; // Use 64ticks prescaler.
    TCCR2A = 1 << WGM21; // Clear Timer on Compare.
    OCR2A   = (F_CPU/64L/1000L)-1; // Divide clock speed, with 64ticks, and transform to us.
    TIFR2 |= (1<<OCF2A); // Clear pending interrupts.
    TIMSK2 |= (1 << OCIE2A); // Enable interrupt.
}

static uint32_t timer_1 = 0;
static uint32_t timer_2 = 0;

ISR(TIMER2_COMPA_vect){
    if (timer_1 > 0)
      timer_1--;
    if (timer_2 > 0)
      timer_2--;
}

void hal_timeout_set_100us(__IO uint32_t hus) {
    timer_1 = hus * 100;
}

void hal_timeout2_set_100us(__IO uint32_t hus) {
    timer_2 = hus * 100;
}

void hal_timeout_set(__IO uint32_t ms){
    timer_1 = ms * 1000;
}

uint8_t hal_timeout_timed_out(void) {
  return timer_1 == 0;
}

uint8_t hal_timeout2_timed_out(void) {
  return timer_2 == 0;
}

