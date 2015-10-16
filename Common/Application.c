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
#if PL_CONFIG_HAS_KEYS
  #include "Keys.h"
#endif

static void APP_EvntHandler(EVNT_Handle event) {
  switch(event) {
  case EVNT_STARTUP:
	  LED_Test();
	  break;
  case EVENT_LED_HEARTBEAT:
	  LED1_Neg();
	  break;
/*  case EVENT_KEY:
	  APP_KeyEvntHandler(event);
  default:
	  break; */
  }
}


static void App(void) {
	EVNT_SetEvent(EVNT_STARTUP);
	  for(;;) {
	  #if PL_CONFIG_HAS_EVENTS
	    EVNT_HandleEvent(APP_EvntHandler);
	  #endif
}
}

void APP_Run(void) {
 PL_Init();
 App();
 PL_Deinit();
}
