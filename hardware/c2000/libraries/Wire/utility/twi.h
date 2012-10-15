/*
  ************************************************************************
  *	twi.h
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  twi.h - TWI/I2C library for Wiring & Arduino
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef twi_h
#define twi_h

#include <msp430.h>

#ifndef __MSP430_HAS_USI__
#error "********** USI not available"
#endif

#include <inttypes.h>

#ifndef TWI_FREQ
#define TWI_FREQ 100000L
#endif

#ifndef TWI_BUFFER_LENGTH
#define TWI_BUFFER_LENGTH 16
#endif

#define TWI_SND_START 0
#define TWI_PREP_SLA_ADDR_ACK 1
#define TWI_MT_PROC_ADDR_ACK 2
#define TWI_MT_PREP_DATA_ACK 3
#define TWI_MT_PROC_DATA_ACK 4
#define TWI_MR_PREP_DATA_RECV 5
#define TWI_MR_PROC_DATA_RECV 6
#define TWI_MR_PREP_STOP 7
#define TWI_EXIT 8
#define TWI_IDLE 9

#define TWI_ERRROR_NO_ERROR 0
#define TWI_ERROR_BUF_TO_LONG 1
#define TWI_ERROR_ADDR_NACK 2
#define TWI_ERROR_DATA_NACK 3
#define TWI_ERROR_OTHER 4



void twi_init(void);
void twi_setAddress(uint8_t);
uint8_t twi_readFrom(uint8_t, uint8_t*, uint8_t);
uint8_t twi_writeTo(uint8_t, uint8_t*, uint8_t, uint8_t);
uint8_t twi_transmit(const uint8_t*, uint8_t);
void twi_attachSlaveRxEvent( void (*)(uint8_t*, int) );
void twi_attachSlaveTxEvent( void (*)(void) );
void twi_reply(uint8_t);
void twi_stop(void);
void twi_releaseBus(void);

#endif

