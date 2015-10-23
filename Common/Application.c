/*
 * Application.c
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#include "Platform.h"
#include "Application.h"
#include "WAIT1.h"
#include "CLS1.h"
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
#if !PL_CONFIG_EVENTS_AUTO_CLEAR
      EVNT_ClearEvent(EVNT_STARTUP);
    #endif
	  LED_Test();
	  break;
  case EVENT_LED_HEARTBEAT:
#if !PL_CONFIG_EVENTS_AUTO_CLEAR
      EVNT_ClearEvent(EVNT_LED_HEARTBEAT);
    #endif
	  LED1_Neg();
	  break;\

  case EVNT_TestConsole:
#if !PL_CONFIG_EVENTS_AUTO_CLEAR
      EVNT_ClearEvent(EVNT_TestConsole);
    #endif
  #if PL_CONFIG_HAS_SHELL
	  CLS1_SendStr("Dies ist ein Test\r\n",CLS1_GetStdio()->stdOut );
	  //CLS1_SendNum8u(10,CLS1_GetStdio()->stdOut);
	  CLS1_SendStr("123456789\r\n",CLS1_GetStdio()->stdOut );
      #endif
	  break;


  default:
      #if PL_CONFIG_HAS_KEYS
	  APP_KeyEvntHandler(event);
      #endif

	  break;
  }
}


static void App(void) {

	EVNT_SetEvent(EVNT_STARTUP);
#if PL_CONFIG_HAS_SHELL
	EVNT_SetEvent(EVNT_TestConsole);
#endif
	  for(;;) {
	  #if PL_CONFIG_HAS_EVENTS
#if PL_CONFIG_EVENTS_AUTO_CLEAR
    EVNT_HandleEvent(APP_EvntHandler, TRUE);
    #else
    EVNT_HandleEvent(APP_EvntHandler, FALSE);
    #endif
	  #endif
      #if PL_CONFIG_HAS_KEYS
	    KEY_Scan();
      #endif

}
}

void APP_Run(void) {
 PL_Init();
 App();
 PL_Deinit();
}
