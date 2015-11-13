/*
 * Timer.c
 *
 *  Created on: 09.10.2015
 *      Author: Cyrill
 */

#include "Platform.h"
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#include "Event.h"
#if PL_CONFIG_HAS_TRIGGER
	#include "Trigger.h";
#endif

void TMR_OnInterrupt(void) {
  /* this one gets called from an interrupt!!!! */
  /*! \todo Add code for a blinking LED here */
	static int cntr = 0;
#define BLINK_PERIOD_MS 2500
	cntr++;
	if((cntr%(BLINK_PERIOD_MS/TMR_TICK_MS))==0){
		EVNT_SetEvent(EVENT_LED_HEARTBEAT);
	}
#if PL_CONFIG_HAS_TRIGGER
	TRG_IncTick();
#endif

}

void TMR_Init(void) {
  /* nothing needed right now */

}

void TMR_Deinit(void) {
  /* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/

