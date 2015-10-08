/*
 * LED.h
 *
 *  Created on: 01.10.2015
 *      Author: Cyrill
 */

#ifndef SOURCES_COMMON_LED_H_
#define SOURCES_COMMON_LED_H_

#include "Platform.h"

#if PL_CONFIG_NOF_LED>=1
  #include "LED1.h"
#endif
#if PL_CONFIG_NOF_LED>=2
  #include "LED2.h"
#endif
#if PL_CONFIG_NOF_LED>=3
  #include "LED3.h"
#endif

void LED_Init(void);
void LED_Deinit(void);

void LED_Test(void);



#endif /* SOURCES_COMMON_LED_H_ */
