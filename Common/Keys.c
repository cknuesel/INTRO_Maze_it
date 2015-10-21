/*
 * Keys.c
 *
 *  Created on: 16.10.2015
 *      Author: Manuel
 */
/* This module implements a generic keyboard driver for up to 7 Keys.
 * It is using macros for maximum flexibility with minimal code overhead.
 */

#include "Platform.h"
#include "CLS1.h"
#if PL_CONFIG_HAS_KEYS
  #include "Keys.h"
#if PL_CONFIG_HAS_EVENTS
  #include "Event.h"
#endif

void KEY_Scan(void) {
  /*! \todo check handling all keys */
#if PL_CONFIG_NOF_KEYS >= 1
  if (KEY1_Get()) { /* key pressed */
    EVNT_SetEvent(EVNT_SW1_PRESSED);
  }
#endif
#if PL_CONFIG_NOF_KEYS >= 2
  if (KEY2_Get()) { /* key pressed */
    EVNT_SetEvent(EVNT_SW2_PRESSED);
  }
#endif
#if PL_CONFIG_NOF_KEYS >= 3
  if (KEY3_Get()) { /* key pressed */
    EVNT_SetEvent(EVNT_SW3_PRESSED);
  }
#endif
#if PL_CONFIG_NOF_KEYS >= 4
  if (KEY4_Get()) { /* key pressed */
    EVNT_SetEvent(EVNT_SW4_PRESSED);
  }
#endif
#if PL_CONFIG_NOF_KEYS >= 5
  if (KEY5_Get()) { /* key pressed */
    EVNT_SetEvent(EVNT_SW5_PRESSED);
  }
#endif
#if PL_CONFIG_NOF_KEYS >= 6
  if (KEY6_Get()) { /* key pressed */
    EVNT_SetEvent(EVNT_SW6_PRESSED);
  }
#endif
#if PL_CONFIG_NOF_KEYS >= 7
  if (KEY7_Get()) { /* key pressed */
    EVNT_SetEvent(EVNT_SW7_PRESSED);
  }
#endif
}

/*! \brief Key driver initialization */
void KEY_Init(void) {
  /* nothing needed for now */
}

/*! \brief Key driver de-initialization */
void KEY_Deinit(void) {
  /* nothing needed for now */
}

void APP_KeyEvntHandler(EVNT_Handle event) {
  switch(event) {
  #if PL_CONFIG_NOF_KEYS >= 1
    case EVNT_SW1_PRESSED:
    case EVNT_SW1_LPRESSED:
    case EVNT_SW1_RELEASED:
      LED1_Neg();
      CLS1_SendStr("Rot\r\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
    case EVNT_SW2_LPRESSED:
    case EVNT_SW2_RELEASED:
      LED1_Neg();

      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 3
    case EVNT_SW3_PRESSED:
    case EVNT_SW3_LPRESSED:
    case EVNT_SW3_RELEASED:
      LED3_Neg();
      CLS1_SendStr("Blau\r\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 4
    case EVNT_SW4_PRESSED:
    case EVNT_SW4_LPRESSED:
    case EVNT_SW4_RELEASED:
    	CLS1_SendStr("Grün\r\n", CLS1_GetStdio()->stdOut);
      LED2_Neg();
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 5
    case EVNT_SW5_PRESSED:
    case EVNT_SW5_LPRESSED:
    case EVNT_SW5_RELEASED:
      LED1_Neg();
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 6
    case EVNT_SW6_PRESSED:
    case EVNT_SW6_LPRESSED:
    case EVNT_SW6_RELEASED:
      LED1_Neg();
      break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 7
    case EVNT_SW7_PRESSED:
    case EVNT_SW7_LPRESSED:
    case EVNT_SW7_RELEASED:
      LED1_Neg();
      break;
   #endif
    default:
      break;
  }
}

#endif /* PL_HAS_KEYS */




