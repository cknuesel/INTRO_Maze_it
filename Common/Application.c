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
#if PL_CONFIG_HAS_TRIGGER
#include "Trigger.h"
#endif
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
#if PL_CONFIG_HAS_TETIRS
  #include "Tetris.h"
#endif
#if PL_CONFIG_HAS_SHELL
  #include "CLS1.h"
#endif
#if PL_CONFIG_HAS_BUZZER
  #include "Buzzer.h"
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
  case EVENT_TRIGGER:
#if !PL_CONFIG_EVENTS_AUTO_CLEAR
      EVNT_ClearEvent(EVNT_TestConsole);
    #endif
  #if PL_CONFIG_HAS_TRIGGER
      TRG_IncTick();
#endif
  default:
      #if PL_CONFIG_HAS_KEYS
	  APP_KeyEvntHandler(event);
      #endif

	  break;
  }
}


static void App(void) {
#if PL_CONFIG_HAS_SHELL
  int cntr = 0;
#endif

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
#if PL_CONFIG_HAS_TETIRS
    WAIT1_Waitms(50);
    if (TETRIS_Run()==0) {
      TETRIS_Start();
    }
  #else
    #if PL_CONFIG_HAS_SHELL
    cntr++;
    if ((cntr%100)==0) {
      CLS1_SendStr("hello world!\r\n", CLS1_GetStdio()->stdOut);
    }
    #endif
    WAIT1_Waitms(10);
  #endif

}
}

void APP_Run(void) {
 PL_Init();
 App();
 PL_Deinit();
}
