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
#if PL_CONFIG_HAS_REFLECTANCE
  #include "Reflectance.h"
#endif
#if PL_CONFIG_HAS_RADIO
	#include "Remote.h"
#endif



void KEY_Scan(void) {
  /*! \todo check handling all keys */
#if PL_CONFIG_HAS_DEBOUNCE
  KEYDBNC_Process();
#else
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
#endif
}

#if PL_CONFIG_HAS_KBI
void KEY_EnableInterrupts(void) {
#if PL_CONFIG_NOF_KEYS >= 1
  SW1_Enable();
#endif
#if PL_CONFIG_NOF_KEYS >= 2
  #error "only one keyboard interrupt key handled right now"
#endif
}
#endif /* PL_CONFIG_HAS_KBI */

#if PL_CONFIG_HAS_KBI
void KEY_DisableInterrupts(void) {
#if PL_CONFIG_NOF_KEYS >= 1
  SW1_Disable();
#endif
#if PL_CONFIG_NOF_KEYS >= 2
  #error "only one keyboard interrupt key handled right now"
#endif
}
#endif /* PL_CONFIG_HAS_KBI */

#if PL_CONFIG_HAS_KBI
void KEY_OnInterrupt(KEY_Buttons button) {
#if PL_CONFIG_HAS_DEBOUNCE
  KEYDBNC_Process();
#else
  switch(button) {
  #if PL_CONFIG_NOF_KEYS >= 1
      case KEY_BTN1: EVNT_SetEvent(EVNT_SW1_PRESSED); break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 2
      case KEY_BTN2: EVNT_SetEvent(EVNT_SW2_PRESSED); break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 3
      case KEY_BTN3: EVNT_SetEvent(EVNT_SW3_PRESSED); break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 4
      case KEY_BTN4: EVNT_SetEvent(EVNT_SW4_PRESSED); break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 5
      case KEY_BTN5: EVNT_SetEvent(EVNT_SW5_PRESSED); break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 6
      case KEY_BTN6: EVNT_SetEvent(EVNT_SW6_PRESSED); break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 6
      case KEY_BTN7: EVNT_SetEvent(EVNT_SW7_PRESSED); break;
  #endif
      default:
        /* unknown? */
        break;
    } /* switch */
  #endif
  }
  #endif /* PL_CONFIG_HAS_KBI */


/*! \brief Key driver initialization */
void KEY_Init(void) {
  /* nothing needed for now */
}

/*! \brief Key driver de-initialization */
void KEY_Deinit(void) {
  /* nothing needed for now */
}

#if PL_CONFIG_HAS_SNAKE
	void APP_KeyEvntHandler(EVNT_Handle event) {
	  switch(event) {
	  #if PL_CONFIG_NOF_KEYS >= 1 /* A */
		case EVNT_SW1_PRESSED:
		  EVNT_ClearEvent(EVNT_SW1_PRESSED);
		  EVNT_SetEvent(EVNT_SNAKE_UP);
		  break;

		case EVNT_SW1_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW1_LPRESSED);
		  break;

		case EVNT_SW1_RELEASED:
		  EVNT_ClearEvent(EVNT_SW1_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 2 /* B */
		case EVNT_SW2_PRESSED:
		  EVNT_ClearEvent(EVNT_SW2_PRESSED);
		  EVNT_SetEvent(EVNT_SNAKE_RIGHT);
		  break;

		case EVNT_SW2_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW2_LPRESSED);
		  break;

		case EVNT_SW2_RELEASED:
		  EVNT_ClearEvent(EVNT_SW2_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 3 /* C */
	   case EVNT_SW3_PRESSED:
		  EVNT_ClearEvent(EVNT_SW3_PRESSED);
		  EVNT_SetEvent(EVNT_SNAKE_DOWN);
		  break;

	   case EVNT_SW3_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW3_LPRESSED);
		  break;

	   case EVNT_SW3_RELEASED:
		  EVNT_ClearEvent(EVNT_SW3_RELEASED);
		  LED1_Neg();
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 4 /* D */
		case EVNT_SW4_PRESSED:
		  EVNT_ClearEvent(EVNT_SW4_PRESSED);
		  EVNT_SetEvent(EVNT_SNAKE_LEFT);
		  break;

		case EVNT_SW4_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW4_LPRESSED);
		  break;

		case EVNT_SW4_RELEASED:
		  EVNT_ClearEvent(EVNT_SW4_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 5 /* E */
		case EVNT_SW5_PRESSED:
		  EVNT_ClearEvent(EVNT_SW5_PRESSED);
		  break;

		case EVNT_SW5_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW5_LPRESSED);
		  break;

		case EVNT_SW5_RELEASED:
		  EVNT_ClearEvent(EVNT_SW5_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 6 /* F */
		case EVNT_SW6_PRESSED:
		  EVNT_ClearEvent(EVNT_SW6_PRESSED);
		  break;

		case EVNT_SW6_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW6_LPRESSED);
		  break;

		case EVNT_SW6_RELEASED:
		  EVNT_ClearEvent(EVNT_SW6_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 7 /* G, Joystick */
		case EVNT_SW7_PRESSED:
		  EVNT_ClearEvent(EVNT_SW7_PRESSED);
		  EVNT_SetEvent(EVNT_SNAKE_START_PAUSE);
		 break;

		case EVNT_SW7_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW7_LPRESSED);
		  break;

		case EVNT_SW7_RELEASED:
		  EVNT_ClearEvent(EVNT_SW7_RELEASED);
		  break;
	  #endif

		default:
		  break;
	  }
	}

