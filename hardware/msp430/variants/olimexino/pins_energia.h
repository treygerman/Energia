/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: Rei VILO
  *
  ***********************************************************************
  Derived from:
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h
#ifndef BV
#define BV(x) (1 << (x))
#endif

// The USCI_B1 goes to the UEXT on the Olimexino board
#if defined(__MSP430_HAS_USCI_B1__)
static const uint8_t SS   = 20;  /* PJ.0 */
static const uint8_t SCK  = 13;  /* P4.3 */
static const uint8_t MOSI = 11;  /* P4.1 */
static const uint8_t MISO = 12;  /* P4.2 */
#endif

static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;

/* Layout of the Arduino compatible pin headers.

   All P1.x and P2.x pins support digitalWrite() and attachInterrupt()
   Pins marked with PWM support anaglogWrite()
   Pins marked with Ax support analogRead()

                                          +---\/---+
                                          |        |13  P4.3 (D13)       (SCK)
                                          |        |12  P4.2 (D12)       (MISO) (SCL)
                                   RST    |        |11  P4.1 (D11)       (MOSI) (SDA)
                                   3V     |        |10  P4.0 (D10)       (SS)
                                   5V5    |        | 9  P1.7 (D9)
                                   GND    |        | 8  P1.6 (D8)
                                   GND    |        | 7  P1.5 (D7)  (PWM)
                              (NC) VIN    |        | 6  P1.4 (D6)  (PWM)
                              (A0) P6.0 14|        | 5  P1.3 (D5)  (PWM)
                              (A1) P6.1 15|        | 4  P1.2 (D4)  (PWM)
                              (A2) P6.2 16|        | 3  P1.1 (D3)
                              (A3) P6.3 17|        | 2  P1.0 (D2)
                              (A4) P5.0 18|        | 1  P4.4 (D1)         (TXD)
                              (A5) P5.1 19|        | 0  P4.5 (D0)         (RXD)
                                          +--------+

                                               ----+
                                            UEXT-1 |NA  3V3
                                            UEXT-2 |NA  GND
                                            UEXT-3 |1   P4.4 (D1)       (TXD)
                                            UEXT-4 |0   P4.5 (D0)       (RXD)
                                            UEXT-5 |21  P4.7 (SOFT_SCL)
                10 pin UEXT connector       UEXT-6 |22  P4.6 (SOFT_SDA)
                                            UEXT-7 |12  P4.2 (D12)      (MISO)
                                            UEXT-8 |11  P4.1 (D11)      (MOSI)
                                            UEXT-9 |13  P4.3 (D13)      (SCK)
                                            UEXT-10|20  PJ.0            (#UEXT_CS)
                                               ----+

                                               ----+
                                                   |23  PJ.3 (GREEN LED)
                                 LED's and BUTTON  |24  PJ.2 (RED LED OLIMEXINO-T5510 ONLY)
                                                   |25  P2.0 (BUTTON)
                                               ----+

*/

//Pin names based on the silkscreen and some special pins
static const uint8_t P4_5 = 0;
static const uint8_t P4_4 = 1;
static const uint8_t P1_0 = 2;
static const uint8_t P1_1 = 3;
static const uint8_t P1_2 = 4;
static const uint8_t P1_3 = 5;
static const uint8_t P1_4 = 6;
static const uint8_t P1_5 = 7;
static const uint8_t P1_6 = 8;
static const uint8_t P1_7 = 9;
static const uint8_t P4_0 = 10;
static const uint8_t P4_1 = 11;
static const uint8_t P4_2 = 12;
static const uint8_t P4_3 = 13;
static const uint8_t P6_0 = 14;
static const uint8_t P6_1 = 15;
static const uint8_t P6_2 = 16;
static const uint8_t P6_3 = 17;
static const uint8_t P5_0 = 18;
static const uint8_t P5_1 = 19;
static const uint8_t PJ_0 = 20;
static const uint8_t P4_7 = 21;
static const uint8_t P4_6 = 22;
static const uint8_t PJ_3 = 23;
static const uint8_t PJ_2 = 24;
static const uint8_t P2_0 = 25;

static const uint8_t GREEN_LED = 23;
static const uint8_t RED_LED = 24;

#ifdef ARDUINO_MAIN
const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
	(uint16_t) &P3DIR,
	(uint16_t) &P4DIR,
	(uint16_t) &P5DIR,
	(uint16_t) &P6DIR,
	(uint16_t) &PJDIR
};

