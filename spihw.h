/* Define what our hardware is. */
#include "spihw_avrspi.h"

/* These work for all the xU2/U4 */
#define SPI_PORT	PORTB
#define SCK		PORTB1
#define MISO		PORTB3
#define MOSI 		PORTB2
#define SS		PORTB0
#define DDR_SPI		DDRB

/* But the CS needs to change between an R3s U2 and a pro micro ... */

#if (defined __AVR_ATmega8U2__) || (defined __AVR_ATmega16U2__ ) || (defined __AVR_ATmega32U2__)

/* *U2 on an arduino R3 with open collector CS like in my SPI shield. */
#define spi_select() do { DDR_SPI |=_BV(4); } while(0)
#define spi_deselect() do { DDR_SPI &= ~_BV(4); _delay_us(1); } while(0)

#elif (defined __AVR_ATmega16U4__) || (defined __AVR_ATmega32U4__)

/* Arduino Pro Micro. PB6 aka D10 used as ext. CS */
#define SPI_CS PB6

#define spi_select() do { SPI_PORT &= ~_BV(SPI_CS); } while(0)
#define spi_deselect() do { SPI_PORT |= _BV(SPI_CS); } while(0)


#else
#error define your SPI hw
/* Also check spihw.c */

#endif