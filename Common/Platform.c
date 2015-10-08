/*
 * Plattform.c
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#include "Platform.h"
#if PL_CONFIG_HAS_LED
  #include "LED.h"
#endif

void PL_Init(void) {
#if PL_CONFIG_HAS_LED
  LED_Init();
#endif
}

void PL_Deinit(void) {
#if PL_CONFIG_HAS_LED
  LED_Deinit();
#endif
}