#elif PL_CONFIG_HAS_TETRIS
	void APP_KeyEvntHandler(EVNT_Handle event) {
	  switch(event) {
	  #if PL_CONFIG_NOF_KEYS >= 1 /* A */
		case EVNT_SW1_PRESSED:
		  EVNT_ClearEvent(EVNT_SW1_PRESSED);
		  EVNT_SetEvent(EVNT_TETRIS_UP);
		  break;

		case EVNT_SW1_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW1_LPRESSED);
		  break;

		case EVNT_SW1_RELEASED:
		  EVNT_ClearEvent(EVNT_SW1_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 2 /* B */
		case EVNT_SW2_PRESSED:
		  EVNT_ClearEvent(EVNT_SW2_PRESSED);
		  EVNT_SetEvent(EVNT_TETRIS_RIGHT);
		  break;

		case EVNT_SW2_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW2_LPRESSED);
		  break;

		case EVNT_SW2_RELEASED:
		  EVNT_ClearEvent(EVNT_SW2_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 3 /* C */
	   case EVNT_SW3_PRESSED:
		  EVNT_ClearEvent(EVNT_SW3_PRESSED);
		  EVNT_SetEvent(EVNT_TETRIS_DOWN);
		  break;

	   case EVNT_SW3_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW3_LPRESSED);
		  break;

	   case EVNT_SW3_RELEASED:
		  EVNT_ClearEvent(EVNT_SW3_RELEASED);
		  LED1_Neg();
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 4 /* D */
		case EVNT_SW4_PRESSED:
		  EVNT_ClearEvent(EVNT_SW4_PRESSED);
		  EVNT_SetEvent(EVNT_TETRIS_LEFT);
		  break;

		case EVNT_SW4_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW4_LPRESSED);
		  break;

		case EVNT_SW4_RELEASED:
		  EVNT_ClearEvent(EVNT_SW4_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 5 /* E */
		case EVNT_SW5_PRESSED:
		  EVNT_ClearEvent(EVNT_SW5_PRESSED);
		  break;

		case EVNT_SW5_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW5_LPRESSED);
		  break;

		case EVNT_SW5_RELEASED:
		  EVNT_ClearEvent(EVNT_SW5_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 6 /* F */
		case EVNT_SW6_PRESSED:
		  EVNT_ClearEvent(EVNT_SW6_PRESSED);
		  break;

		case EVNT_SW6_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW6_LPRESSED);
		  break;

		case EVNT_SW6_RELEASED:
		  EVNT_ClearEvent(EVNT_SW6_RELEASED);
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 7 /* G, Joystick */
		case EVNT_SW7_PRESSED:
		  EVNT_ClearEvent(EVNT_SW7_PRESSED);
		  EVNT_SetEvent(EVNT_TETRIS_DROP);
		 break;

		case EVNT_SW7_LPRESSED:
		  EVNT_ClearEvent(EVNT_SW7_LPRESSED);
		  break;

		case EVNT_SW7_RELEASED:
		  EVNT_ClearEvent(EVNT_SW7_RELEASED);
		  break;
	  #endif

		default:
		  break;
	  }
}

