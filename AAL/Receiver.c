/*
 * Receiver.c
 *
 * Created: 17/12/2019 18:33:53
 *  Author: Asaad
 */ 
/*- INCLUDES ----------------------------------------------*/
#include"BCM_PostBConfig.h"
#include"BCM.h"

/*- LOCAL MACROS ------------------------------------------*/
#define BCM_ARR_SIZE 3/*"tie"*/
/*- LOCAL Dataypes ----------------------------------------*/
/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
/*- GLOBAL STATIC VARIABLES -------------------------------*/
/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
/*- APIs IMPLEMENTATION -----------------------------------*/
int main()
{
	/*The array that we will send to the BCM receiver*/
	uint8_t u8_BCM_array_1[BCM_ARR_SIZE]="tie";
	uint8_t u8_BCM_array_2[BCM_ARR_SIZE]="tea";
    /*Initalize the BCM*/
    BCM_Init(&BCM_UART_TX_Trans_Config);
    DIO_INIT_Pin(0,1);
    BCM_Setup_Receive(u8_BCM_array_1,3);
	while(1)
	{	

        
	}	
}


