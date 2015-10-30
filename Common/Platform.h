/*
 * Plattform.h
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#ifndef SOURCES_COMMON_PLATFORM_H_
#define SOURCES_COMMON_PLATFORM_H_

#include "Platform_Local.h"
#include "PE_Types.h" /* common Processor Expert types: bool, NULL, ... */


/* configuration macros"*/
#define PL_CONFIG_HAS_TETIRS          (0)
#if !defined(PL_CONFIG_HAS_SNAKE)
  #define PL_CONFIG_HAS_SNAKE         (0)
#endif


#define PL_CONFIG_HAS_LED				(1 && !defined(PL_CONFIG_DISABLE_HAS_LED))
#define PL_CONFIG_HAS_EVENTS			(1 && !defined(PL_CONFIG_DISABLE_HAS_EVENTS))
	 #define PL_CONFIG_EVENTS_AUTO_CLEAR (1 && PL_CONFIG_HAS_EVENTS)
#define PL_CONFIG_HAS_TIMER				(1 && !defined(PL_CONFIG_DISABLE_HAS_TIMER))
#define PL_CONFIG_HAS_KEYS              (1 && !defined(PL_CONFIG_DISABLE_HAS_KEYS))
#define PL_CONFIG_HAS_JOYSTICK          (1 && PL_CONFIG_HAS_KEYS && defined(PL_CONFIG_BOARD_IS_FRDM))
#define PL_CONFIG_HAS_TRIGGER           (1 && !defined(PL_CONFIG_DISABLE_HAS_TRIGGER))
#define PL_CONFIG_HAS_SHELL             (1 && !defined(PL_CONFIG_DISABLE_HAS_SHELL))
#define PL_CONFIG_HAS_BUZZER            (1 && !defined(PL_CONFIG_DISABLE_HAS_BUZZER) && defined(PL_CONFIG_BOARD_IS_ROBO))
#define PL_CONFIG_HAS_TETRIS            (1 && !defined(PL_CONFIG_DISABLE_HAS_TETRIS))
#define PL_CONFIG_HAS_DEBOUNCE          (1 && PL_CONFIG_HAS_KEYS)
#define PL_CONFIG_HAS_KBI               (0 && !defined(PL_CONFIG_DISABLE_HAS_KBI) && PL_CONFIG_HAS_KEYS && defined(PL_CONFIG_BOARD_IS_ROBO))


void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_PLATFORM_H_ */
