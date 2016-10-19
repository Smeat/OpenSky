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

#include "hal_io.h"
#include "config.h"
#include <avr/io.h>
#include <avr/interrupt.h>


#define DD_MOSI MOSI
#define DD_MISO MISO
#define DD_SCK  SCK

#define DD_GDO D9
#define DD_SS D10

void hal_io_init(void) {
  /* Set MOSI and SCK output, all others input */
  DDRB = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS)|(1<<0);
  
  /* PUT SS HI */
  hal_io_csn_hi();

  /* Test GDO PIN
  while(1) {
    if (hal_io_get_gdo())
      debug("1\n");
    else
      debug("0\n");
    delay_ms(100);
  }
  */
}

void hal_io_csn_lo() {
  PORTB &= ~ 1 << DDB2;
}

void hal_io_csn_hi() {
  PORTB |= 1 << DDB2;
}

void hal_io_wait_miso_low() {
  while((PINB & 1 << DD_MISO) != 0){}
}

uint8_t hal_io_get_gdo() {
  return (PINB & 1 << DD_GDO) != 0;
}

uint8_t hal_io_bind_request(void) {
  return 1;
}

