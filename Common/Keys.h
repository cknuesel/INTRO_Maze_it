/*
 * Keys.h
 *
 *  Created on: 16.10.2015
 *      Author: Manuel
 */

#ifndef SOURCES_COMMON_KEYS_H_
#define SOURCES_COMMON_KEYS_H_

#include "Platform.h"
#if PL_CONFIG_HAS_LED
#include "LED.h"
#endif

#if PL_CONFIG_HAS_KEYS

typedef enum {
#if PL_CONFIG_NOF_KEYS>=1
  KEY_BTN1, /*!< button 1 */
#endif
#if PL_CONFIG_NOF_KEYS>=2
  KEY_BTN2, /*!< button 2 */
#endif
#if PL_CONFIG_NOF_KEYS>=3
  KEY_BTN3, /*!< button 3 */
#endif
#if PL_CONFIG_NOF_KEYS>=4
  KEY_BTN4, /*!< button 4 */
#endif
#if PL_CONFIG_NOF_KEYS>=5
  KEY_BTN5, /*!< button 5 */
#endif
#if PL_CONFIG_NOF_KEYS>=6
  KEY_BTN6, /*!< button 6 */
#endif
#if PL_CONFIG_NOF_KEYS>=7
  KEY_BTN7, /*!< button 7 */
#endif
  KEY_BTN_LAST /*!< must be last */
} KEY_Buttons;

#if PL_CONFIG_NOF_KEYS>=1
  #include "SW1.h"

  #define KEY1_Get()  (!(SW1_GetVal()))
    /*!< Macro which returns TRUE if key is pressed */
#else
  #define KEY1_Get()  FALSE
    /*!< if we do not have a button, then return 'not pressed' */
#endif

#if PL_CONFIG_NOF_KEYS>=2
  #include "SW2.h"

  #define KEY2_Get()  (!(SW2_GetVal()))
    /*!< Macro which returns TRUE if key is pressed */
#else
  #define KEY2_Get()  FALSE
    /*!< if we do not have a button, then return 'not pressed' */
#endif

#if PL_CONFIG_NOF_KEYS>=3
  #include "SW3.h"

  #define KEY3_Get()  (!(SW3_GetVal()))
    /*!< Macro which returns TRUE if key is pressed */
#else
  #define KEY3_Get()  FALSE
    /*!< if we do not have a button, then return 'not pressed' */
#endif

#if PL_CONFIG_NOF_KEYS>=4
  #include "SW4.h"

  #define KEY4_Get()  (!(SW4_GetVal()))
    /*!< Macro which returns TRUE if key is pressed */
#else
  #define KEY4_Get()  FALSE
    /*!< if we do not have a button, then return 'not pressed' */
#endif

#if PL_CONFIG_NOF_KEYS>=5
  #include "SW5.h"

  #define KEY5_Get()  (!(SW5_GetVal()))
    /*!< Macro which returns TRUE if key is pressed */
#else
  #define KEY5_Get()  FALSE
    /*!< if we do not have a button, then return 'not pressed' */
#endif

#if PL_CONFIG_NOF_KEYS>=6
  #include "SW6.h"

  #define KEY6_Get()  (!(SW6_GetVal()))
    /*!< Macro which returns TRUE if key is pressed */
#else
  #define KEY6_Get()  FALSE
    /*!< if we do not have a button, then return 'not pressed' */
#endif

#if PL_CONFIG_NOF_KEYS>=7
  #include "SW7.h"

  #define KEY7_Get()  (!(SW7_GetVal()))
    /*!< Macro which returns TRUE if key is pressed */
#else
  #define KEY7_Get()  FALSE
    /*!< if we do not have a button, then return 'not pressed' */
#endif

#if PL_CONFIG_HAS_KBI
/*!
 * \brief Function called from a keyboard interrupt (if supported).
 * \param button Button for which interrupt has been generated.
 */
void KEY_OnInterrupt(KEY_Buttons button);

/*!
 * \brief Acknowledge any pending interrupt, and enable again keyboard interrupts
 */
void KEY_EnableInterrupts(void);

/*!
 * \brief Acknowledge any pending interrupt, and enable again keyboard interrupts
 */
void KEY_DisableInterrupts(void);

#endif

typedef enum {
  A_p,
  A_lp,
  A_r,
  B_p,
  B_lp,
  B_r,
  C_p,
  C_lp,
  C_r,
  D_p,
  D_lp,
  D_r,
  E_p,
  E_lp,
  E_r,
  F_p,
  F_lp,
  F_r,
  G_p,
  G_lp,
  G_r,
} KEY_DATA;

/*!
 * \brief Checks the key status and generates the events.
 */
void KEY_Scan(void);

/*! \brief Get access to key hardware. Use KEY_Close() afterwards. */
void KEY_Open(void);

/*! \brief Finish access to key hardware. Called after KEY_Open(). */
void KEY_Close(void);

/*! \brief Key driver initialization */
void KEY_Init(void);

/*! \brief Key driver de-initialization */
void KEY_Deinit(void);

#endif /* PL_HAS_KEYS */



#endif /* SOURCES_COMMON_KEYS_H_ */
