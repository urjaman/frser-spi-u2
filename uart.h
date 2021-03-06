/*
 * This file is part of the frser-duino project.
 *
 * Copyright (C) 2010,2011 Urja Rannikko <urjaman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

uint8_t uart_recv(void);
void uart_send(uint8_t val);
void uart_wait_txdone(void);

/* These can be used to go behind the scenes with the USB "uart". */
uint8_t uart_isdata(void);
uint8_t uart_send_getfree(void);
void uart_recv_ctrl_cnt(uint8_t b);
void uart_send_ctrl_cnt(uint8_t b);



#define RECEIVE() uart_recv()
#define SEND(n) uart_send(n)
#define UART_BUFLEN 1024
#define UART_POLLED_TX
#define UARTTX_BUFLEN 0
/* Fake, roughly USB 1.1 bandwidth. */
#define BAUD 8000000
