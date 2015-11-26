/*
 * Pid.h
 *
 *  Created on: 20.11.2015
 *      Author: Cyrill
 */

#ifndef SOURCES_COMMON_PID_H_
#define SOURCES_COMMON_PID_H_

#include "Platform.h"
#if PL_CONFIG_HAS_PID

#if PL_CONFIG_HAS_LINE_FOLLOW
#define REF_NOF_SENSORS 6
#define REF_MIDDLE_LINE_VALUE  ((REF_NOF_SENSORS+1)*1000/2)
#define REF_MAX_LINE_VALUE     ((REF_NOF_SENSORS-1)*1000) /* maximum value for REF_GetLine() */

typedef enum {
  REF_LINE_NONE=0,     /* no line, sensors do not see a line */
  REF_LINE_STRAIGHT=1, /* forward line |, sensors see a line underneath */
  REF_LINE_LEFT=2,     /* left half of sensors see line */
  REF_LINE_RIGHT=3,    /* right half of sensors see line */
  REF_LINE_FULL=4,     /* all sensors see a line */
  REF_NOF_LINES        /* Sentinel */
} REF_LineKind;

REF_LineKind REF_GetLineKind(void);
#endif

#if PL_CONFIG_HAS_SHELL
#include "CLS1.h"
/*!
 * \brief Shell command line parser.
 * \param[in] cmd Pointer to command string
 * \param[out] handled If command is handled by the parser
 * \param[in] io Std I/O handler of shell
 */
uint8_t PID_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
#endif

/*!
 * \brief Performs PID closed loop calculation for the speed
 * \param currSpeed Current speed of motor
 * \param setSpeed desired speed of motor
 * \param isLeft TRUE if is for the left motor, otherwise for the right motor
 */
void PID_Speed(int32_t currSpeed, int32_t setSpeed, bool isLeft);

/*!
 * \brief Performs PID closed loop calculation for the line position
 * \param currPos Current position of wheel
 * \param setPos Desired wheel position
 * \param isLeft TRUE if is for the left wheel, otherwise for the right wheel
 */
void PID_Pos(int32_t currPos, int32_t setPos, bool isLeft);

/*! \brief Driver initialization */
void PID_Start(void);

/*! \brief Driver initialization */
void PID_Init(void);

/*! \brief Driver de-initialization */
void PID_Deinit(void);

#endif /* PL_HAS_PID */



#endif /* SOURCES_COMMON_PID_H_ */
