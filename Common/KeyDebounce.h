/*
 * KeyDebounce.h
 *
 *  Created on: 29.10.2015
 *      Author: Cyrill
 *
 * This module implements debouncing for multiple keys.
 */

#ifndef SOURCES_COMMON_KEYDEBOUNCE_H_
#define SOURCES_COMMON_KEYDEBOUNCE_H_

/*!
 * \brief Kicks the debouncing state machine.
 */
void KEYDBNC_Process(void);

/*!
 * \brief Driver initialization.
 */
void KEYDBNC_Init(void);

/*!
 * \brief Driver de-initialization.
 */
void KEYDBNC_Deinit(void);



#endif /* SOURCES_COMMON_KEYDEBOUNCE_H_ */
