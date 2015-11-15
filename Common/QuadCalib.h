/*
 * QuadCalib.h
 *
 *  Created on: 15.11.2015
 *      Author: Cyrill
 *
 * This is the interface to the quadrature calibration module.
 */

#ifndef SOURCES_COMMON_QUADCALIB_H_
#define SOURCES_COMMON_QUADCALIB_H_

#include "Platform.h"

#if PL_CONFIG_HAS_SHELL
#include "CLS1.h"

uint8_t QUADCALIB_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
#endif



#endif /* SOURCES_COMMON_QUADCALIB_H_ */
