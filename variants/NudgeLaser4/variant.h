/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_NRF52_DK_
#define _VARIANT_NRF52_DK_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (32u)
#define NUM_DIGITAL_PINS     (32u)
#define NUM_ANALOG_INPUTS    (8u)
#define NUM_ANALOG_OUTPUTS   (0u)

// LEDs
#define BLUE_LED                (16u)
#define GREEN_LED               (18u)
#define RED_LED                 (11u)
#define PIN_LED1                RED_LED
#define PIN_LED2                GREEN_LED
#define PIN_LED3                BLUE_LED
#define LED_BUILTIN             PIN_LED1

#define LED_RED                 RED_LED
#define LED_BLUE                BLUE_LED  // Used in the core for BLE

#define LED_STATE_ON            1         // State when LED is litted

// Buttons
#define PIN_BUTTON1             (29u)
//#define PIN_BUTTON2             (7u)

/*
 * Serial interfaces
 */
// Serial
#define PIN_SCANNER_RX            (15u)
#define PIN_SCANNER_TX            (17u)

#define PIN_MCU_RX                (12u)
#define PIN_MCU_TX                (14u)

#define PIN_SERIAL_RX             PIN_SCANNER_RX
#define PIN_SERIAL_TX             PIN_MCU_TX

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_CS              (6u)
#define PIN_SPI_MISO            (5u)
#define PIN_SPI_MOSI            (3u)
#define PIN_SPI_SCK             (8u)

static const uint8_t SS   = PIN_SPI_CS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA            (13u)
#define PIN_WIRE_SCL             (7u)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// Interupts
#define PIN_MPU_INTERRUPT       (4u)
#define PIN_RTC_INTERRUPT       (19u)
#define PIN_STAT                (27u)
#define PIN_SCANNER_TRIGGER     (2u)
#define PIN_SCANNER_DECODE      (20u)
#define PIN_SCANNER_POWER       (28u)
#define PIN_BATTERY_VOLTAGE     (30u)
#define PIN_LASER_TRIGGER   PIN_SCANNER_TRIGGER    

static inline bool isPinValid(uint32_t pin)
{
  // 0, 1 is xtal
  if (pin >= PINS_COUNT) return false;

  const uint8_t forbid[] = { 0, 1, };
  for(uint8_t i=0; i<sizeof(forbid); i++)
  {
    if ( pin == forbid[i] ) return false;
  }

  return true;
}

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
