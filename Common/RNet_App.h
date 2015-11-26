/*
 * RNet_App.h
 *
 *  Created on: 26.11.2015
 *      Author: Cyrill
 */

#ifndef SOURCES_COMMON_RNET_APP_H_
#define SOURCES_COMMON_RNET_APP_H_

#include "Platform.h"
#include "RNWK.h"
#if PL_CONFIG_HAS_SHELL
#include "CLS1.h"
uint8_t RNETA_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
#endif

/*!
 * \brief Return the current remote node address.
 * \return Remote node address
 */
RNWK_ShortAddrType RNETA_GetDestAddr(void);

/*! \brief Driver de-initialization */
void RNETA_Deinit(void);

/*! \brief Driver initialization */
void RNETA_Init(void);



#endif /* SOURCES_COMMON_RNET_APP_H_ */
