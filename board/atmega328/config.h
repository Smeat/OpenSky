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

#define USART_BAUDRATE 115200

/* Map arduino pin names to atmega ports */

#define A0_PIN      DDC0
#define A1_PIN      DDC1
#define A2_PIN      DDC2
#define A3_PIN      DDC3
#define A0_PORT      PORTC
#define A1_PORT      PORTC
#define A2_PORT      PORTC
#define A3_PORT      PORTC
#define A0_INP      PINC
#define A1_INP      PINC
#define A2_INP      PINC
#define A3_INP      PINC

#define RXI_PIN     DDD0
#define TX0_PIN     DDD1
#define D2_PIN      DDD2
#define D3_PIN      DDD3
#define D4_PIN      DDD4
#define D5_PIN      DDD5
#define D6_PIN      DDD6
#define D7_PIN      DDD7
#define RXI_PORT     PORTD
#define TX0_PORT     PORTD
#define D2_PORT      PORTD
#define D3_PORT      PORTD
#define D4_PORT      PORTD
#define D5_PORT      PORTD
#define D6_PORT      PORTD
#define D7_PORT      PORTD
#define RXI_INP     PIND
#define TX0_INP     PIND
#define D2_INP      PIND
#define D3_INP      PIND
#define D4_INP      PIND
#define D5_INP      PIND
#define D6_INP      PIND
#define D7_INP      PIND

#define D8_PIN      DDB0
#define D9_PIN      DDB1
#define D10_PIN     DDB2
#define MOSI_PIN    DDB3
#define MISO_PIN    DDB4
#define SCK_PIN     DDB5

#define D8_PORT      PORTB
#define D9_PORT      PORTB
#define D10_PORT     PORTB
#define MOSI_PORT    PORTB
#define MISO_PORT    PORTB
#define SCK_PORT     PORTB

#define D8_INP      PINB
#define D9_INP      PINB
#define D10_INP     PINB
#define MOSI_INP    PINB
#define MISO_INP    PINB
#define SCK_INP     PINB

/* MAP Arduino pins to functions */


#define DD_MOSI_PIN MOSI_PIN
#define DD_MOSI_PORT MOSI_PORT
#define DD_MISO_PIN MISO_PIN
#define DD_MISO_INP MISO_INP
#define DD_SCK_PIN  SCK_PIN
#define DD_SCK_PORT  SCK_PORT

#define DD_GDO_PIN D2_PIN
#define DD_GDO_INP D2_INP
#define DD_SS_PIN D10_PIN
#define DD_SS_PORT D10_PORT

#define PPM_PIN D9_PIN
#define PPM_PORT D9_PORT
#define BIND_PIN D3_PIN
#define BIND_INP D3_INP
#define DEBUG_PIN D4_PIN
#define DEBUG_PORT D4_PORT
#define DEBUG2_PIN D5_PIN
#define DEBUG2_PORT D5_PORT
#define PA_EN_PIN D6_PIN
#define PA_EN_PORT D6_PORT
#define LNA_EN_PIN D7_PIN
#define LNA_EN_PORT D7_PORT


#define DEFAULT_FSCAL_VALUE 0