const uint16_t port_to_sel[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
	(uint16_t) &P3SEL,
	(uint16_t) &P4SEL,
	(uint16_t) &P5SEL,
	(uint16_t) &P6SEL,
#ifdef PJSEL_
	(uint16_t) &PJSEL
#else 
        NOT_A_PORT
#endif	
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
	(uint16_t) &P3REN,
	(uint16_t) &P4REN,
	(uint16_t) &P5REN,
	(uint16_t) &P6REN,
#ifdef PJREN_
	(uint16_t) &PJREN
#endif
};

const uint16_t port_to_sel2[] = {
	NOT_A_PORT,
#ifdef P1SEL2_
	(uint16_t) &P1SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P2SEL2_
	(uint16_t) &P2SEL2,
#else 
        NOT_A_PORT,
#endif
#ifdef P3SEL2_
	(uint16_t) &P3SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P4SEL2_
	(uint16_t) &P4SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P5SEL2_
	(uint16_t) &P5SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P6SEL2_
	(uint16_t) &P6SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef PJSEL2_
	(uint16_t) &PJSEL2,
#else
        NOT_A_PORT
#endif
};

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
	(uint16_t) &P3IN,
	(uint16_t) &P4IN,
	(uint16_t) &P5IN,
	(uint16_t) &P6IN,
	(uint16_t) &PJIN
};
const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
	(uint16_t) &P3OUT,
	(uint16_t) &P4OUT,
	(uint16_t) &P5OUT,
	(uint16_t) &P6OUT,
	(uint16_t) &PJOUT
};

/* 
 *  
 */
const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  0 */
	NOT_ON_TIMER, /*  1 */
	NOT_ON_TIMER, /*  2 */
	T0A0,         /*  3 */
	T0A1,         /*  4 */
	T0A2,         /*  5 */
	T0A3,         /*  6 */
	T0A4,         /*  7 */
	NOT_ON_TIMER, /*  8 */
	T1A0,         /*  9 */
	NOT_ON_TIMER, /* 10 */
	NOT_ON_TIMER, /* 11 */
	NOT_ON_TIMER, /* 12 */
	NOT_ON_TIMER, /* 13 */
	NOT_ON_TIMER, /* 14 */
	NOT_ON_TIMER, /* 15 */
	NOT_ON_TIMER, /* 16 */
	NOT_ON_TIMER, /* 17 */
	NOT_ON_TIMER, /* 18 */
	NOT_ON_TIMER, /* 19 */
	NOT_ON_TIMER, /* 20 */
	NOT_ON_TIMER, /* 21 */
	NOT_ON_TIMER, /* 22 */
	NOT_ON_TIMER, /* 23 */
	NOT_ON_TIMER, /* 24 */
	NOT_ON_TIMER, /* 25 */
};

const uint8_t digital_pin_to_port[] = {
	P4, /* 0 */
	P4, /* 1 */
	P1, /* 2 */
	P1, /* 3 */
	P1, /* 4 */
	P1, /* 5 */
	P1, /* 6 */
	P1, /* 7 */
	P1, /* 8 */
	P1, /* 9 */
	P4, /* 10 */
	P4, /* 11 */
	P4, /* 12 */
	P4, /* 13 */
	P6, /* 14 */
	P6, /* 15 */
	P6, /* 16 */
	P6, /* 17 */
	P5, /* 18 */
	P5, /* 19 */
	PJ, /* 20 */
	P4, /* 21 */
	P4, /* 22 */
	PJ, /* 23 */
	PJ, /* 24 */
	P2  /* 25 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	BV(5), /* 0 */
	BV(4), /* 1 */
	BV(0), /* 2 */
	BV(1), /* 3 */
	BV(2), /* 4 */
	BV(3), /* 5 */
	BV(4), /* 6 */
	BV(5), /* 7 */
	BV(6), /* 8 */
	BV(7), /* 9 */
	BV(0), /* 10 */
	BV(1), /* 11 */
	BV(2), /* 12 */
	BV(3), /* 13 */
	BV(0), /* 14 */
	BV(1), /* 15 */
	BV(2), /* 16 */
	BV(3), /* 17 */
	BV(0), /* 18 */
	BV(1), /* 19 */
	BV(0), /* 20 */
	BV(7), /* 21 */
	BV(6), /* 22 */
	BV(3), /* 23 */
	BV(2), /* 24 */
	BV(0)  /* 25 */
};
#endif
#endif
