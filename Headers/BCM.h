/*
 *  BCM.h
 *  Created: 21/12/2019 5:36:45 PM
 *  Author: Asaad
 */ 


#ifndef BCM_H_
#define BCM_H_

/*- INCLUDES -----------------------------------------------*/
#include"UART.h"
#include"Data_Types.h"
/*- CONSTANTS ----------------------------------------------*/
/*- PRIMITIVE TYPES ----------------------------------------*/
/*- ENUMS --------------------------------------------------*/
/*- STRUCTS AND UNIONS -------------------------------------*/
/*- FUNCTION-LIKE MACROS -----------------------------------*/
/*- FUNCTION DECLARATIONS ----------------------------------*/

void BCM_Init();
void BCM_Send();
void BCM_Setup_Receive();
void BCM_RxDispatcher();
void BCM_TxDispatcher();
void BCM_RxUnlock();
/*Packer[Command-Size-Data-CS]*/
#endif