#else /* default Key Event Handler */
	void APP_KeyEvntHandler(EVNT_Handle event) {
		KEY_DATA keydata;
	  switch(event) {
	  #if PL_CONFIG_NOF_KEYS >= 1	/* A */
		case EVNT_SW1_PRESSED:
			#if !PL_CONFIG_EVENTS_AUTO_CLEAR
			  EVNT_ClearEvent(EVNT_SW1_PRESSED);
			#endif
			#if PL_CONFIG_HAS_LCD
			PDC1_WriteLineStr(1,"Hello World");
			#endif
			#if (PL_CONFIG_HAS_REFLECTANCE && PL_CONFIG_HAS_NVM)
			REF_RestorCalib();
			#else
				#if PL_CONFIG_HAS_RADIO
					keydata = A_p;
					RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
				#endif
			#endif
			break;

		case EVNT_SW1_LPRESSED:
			#if !PL_CONFIG_EVENTS_AUTO_CLEAR
			  EVNT_ClearEvent(EVNT_SW1_LPRESSED);
			#endif
			#if PL_CONFIG_HAS_RADIO && defined(PL_CONFIG_BOARD_IS_FRDM)
			  keydata = A_lp;
			  	 RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
			#if defined(PL_CONFIG_BOARD_IS_ROBO)
			  REF_CalibrateStartStop();
			#endif
			break;

		case EVNT_SW1_RELEASED:
			#if !PL_CONFIG_EVENTS_AUTO_CLEAR
			  EVNT_ClearEvent(EVNT_SW1_RELEASED);
			#endif
			#if PL_CONFIG_HAS_RADIO && defined(PL_CONFIG_BOARD_IS_FRDM)
			  keydata = A_r;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
	   #endif


	  #if PL_CONFIG_NOF_KEYS >= 2	/* B */
		case EVNT_SW2_PRESSED:
			#if !PL_CONFIG_EVENTS_AUTO_CLEAR
			  EVNT_ClearEvent(EVNT_SW2_PRESSED);
			#endif
			#if PL_CONFIG_HAS_RADIO
			  keydata = B_p;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif

		case EVNT_SW2_LPRESSED:
		    #if !PL_CONFIG_EVENTS_AUTO_CLEAR
		      EVNT_ClearEvent(EVNT_SW2_LPRESSED);
			#endif
			#if PL_CONFIG_HAS_RADIO
		      keydata = B_lp;
		      RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		      break;

		case EVNT_SW2_RELEASED:
		   #if !PL_CONFIG_EVENTS_AUTO_CLEAR
		      EVNT_ClearEvent(EVNT_SW2_RELEASED);
		   #endif
			#if PL_CONFIG_HAS_RADIO
		      keydata = B_r;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;
	   #endif


	  #if PL_CONFIG_NOF_KEYS >= 3	/* C */
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW3_PRESSED);
		#endif
		#if PL_CONFIG_HAS_RADIO
		  keydata = C_p;
		  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
		#endif
		break;

	   case EVNT_SW3_LPRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW3_LPRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = C_lp;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;

	   case EVNT_SW3_RELEASED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW3_RELEASED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = C_r;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
	   #endif

	  #if PL_CONFIG_NOF_KEYS >= 4	/* D */
	   case EVNT_SW4_PRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW4_PRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = D_p;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;

		case EVNT_SW4_LPRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW4_LPRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  	 keydata = D_lp;
			 	 RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;

		case EVNT_SW4_RELEASED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW4_RELEASED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  	 keydata = D_r;
			 	 RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;
	   #endif

	  #if PL_CONFIG_NOF_KEYS >= 5	/* E */
		case EVNT_SW5_PRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
			EVNT_ClearEvent(EVNT_SW5_PRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
			  keydata = E_p;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
			break;

		case EVNT_SW5_LPRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW5_LPRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = E_lp;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;

		case EVNT_SW5_RELEASED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW5_RELEASED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = E_r;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;
	   #endif

	  #if PL_CONFIG_NOF_KEYS >= 6	/* F */
		case EVNT_SW6_PRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW6_PRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = F_p;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;

		case EVNT_SW6_LPRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW6_LPRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = F_lp;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;

		case EVNT_SW6_RELEASED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW6_RELEASED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = F_r;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;
	  #endif

	  #if PL_CONFIG_NOF_KEYS >= 7	/* Joystick */
		case EVNT_SW7_PRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW7_PRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = G_p;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		 break;

		case EVNT_SW7_LPRESSED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW7_LPRESSED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = F_lp;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;

		case EVNT_SW7_RELEASED:
		#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		  EVNT_ClearEvent(EVNT_SW7_RELEASED);
		#endif
			#if PL_CONFIG_HAS_RADIO
		  	  keydata = F_r;
			  RAPP_SendPayloadDataBlock(&keydata, sizeof(KEY_DATA), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE);
			#endif
		  break;
	   #endif

		default:
		  break;
	  }
	}
#endif


#endif /* PL_HAS_KEYS */




