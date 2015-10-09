/*
 * Timer.c
 *
 *  Created on: 09.10.2015
 *      Author: Cyrill
 */

#include "Platform.h"
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"

void TMR_OnInterrupt(void) {
  /* this one gets called from an interrupt!!!! */
  /*! \todo Add code for a blinking LED here */
}

void TMR_Init(void) {
  /* nothing needed right now */
}

void TMR_Deinit(void) {
  /* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/

