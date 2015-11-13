/*
 * Buzzer.c
 *
 *  Created on: 21.10.2015
 *      Author: Manuel
 */

#include "Platform.h"
#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#include "BUZ1.h"
#include "Trigger.h"
#include "UTIL1.h"
#if PL_CONFIG_HAS_SHELL
  #include "CLS1.h"
#endif

typedef struct {
  uint16_t buzPeriodTicks; /*!< number of trigger ticks for a PWM period */
  uint16_t buzIterationCntr; /*!< number of iterations */
} BUZ_TrgInfo;

static volatile BUZ_TrgInfo trgInfo;

static void BUZ_Toggle(void *dataPtr) {
  BUZ_TrgInfo *trgInfo = (BUZ_TrgInfo *)dataPtr;

  if (trgInfo->buzIterationCntr==0) {
    BUZ1_ClrVal(); /* turn buzzer off */
  } else {
    trgInfo->buzIterationCntr--;
    BUZ1_NegVal();
    (void)TRG_SetTrigger(TRG_BUZ_BEEP, trgInfo->buzPeriodTicks, BUZ_Toggle, trgInfo);
  }
}

uint8_t BUZ_Beep(uint16_t freq, uint16_t durationMs) {
  if (trgInfo.buzIterationCntr==0) { /* only if buzzer is not running right now */
    BUZ1_SetVal(); /* turn buzzer on */
    trgInfo.buzPeriodTicks = (1000*TRG_TICKS_MS)/freq;
    trgInfo.buzIterationCntr = durationMs/TRG_TICKS_MS/trgInfo.buzPeriodTicks;
    return TRG_SetTrigger(TRG_BUZ_BEEP, trgInfo.buzPeriodTicks, BUZ_Toggle, (void*)&trgInfo);
  } else {
    return ERR_BUSY;
  }
}

typedef struct {
  int freq; /* frequency */
  int ms; /* milliseconds */
} BUZ_Tune;

static const BUZ_Tune Melody[] =
{ /* freq, ms */
    {300,500},
    {500,200},
    {300,100},
    {200,300},
    {500,400},
    {300,100},
    {200,300},
    {300,100},
    {200,300},
    {500,400},
};

static void BUZ_Play(void *dataPtr) {
  int idx = (int)dataPtr;

  BUZ_Beep(Melody[idx].freq, Melody[idx].ms);
  idx++;
  if (idx<(sizeof(Melody)/sizeof(Melody[0]))) {
    TRG_SetTrigger(TRG_BUZ_TUNE, Melody[idx-1].ms/TRG_TICKS_MS, BUZ_Play, (void*)idx);
  }
}

uint8_t BUZ_PlayTune(void) {
  return TRG_SetTrigger(TRG_BUZ_TUNE, 1, BUZ_Play, (void*)0);
}


#if PL_CONFIG_HAS_SHELL
static uint8_t BUZ_PrintHelp(const CLS1_StdIOType *io) {
  CLS1_SendHelpStr((unsigned char*)"buzzer", (unsigned char*)"Group of buzzer commands\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  help|status", (unsigned char*)"Shows radio help or status\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  buz <freq> <time>", (unsigned char*)"Beep for time (ms) and frequency (kHz)\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  play tune", (unsigned char*)"Play tune\r\n", io->stdOut);
  return ERR_OK;
}

static uint8_t BUZ_PrintStatus(const CLS1_StdIOType *io) {
  (void)io; /* not used */
  return ERR_OK;
}

uint8_t BUZ_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io) {
  const unsigned char *p;
  uint16_t freq, duration;

  if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_HELP)==0 || UTIL1_strcmp((char*)cmd, (char*)"buzzer help")==0) {
    *handled = TRUE;
    return BUZ_PrintHelp(io);
  } else if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_STATUS)==0 || UTIL1_strcmp((char*)cmd, (char*)"buzzer status")==0) {
    *handled = TRUE;
    return BUZ_PrintStatus(io);
  } else if (UTIL1_strncmp((char*)cmd, (char*)"buzzer buz ", sizeof("buzzer buz ")-1)==0) {
    *handled = TRUE;
    p = cmd+sizeof("buzzer buz ")-1;
    if (UTIL1_ScanDecimal16uNumber(&p, &freq)==ERR_OK && UTIL1_ScanDecimal16uNumber(&p, &duration)==ERR_OK) {
      if (BUZ_Beep(freq, duration)!=ERR_OK) {
        CLS1_SendStr((unsigned char*)"Starting buzzer failed\r\n", io->stdErr);
        return ERR_FAILED;
      }
      return ERR_OK;
    }
  } else if (UTIL1_strcmp((char*)cmd, (char*)"buzzer play tune")==0) {
    *handled = TRUE;
    return BUZ_PlayTune();
  }
  return ERR_OK;
}
#endif /* PL_CONFIG_HAS_SHELL */

void BUZ_Deinit(void) {
  /* nothing to do */
}

void BUZ_Init(void) {
  BUZ1_SetVal(); /* turn buzzer off */
  trgInfo.buzPeriodTicks = 0;
  trgInfo.buzIterationCntr = 0;
}
#endif /* PL_CONFIG_HAS_BUZZER */


