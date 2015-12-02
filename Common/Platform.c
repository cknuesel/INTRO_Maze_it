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
  #if PL_CONFIG_HAS_SHELL_QUEUE
  	#include "ShellQueue.h"
  #endif
#endif
#if PL_HAS_CONFIG_SEMAPHORE
  #include "Sem.h"
#endif
#if PL_CONFIG_HAS_MOTOR
	#include "Motor.h"
	#if PL_CONFIG_HAS_MOTOR_TACHO
		#include "Tacho.h"
	#endif
	#if PL_CONFIG_HAS_PID
  	  #include "PID.h"
	#endif
	#if PL_CONFIG_HAS_DRIVE
  	  #include "PID.h"
	#endif
#endif
#if PL_CONFIG_HAS_REFLECTANCE
	#include "Reflectance.h"
	#endif
#if PL_CONFIG_HAS_SNAKE
	#include "Snake.h"
#endif
#if PL_CONFIG_HAS_NVM
	#include "NVM_Config.h"
#endif
#if PL_CONFIG_HAS_MCP4728
 #include "MCP4728.h"
#endif
#if PL_CONFIG_HAS_MOTOR_TACHO
  #include "Tacho.h"
#endif
#if PL_CONFIG_HAS_ULTRASONIC
  #include "Ultrasonic.h"
#endif
#if PL_CONFIG_HAS_PID
  #include "PID.h"
#endif
#if PL_CONFIG_HAS_DRIVE
  #include "Drive.h"
#endif
#if PL_CONFIG_HAS_TURN
  #include "Turn.h"
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
  #include "LineFollow.h"
#endif
#if PL_CONFIG_HAS_RADIO
  #include "RNet_App.h"
#endif
#if PL_CONFIG_HAS_REMOTE
  #include "Remote.h"
#endif
#if PL_CONFIG_HAS_IDENTIFY
  #include "Identify.h"
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
	#if PL_CONFIG_HAS_SHELL_QUEUE
  	  SQUEUE_Init();
	#endif
#endif
#if PL_CONFIG_HAS_MOTOR
	MOT_Init();
	#if PL_CONFIG_HAS_MCP4728
 	 MCP4728_Init();
	#endif
	#if PL_CONFIG_HAS_MOTOR_TACHO
		TACHO_Init();
	#endif
	#if PL_CONFIG_HAS_PID
		PID_Init();
	#endif
	#if PL_CONFIG_HAS_DRIVE
  	  DRV_Init();
	#endif
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
#if PL_CONFIG_HAS_NVM
	NVMC_Init();
#endif
#if PL_CONFIG_HAS_ULTRASONIC
  US_Init();
#endif
#if PL_CONFIG_HAS_TURN
  TURN_Init();
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
  LF_Init();
#endif
#if PL_CONFIG_HAS_RADIO
  RNETA_Init();
#endif
#if PL_CONFIG_HAS_REMOTE
  REMOTE_Init();
#endif
#if PL_CONFIG_HAS_IDENTIFY
  ID_Init();
#endif
}

void PL_Deinit(void) {
#if PL_CONFIG_HAS_REMOTE
  REMOTE_Deinit();
#endif
#if PL_CONFIG_HAS_RADIO
  RNETA_Deinit();
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
  LF_Deinit();
#endif
#if PL_CONFIG_HAS_TURN
  TURN_Deinit();
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
#if PL_CONFIG_HAS_SHELL_QUEUE
  	  SQUEUE_Deinit();
	#endif
#endif
#if PL_CONFIG_HAS_MOTOR
	MOT_Deinit();
	#if PL_CONFIG_HAS_MCP4728
 	 MCP4728_Deinit();
	#endif
	#if PL_CONFIG_HAS_PID
	  PID_Deinit();
	#endif
	#if PL_CONFIG_HAS_MOTOR_TACHO
	  TACHO_Deinit();
	#endif
	#if PL_CONFIG_HAS_DRIVE
  	  DRV_Deinit();
	#endif
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
#if PL_CONFIG_HAS_TIMER
  TMR_Deinit();
#endif
#if PL_CONFIG_HAS_EVENTS
  EVNT_Deinit();
#endif
#if PL_CONFIG_HAS_LED
  LED_Deinit();
#endif
#if PL_CONFIG_HAS_ULTRASONIC
  US_Deinit();
#endif
#if PL_CONFIG_HAS_IDENTIFY
  ID_Deinit();
#endif
}
