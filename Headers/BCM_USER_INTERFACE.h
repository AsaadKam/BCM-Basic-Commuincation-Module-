#ifndef _BCM_USER_INTERFACE_H_
#define _BCM_USER_INTERFACE_H_


#include"Data_Types.h"


typedef  uint8_t BCM_ERROR_t;
typedef  uint8_t BCM_SINGLE_DATA_SIZE;

typedef  struct
{
	uint8_t  BCM_ID;
	uint32_t BCM_MAX_SIZE_OF_CHAR; 
	uint8_t  BCM_Type_of_Communication;
	uint8_t  BCM_Transimition;
	uint8_t  BCM_Reception;
}BCM_Config_t;

/************BCM_ID****************/
#define BCM_ID_0            0
#define BCM_ID_1            1
/*******BCM_Type_of_Communication******/
#define UART                0
#define SPI                 1
#define I2C                 2
#define CAN                 3
#define LIN                 4
#define Ethernt             5 

/**********BCM_Transimition*************/
#define BCM_Transimition_Enable     6      
#define BCM_Transimition_Disable    7

/**********BCM_Reception**************/  
#define BCM_Reception_Enable     8      
#define BCM_Reception_Disable    9

/*- FUNCTION DECLARATIONS ----------------------------------*/

extern BCM_ERROR_t BCM_Init(BCM_Config_t* pBCM_Config);
extern BCM_ERROR_t BCM_Send(uint8_t* pu8_BCM_DATA,uint8_t u8_Size_of_Buffer);
extern BCM_ERROR_t BCM_Setup_Receive();
extern BCM_ERROR_t BCM_RxDispatcher();
extern void        BCM_TxDispatcher();
extern BCM_ERROR_t BCM_RxUnlock();

#endif /*_BCM_USER_INTERFACE_H_*/