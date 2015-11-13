/*
 * Shell.h
 *
 *  Created on: 06.11.2015
 *      Author: Cyrill
 *
 *      This module implements a command line interface to the application.
 */

#ifndef SOURCES_COMMON_SHELL_H_
#define SOURCES_COMMON_SHELL_H_

/*!
 * \brief Sends a string to the shell/console stdout
 * \param msg Zero terminated string to write
 */
void SHELL_SendString(unsigned char *msg);

/*! \brief Shell Module initialization, creates Shell task */
void SHELL_Init(void);

/*! \brief Shell driver de-initialization */
void SHELL_Deinit(void);




#endif /* SOURCES_COMMON_SHELL_H_ */
