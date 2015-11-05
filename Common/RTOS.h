/*
 * RTOS.h
 *
 *  Created on: 05.11.2015
 *      Author: Cyrill
 *
 *  This module the main tasks of the RTOS.
 */

#ifndef SOURCES_COMMON_RTOS_H_
#define SOURCES_COMMON_RTOS_H_

/*! \brief Runs the scheduler */
void RTOS_Run(void);

/*! \brief Initializes the RTOS module */
void RTOS_Init(void);

/*! \brief De-Initializes the RTOS module */
void RTOS_Deinit(void);

/*!
 * \brief Short button press
 */
void RTOS_ButtonSW1Press(void);



#endif /* SOURCES_COMMON_RTOS_H_ */
