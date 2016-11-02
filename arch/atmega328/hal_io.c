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

#include <stdint.h>
#include "hal_io.h"
#include "config.h"
#include "delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>


void hal_io_init(void) {
  /* Set MOSI and SCK output, all others input */
  DDRB = 0;
  DDRC = 0;
  DDRD = 0;
  PPM_PORT |= (1<<PPM_PIN);
  DD_MOSI_PORT |= (1<<DD_MOSI_PIN);
  DD_SCK_PORT |= (1<<DD_SCK_PIN);
  DD_SS_PORT |= (1<<DD_SS_PIN);
  PA_EN_PORT |= (1<<PA_EN_PIN);
  LNA_EN_PORT |= (1<<LNA_EN_PIN);
  DEBUG_PORT |= (1<<DEBUG_PIN);
  DEBUG2_PORT |= (1<<DEBUG2_PIN);

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

void hal_io_set_ppm(uint8_t enable) {
  if (enable)
    PPM_PORT |= 1 << PPM_PIN;
  else
    PPM_PORT &= ~ (1 << PPM_PIN);
}

void hal_io_enable_pa(uint8_t enable) {
  if (enable)
    PA_EN_PORT |= 1 << PA_EN_PIN;
  else
    PA_EN_PORT &= ~ (1 << PA_EN_PIN);
}

void hal_io_enable_lna(uint8_t enable) {
  if (enable)
    LNA_EN_PORT |= 1 << LNA_EN_PIN;
  else
    LNA_EN_PORT &= ~ (1 << LNA_EN_PIN);
}

void hal_io_debug(uint8_t enable) {
  if (enable)
    DEBUG_PORT |= 1 << DEBUG_PIN;
  else
    DEBUG_PORT &= ~ (1 << DEBUG_PIN);
}

void hal_io_debug2(uint8_t enable) {
  if (enable)
    DEBUG2_PORT |= 1 << DEBUG2_PIN;
  else
    DEBUG2_PORT &= ~ (1 << DEBUG2_PIN);
}

void hal_io_csn_lo() {
  DD_SS_PORT &= ~ (1 << DD_SS_PIN);
}

void hal_io_csn_hi() {
  DD_SS_PORT |= 1 << DD_SS_PIN;
}

void hal_io_wait_miso_low() {
  while((DD_MISO_INP & 1 << DD_MISO_PIN) != 0){ /*debug("H");*/}
  /*debug("L");*/
}

uint8_t hal_io_get_gdo() {
  return (DD_GDO_INP & 1 << DD_GDO_PIN) != 0;
}

uint8_t hal_io_bind_request(void) {
  return (BIND_INP & 1 << BIND_PIN) != 0;
}

