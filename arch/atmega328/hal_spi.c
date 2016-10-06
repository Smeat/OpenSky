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


#define DDR_SPI DDRB
#define DD_MISO PB4
#define DD_MOSI PB3
#define DD_SCK PB5
#define DD_SS PB2

ISR(SPI_STC_vect){
}

void hal_spi_init(void) {
  /* Set MOSI and SCK output, all others input */
  DDRB = (1<<DD_MOSI)|(1<<DD_SCK);
  /* Enable SPI, Master, set clock rate fck/16 */
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}


void hal_spi_dma_xfer(uint8_t *buffer, uint8_t len) {
}

uint8_t hal_spi_tx(uint8_t address) {
  /* Wait for transmission complete */
  while(!(SPSR & (1<<SPIF))) {}

  /* Send byte */
  SPDR = address;

  /* Wait for transmission complete */
  while(!(SPSR & (1<<SPIF))) {}

  /* Return byte */
  return SPDR;
}

uint8_t hal_spi_rx(void) {
  return hal_spi_tx(0xff);
}

uint8_t hal_spi_read_address(uint8_t address) {
  return 0;
}

