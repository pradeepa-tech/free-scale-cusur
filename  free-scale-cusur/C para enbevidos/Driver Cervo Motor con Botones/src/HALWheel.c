/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            HALWheel.c
* version:         1.0
* created_by:      Continental
* date_created:    Ago 11 2011
*=============================================================================*/
/* DESCRIPTION : Source file for Abstraction layer for WHEEL                  */
/*============================================================================*/
/* FUNCTION COMMENT : Describes the functions for Abstraction Layer for WHEEL */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 11/ago/2011 |                               | Continental      */
/* Initial version for the Smart Car Race 2010 contest using Freescale        */
/* Bolero micro.                                                              */
/*============================================================================*/

#include "stdtypedef.h"
#include "sysinit.h"
#include "MALioapi.h"
#include "MALbeMIOS.h"
#include "MALPWM.h"
#include "HALKnob.h"

void init (void)
{

	SIU.PCR[64].R=0x100;
	SIU.PCR[65].R=0x100;
	SIU.PCR[66].R=0x100;
	SIU.PCR[67].R=0x100;
	
	SIU.PCR[48].R = 0x200; /* set PA[0] as input */
	SIU.PCR[50].R = 0x200; /* set PA[2] as input */
	SIU.PCR[52].R = 0x200; /* set PA[4] as input */

	
}

	
T_UWORD valor = 1000;
T_UWORD valor1 = 1000;



void WHEEL_Init(void);
void WHEEL_SetWheelPos(void);


void WHEEL_Init(void)
{
	InitPWM();
}
void WHEEL_SetWheelPos(void)
{
init();
/*	SetDutyCycle(KNOB_GetKnobValue());*/
	if(SIU.GPDI[64].R==0)
	{
		
		valor=100;
		
	}
	if(SIU.GPDI[65].R==0)
	{
		valor=350;
		
	}
	if(SIU.GPDI[66].R==0)
	{
		valor=600;
		}
	if(SIU.GPDI[67].R==0)
	{
		valor=1000;
		
	}
	SIU.GPDO[48].R = 1;
	SIU.GPDO[50].R = 1;
	SIU.GPDO[52].R = 0;
	
	SetDutyCycle(valor);
	
	SetDutyCycle1(valor1);
}
