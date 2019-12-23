/*
 *  BCM.c
 *  Created: 21/12/2019 5:36:45 PM
 *  Author: Asaad
 */ 



/*- INCLUDES ----------------------------------------------*/

#include"BCM.h"
#include"BCM_PostBConfig.h"
/*- LOCAL MACROS ------------------------------------------*/

/*- LOCAL Dataypes ----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/

/*- GLOBAL STATIC VARIABLES -------------------------------*/
static uint8_t* sgu8p_BCM_TX_BUFFER=NullPointer;
static uint8_t  sgu8_BCM_Buffer_size=0;
static uint8_t  sgu8_BCM_ID=0;
static uint8_t  sgu8_Transmition_State=0;
static uint8_t  sgu8_Reception_State=0;
static uint8_t  sgu8_Max_size_buffer=0;
/*- GLOBAL EXTERN VARIABLES -------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/

/*- APIs IMPLEMENTATION -----------------------------------*/
/*********Init Uart according needs of configuration of BCM*********/
BCM_ERROR_t BCM_Init(BCM_Config_t* pBCM_Config)
{
/**Set global varialbe for BCM_ID to be able to seen by other units and put in it the value***/

/***Check whether mode transmistion or reception***/

/*****Init UART as transmition or reception and the rest of UART configurations *****/

/****Initialize size of maximum numbers of bytes could be sent****/

	
}
BCM_ERROR_t BCM_Send(uint8_t* pu8_BCM_DATA,uint8_t u8_Size_of_Buffer)
{
	/*Check if the BCM unit is initalized to transmit or not**/ 
	/*Check if the unit is free to use for sending to unit by global variable
	   called BCM_TX_LOCKED and if it is locked get out returning error messege*/
	   
	/***Check the size of buffer is in the range of initalized configuration or not
	    by comparing size of buffer to the maximum size of buffer(sgu8_Max_size_buffer)***/
   
	/*Put in the value global pointer to char (sgu8p_BCM_TX_BUFFER )for dipatcher to send and
        	also global for size*/
			
}
BCM_ERROR_t BCM_Setup_Receive()
{
}
BCM_ERROR_t BCM_RxDispatcher()
{
}
void BCM_TxDispatcher()
{
	/*Check if the BCM unit is initalized to transmit or not**/ 
	/***Check what is the  status of transimition and according to it make the descion****/
	 /**Firstly,send the ID***/
	 /**Secondly,send the Size***/
	 /***thirdly,send byte by byte***/
	 /***Fourthly send the checksum***/
	
}
BCM_ERROR_t BCM_RxUnlock()
{
}