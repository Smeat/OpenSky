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

#include "hal_cc25xx.h"

void hal_cc25xx_init(void) {
}

void hal_cc25xx_set_register(uint8_t reg, uint8_t val) {
}

uint8_t hal_cc25xx_get_register(uint8_t address) {
}

void hal_cc25xx_strobe(uint8_t val) {
}

void hal_cc25xx_enable_receive(void) {
}

void hal_cc25xx_enable_transmit(void) {
}

void hal_cc25xx_enter_rxmode(void) {
}

void hal_cc25xx_enter_txmode(void) {
}


uint8_t hal_cc25xx_get_status(void) {
}

uint32_t hal_cc25xx_set_antenna(uint8_t id) {
}

void hal_cc25xx_set_gdo_mode(void) {
}

uint8_t hal_cc25xx_get_gdo_status(void) {
}

void hal_cc25xx_process_packet(volatile uint8_t *packet_received, volatile uint8_t *buffer, uint8_t maxlen) {
}

void hal_cc25xx_transmit_packet(volatile uint8_t *buffer, uint8_t len) {
}

void hal_cc25xx_read_fifo(uint8_t *buf, uint8_t len) {
}

void hal_cc25xx_register_read_multi(uint8_t address, uint8_t *buffer, uint8_t len) {
}

uint8_t hal_cc25xx_transmission_completed(void) {
}

