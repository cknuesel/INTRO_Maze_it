/*
 * Identify.c
 *
 *  Created on: 26.11.2015
 *      Author: tastyger
 */

#include "Platform.h"
#if PL_CONFIG_HAS_IDENTIFY
#include "Identify.h"
#include "KIN1.h"

static ID_Robots currRobot = ID_ROBO_NONE;

static const KIN1_UID idTable[ID_ROBO_NOF_ID_ROBOTS] =
  {
      {0xFF, 0xFF, 0x4E, 0x45, 0x27, 0x99, 0x10, 0x02, 0x00, 0x2B}, /* ID_ROBO_MANU */
      {0xFF, 0xFF, 0x4E, 0x45, 0x27, 0x99, 0x10, 0x02, 0x00, 0xff}, /* ID_ROBO_CYRILL */
  };

static ID_Robots IdentifyRobot(void) {
  uint8_t res;
  KIN1_UID id;
  ID_Robots i, robo;

  robo = ID_ROBO_UNKNOWN;
  res = KIN1_UIDGet(&id);
  if (res==ERR_OK) {
    for(i=0; i<ID_ROBO_NOF_ID_ROBOTS; i++) {
      if (KIN1_UIDSame(&id, &idTable[i])) {
        robo = i; /* found it */
        break; /* get out of for() loop */
      }
    }
  }
  return robo;
}

ID_Robots ID_WhichRobot(void) {
  if (currRobot==ID_ROBO_NONE) {
    /* not checked ID, try to find matching robot */
    currRobot = IdentifyRobot();
  }
  return currRobot;
}

void ID_Deinit(void) {
  currRobot = ID_ROBO_NONE;
}

void ID_Init(void) {
  currRobot = ID_ROBO_NONE;
}
#endif /* PL_CONFIG_HAS_IDENTIFY */
