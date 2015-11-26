/*
 * Plattform.h
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#ifndef SOURCES_COMMON_PLATFORM_H_
#define SOURCES_COMMON_PLATFORM_H_

#include "Platform_Local.h"
#if PL_CONFIG_BOARD_IS_ROBO
#include "Platform_Local_Version.h"
#endif
#include "PE_Types.h" /* common Processor Expert types: bool, NULL, ... */


/* configuration macros"*/

/* Games */
#define PL_CONFIG_HAS_TETIRS          	(0 && !defined(PL_CONFIG_DISABLE_HAS_TETIRS)&& defined(PL_CONFIG_BOARD_IS_FRDM))
#define PL_CONFIG_HAS_SNAKE           	(0 && !defined(PL_CONFIG_DISABLE_HAS_SNAKE)&& defined(PL_CONFIG_BOARD_IS_FRDM))

/* Components */
#define PL_CONFIG_HAS_LED				(1 && !defined(PL_CONFIG_DISABLE_HAS_LED))
#define PL_CONFIG_HAS_KEYS              (1 && !defined(PL_CONFIG_DISABLE_HAS_KEYS))
	#define PL_CONFIG_HAS_DEBOUNCE          (1 && PL_CONFIG_HAS_KEYS)
	#define PL_CONFIG_HAS_KBI               (0 && !defined(PL_CONFIG_DISABLE_HAS_KBI) && PL_CONFIG_HAS_KEYS && defined(PL_CONFIG_BOARD_IS_ROBO))
#define PL_CONFIG_HAS_JOYSTICK          (1 && PL_CONFIG_HAS_KEYS && defined(PL_CONFIG_BOARD_IS_FRDM))
#define PL_CONFIG_HAS_BUZZER            (1 && !defined(PL_CONFIG_DISABLE_HAS_BUZZER) && defined(PL_CONFIG_BOARD_IS_ROBO))
#define PL_CONFIG_HAS_MOTOR				(1 && !defined(PL_CONFIG_DISABLE_HAS_MOTOR)&& defined(PL_CONFIG_BOARD_IS_ROBO))
	#define PL_CONFIG_HAS_MOTOR_TACHO		(1 && PL_CONFIG_HAS_MOTOR)
		#define PL_CONFIG_HAS_PID				(1 && PL_CONFIG_HAS_MOTOR_TACHO)
	#define PL_CONFIG_HAS_DRIVE				(1 && PL_CONFIG_HAS_MOTOR)
#define PL_CONFIG_HAS_REFLECTANCE		(1 && !defined(PL_CONFIG_DISABLE_HAS_REFLECTANCE)&& defined(PL_CONFIG_BOARD_IS_ROBO))
	#define PL_CONFIG_HAS_LINE_FOLLOW       (1 && PL_CONFIG_HAS_REFLECTANCE)
#define PL_CONFIG_HAS_MCP4728			(1 && !defined(PL_CONFIG_DISABLE_HAS_MCP4728)&& defined(PL_CONFIG_BOARD_IS_ROBO))
	#define PL_CONFIG_HAS_QUAD_CALIBRATION			(1 && PL_CONFIG_HAS_MCP4728)
#define PL_CONFIG_HAS_ULTRASONIC        (1 && defined(PL_CONFIG_BOARD_IS_ROBO))


/* Others */
#define PL_CONFIG_HAS_EVENTS			(1 && !defined(PL_CONFIG_DISABLE_HAS_EVENTS))
	 #define PL_CONFIG_EVENTS_AUTO_CLEAR 	(1 && PL_CONFIG_HAS_EVENTS)
#define PL_CONFIG_HAS_TIMER				(1 && !defined(PL_CONFIG_DISABLE_HAS_TIMER))
#define PL_CONFIG_HAS_TRIGGER           (1 && !defined(PL_CONFIG_DISABLE_HAS_TRIGGER))
#define PL_CONFIG_HAS_NVM				(1 && !defined(PL_CONFIG_DISABLE_HAS_NVM))
#define PL_CONFIG_HAS_TURN              (1 && PL_CONFIG_HAS_DRIVE)

#define PL_CONFIG_APP_LINE_MAZE         (0)


/* OS */
#define PL_CONFIG_HAS_RTOS				(1 && !defined(PL_CONFIG_DISABLE_HAS_RTOS))
	#define PL_CONFIG_HAS_SEMAPHORE				(1 && PL_CONFIG_HAS_RTOS)

/* Communication */
#define PL_CONFIG_HAS_BLUETOOTH			(1 && !defined(PL_CONFIG_DISABLE_HAS_BLUETOOTH)&& defined(PL_CONFIG_BOARD_IS_ROBO))
#define PL_CONFIG_HAS_SHELL             (1 && !defined(PL_CONFIG_DISABLE_HAS_SHELL))
	#define PL_CONFIG_HAS_SHELL_QUEUE             (1 && PL_CONFIG_HAS_SHELL)
		#define PL_CONFIG_HAS_SQUEUE_SINGLE_CHAR             (1 && PL_CONFIG_HAS_SHELL_QUEUE)
#define PL_CONFIG_HAS_USB_CDC			(1 && !defined(PL_CONFIG_DISABLE_HAS_USB_CDC))
#define PL_CONFIG_HAS_SEGGER_RTT		(0 && !defined(PL_CONFIG_DISABLE_HAS_SEGGER_RTT)&& defined(PL_CONFIG_BOARD_IS_ROBO))

#define PL_CONFIG_HAS_RADIO             (0)
#define PL_CONFIG_HAS_REMOTE            (0 && PL_CONFIG_HAS_RADIO)
#define PL_APP_CONTROL_SENDER           (0 && PL_CONFIG_HAS_JOYSTICK && defined(PL_CONFIG_BOARD_IS_FRDM))



void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_PLATFORM_H_ */
