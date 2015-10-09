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
#if PL_CONFIG_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_CONFIG_HAS_TIMER
  #include "Timer.h"
#endif

void PL_Init(void) {
#if PL_CONFIG_HAS_LED
  LED_Init();
#endif
#if PL_CONFIG_HAS_EVENTS
  EVNT_Init();
#endif
#if PL_CONFIG_HAS_TIMER
  TMR_Init();
#endif
}

void PL_Deinit(void) {
#if PL_CONFIG_HAS_LED
  LED_Deinit();
#endif
#if PL_CONFIG_HAS_EVENTS
  EVNT_Deinit();
#endif
#if PL_CONFIG_HAS_TIMER
  TMR_Deinit();
#endif
}
