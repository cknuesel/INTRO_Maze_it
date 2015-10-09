/*
 * Plattform.h
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#ifndef SOURCES_COMMON_PLATFORM_H_
#define SOURCES_COMMON_PLATFORM_H_

#include "Platform_Local.h"
#include "PE_Types.h"

/* configuration macros"*/
#define PL_CONFIG_HAS_LED				(1 && !defined(PL_CONFIG_DISABLE_HAS_LED))
#define PL_CONFIG_HAS_EVENTS			(1 && !defined(PL_CONFIG_DISABLE_HAS_EVENTS))
#define PL_CONFIG_HAS_TIMER				(1 && !defined(PL_CONFIG_DISABLE_HAS_TIMER))


void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_PLATFORM_H_ */
