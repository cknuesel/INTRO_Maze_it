/*
 * Plattform_Local.h
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#ifndef SOURCES_PLATFORM_LOCAL_H_
#define SOURCES_PLATFORM_LOCAL_H_

/* board identification */
#define PL_CONFIG_BOARD_IS_FRDM

#define PL_CONFIG_HAS_LCD           (1)

/* number of LED's on platform */
#if PL_CONFIG_HAS_LCD
  #define PL_CONFIG_NOF_LED  (2) /* SCE of LCD uses same pin as blue RGB LED */
#else
  #define PL_CONFIG_NOF_LED  (3)
#endif

/* number of KEYS on platform */
#define PL_CONFIG_NOF_KEYS (7)


/* disable macros, defined or not */
//#define PL_CONFIG_DISABLE_HAS_LED



#endif /* SOURCES_PLATFORM_LOCAL_H_ */
