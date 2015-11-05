/*
 * RTOS.c
 *
 *  Created on: 05.11.2015
 *      Author: Cyrill
 */

#include "Platform.h"
#if PL_CONFIG_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
#include "Event.h"
#include "Keys.h"
#include "Application.h"

#define TEST_RTOS_TASKS  (0)

static volatile bool SW1Pressed = FALSE;

void RTOS_ButtonSW1Press(void) {
  SW1Pressed = TRUE;
}

#if TEST_RTOS_TASKS
static void T2(void* param) {
  TickType_t xLastWakeTime;

  xLastWakeTime = xTaskGetTickCount();
  for(;;) {
    LED1_Neg();
    FRTOS1_vTaskDelayUntil(&xLastWakeTime, 50/portTICK_RATE_MS);
  }
}

static void T3(void* param) {
  for(;;) {
    LED2_Neg();
  }
}
#endif

static void AppTask(void* param) {
  EVNT_SetEvent(EVNT_STARTUP); /* set startup event */
  for(;;) {
#if PL_CONFIG_HAS_EVENTS
  #if PL_CONFIG_EVENTS_AUTO_CLEAR
  EVNT_HandleEvent(APP_EvntHandler, TRUE);
  #else
  EVNT_HandleEvent(APP_EvntHandler, FALSE);
  #endif
#endif
#if PL_CONFIG_HAS_KEYS && PL_CONFIG_NOF_KEYS>0 && !PL_CONFIG_HAS_KBI
    KEY_Scan(); /* scan keys */
#endif
    //LED1_Neg();
    FRTOS1_vTaskDelay(5/portTICK_RATE_MS);
  }
}

void RTOS_Run(void) {
  FRTOS1_vTaskStartScheduler();  /* does usually not return! */
}

void RTOS_Init(void) {
  /*! \todo Add tasks here */
  if (FRTOS1_xTaskCreate(AppTask, (signed portCHAR *)"App", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
#if TEST_RTOS_TASKS
  if (FRTOS1_xTaskCreate(T2, (signed portCHAR *)"T2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
  if (FRTOS1_xTaskCreate(T3, (signed portCHAR *)"T3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
#endif
}

void RTOS_Deinit(void) {
  /* nothing needed */
}

#endif /* PL_HAS_RTOS */

