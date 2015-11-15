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
#if PL_CONFIG_HAS_KEYS
  #include "Keys.h"
#endif
#if PL_CONFIG_HAS_TRIGGER
  #include "Trigger.h"
#endif
#if PL_CONFIG_HAS_BUZZER
  #include "Buzzer.h"
#endif
#if PL_CONFIG_HAS_DEBOUNCE
  #include "Debounce.h"
  #include "KeyDebounce.h"
#endif
#if PL_CONFIG_HAS_RTOS
  #include "RTOS.h"
#endif
#if PL_CONFIG_HAS_SHELL
  #include "Shell.h"
#endif
#if PL_CONFIG_HAS_MOTOR
	#include "Motor.h"
#endif
#if PL_CONFIG_HAS_SNAKE
	#include "Snake.h"
#endif


void PL_Init(void) {
#if PL_CONFIG_HAS_RTOS
  RTOS_Init();
#endif
#if PL_CONFIG_HAS_LED
  LED_Init();
#endif
#if PL_CONFIG_HAS_EVENTS
  EVNT_Init();
#endif
#if PL_CONFIG_HAS_TIMER
  TMR_Init();
#endif
#if PL_CONFIG_HAS_KEYS
  KEY_Init();
#endif
#if PL_CONFIG_HAS_TRIGGER
  TRG_Init();
#endif
#if PL_CONFIG_HAS_BUZZER
  BUZ_Init();
#endif
#if PL_CONFIG_HAS_DEBOUNCE
  DBNC_Init();
  KEYDBNC_Init();
#endif
#if PL_CONFIG_HAS_SHELL
  SHELL_Init();
#endif
#if PL_CONFIG_HAS_MOTOR
	MOT_Init();
#endif
#if PL_CONFIG_HAS_SEMAPHORE
	SEM_Init();
#endif
#if PL_CONFIG_HAS_REFLECTANCE
	REF_Init();
#endif
#if PL_CONFIG_HAS_SNAKE
	SNAKE_Init();
#endif


}

void PL_Deinit(void) {
#if PL_CONFIG_HAS_RTOS
  RTOS_Deinit();
#endif
#if PL_CONFIG_HAS_LED
  LED_Deinit();
#endif
#if PL_CONFIG_HAS_EVENTS
  EVNT_Deinit();
#endif
#if PL_CONFIG_HAS_TIMER
  TMR_Deinit();
#endif
#if PL_CONFIG_HAS_KEYS
  KEY_Deinit();
#endif
#if PL_CONFIG_HAS_BUZZER
  BUZ_Deinit();
#endif
#if PL_CONFIG_HAS_TRIGGER
  TRG_Deinit();
#endif
#if PL_CONFIG_HAS_DEBOUNCE
  KEYDBNC_Init();
  DBNC_Init();
#endif
#if PL_CONFIG_HAS_SHELL
  SHELL_Deinit();
#endif
#if PL_CONFIG_HAS_MOTOR
	MOT_Deinit();
#endif
#if PL_CONFIG_HAS_SEMAPHORE
	SEM_Deinit();
#endif
#if PL_CONFIG_HAS_REFLECTANCE
	REF_Init();
#endif
#if PL_CONFIG_HAS_SNAKE
	SNAKE_Deinit();
#endif
}
