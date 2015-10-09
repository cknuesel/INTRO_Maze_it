/*
 * Application.c
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#include "Platform.h"
#include "Application.h"
#include "WAIT1.h"
#if PL_CONFIG_HAS_LED
  #include "LED.h"
#endif
#if PL_CONFIG_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_CONFIG_HAS_TIMER
  #include "Timer.h"
#endif

void APP_Run(void) {
 PL_Init();
 LED_Test();
 PL_Deinit();
}
