/*
 * Buzzer.h
 *
 *  Created on: 21.10.2015
 *      Author: Manuel
 */

#ifndef SOURCES_COMMON_BUZZER_H_
#define SOURCES_COMMON_BUZZER_H_


/*!
 * \brief Let the buzzer sound for a specified time.
 * \param freqHz Frequency of the sound. Ignored if the buzzer is not supporting it.
 * \param durationMs Duration in milliseconds.
 * \return Error code, ERR_OK if everything is fine.
 */
uint8_t BUZ_Beep(uint16_t freqHz, uint16_t durationMs);

/*!
 * \brief Initialization of the driver
 */
void BUZ_Init(void);

/*!
 * \brief De-initialization of the driver
 */
void BUZ_Deinit(void);




#endif /* SOURCES_COMMON_BUZZER_H_ */
