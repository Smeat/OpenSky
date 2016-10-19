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

#include "hal_spi.h"
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(SPI_STC_vect){
}

void hal_spi_init(void) {
  /* Enable SPI, Master, set clock rate fck/16 */
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

uint8_t hal_spi_tx(uint8_t address) {

  /* Send byte */
  SPDR = address;

  /* Wait for transmission complete */
  while(!(SPSR & (1<<SPIF))) {}

  /* Return byte */
  uint8_t r = SPDR;
  //debug("hal_spi_tx sent: 0x"); debug_put_hex8(address); debug(" got: 0x"); debug_put_hex8(r); debug("\n"); debug_flush();
  return r;
}

uint8_t hal_spi_rx(void) {
  return hal_spi_tx(0xff);
}

