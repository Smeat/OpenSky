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

void hal_timeout_init(void) {
}

void hal_timeout_set_100us(__IO uint32_t hus) {
}

void hal_timeout2_set_100us(__IO uint32_t hus) {
}

void hal_timeout_set(__IO uint32_t ms){
}

uint8_t hal_timeout_timed_out(void) {
}

uint8_t hal_timeout2_timed_out(void) {
}

void hal_timeout_delay_ms(uint32_t timeout){
}

void SysTick_Handler(void){
}

uint32_t hal_timeout_time_remaining(void) {
    return 0;
}
