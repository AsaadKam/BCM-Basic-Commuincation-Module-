#ifndef _BCM_USER_INTERFACE_H_
#define _BCM_USER_INTERFACE_H_

#include"UART_USER_INTERFACE.h"
#include"Data_Types.h"


typedef  uint8_t BCM_ERROR_t;
typedef  uint8_t BCM_SINGLE_DATA_SIZE;

typedef  struct
{
	uint8_t  BCM_ID;
	uint32_t BCM_MAX_SIZE_OF_CHAR; 
	uint8_t  BCM_Type_of_Communication;
	uint8_t  BCM_Transimition_State;
	uint8_t  BCM_Reception_State;
	
}BCM_Config_t;

/************BCM_ID****************/
#define BCM_ID_0            '#'
#define BCM_ID_1            '@'
/*******BCM_Type_of_Communication******/
#define UART                0
#define SPI                 1
#define I2C                 2
#define CAN                 3
#define LIN                 4
#define Ethernet            5 

/**********BCM_Transimition*************/
#define BCM_Transimition_Enable     UART_trasmit_Enable     
#define BCM_Transimition_Disable    UART_trasmit_Disable

/**********BCM_Reception**************/  
#define BCM_Reception_Enable     UART_Receive_Enable    
#define BCM_Reception_Disable    UART_Receive_Disable
/**********Buffer IDS*******************/
#define BCM_BUFFER_ID_0       0
#define BCM_BUFFER_ID_1       1
#define BCM_BUFFER_ID_2       2

/*- FUNCTION DECLARATIONS ----------------------------------*/

extern BCM_ERROR_t BCM_Init(BCM_Config_t* Copy_pBCM_Config);
extern BCM_ERROR_t BCM_Send(uint8_t* Copy_pu8_BCM_TX_Buffer,uint8_t Copy_u8_BCM_TX_Buffer);
extern BCM_ERROR_t BCM_Setup_Receive(uint8_t* Copy_pu8_BCM_RX_Buffer,uint8_t Copy_u8_BCM_RX_Buffer);
extern BCM_ERROR_t BCM_TxDispatcher(void);
extern BCM_ERROR_t BCM_RxDispatcher(PntrToFunc_t Copy_PntrToFun_RxDispatcher);
extern BCM_ERROR_t BCM_RxUnlock(uint8_t*Copy_pu8_BCM_RX_Buffer);

#endif /*_BCM_USER_INTERFACE_H_*/