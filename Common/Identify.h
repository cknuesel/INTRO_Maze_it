/*
 * Identify.h
 *
 *  Created on: 26.11.2015
 *      Author: tastyger
 */

#ifndef SOURCES_INTRO_COMMON_MASTER_IDENTIFY_H_
#define SOURCES_INTRO_COMMON_MASTER_IDENTIFY_H_

#include "Platform.h"

#if PL_CONFIG_HAS_IDENTIFY

typedef enum { /* do *not* change order of enumeration, they are used internally for a table index */
  ID_ROBO_MANU, /* instructor 'black' robot */
  ID_ROBO_CYRILL, /* lab 7 robot */
  ID_ROBO_NOF_ID_ROBOTS, /* sentinel to count number of entries */
  ID_ROBO_UNKNOWN, /* unknown robot, unknown ID */
  ID_ROBO_NONE /* initialization value, used internally */
} ID_Robots;

ID_Robots ID_WhichRobot(void);
void ID_Deinit(void);
void ID_Init(void);

#endif /* PL_CONFIG_HAS_IDENTIFY */


#endif /* SOURCES_INTRO_COMMON_MASTER_IDENTIFY_H_ */
