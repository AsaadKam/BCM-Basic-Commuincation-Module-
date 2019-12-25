/*
 * Transimter.c
 *
 * Created: 17/12/2019 18:33:53
 *  Author: Asaad
 */ 
/*- INCLUDES ----------------------------------------------*/
#include"BCM_PostBConfig.h"
#include"BCM.h"

/*- LOCAL MACROS ------------------------------------------*/
#define BCM_ARR_SIZE 4/*"tie"*/
/*- LOCAL Dataypes ----------------------------------------*/
/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
/*- GLOBAL STATIC VARIABLES -------------------------------*/
/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
/*- APIs IMPLEMENTATION -----------------------------------*/
int main()
{
	/*The array that we will send to the BCM receiver*/
	uint8_t u8_BCM_array[BCM_ARR_SIZE]="tie1";

	

    /*Initalize the BCM*/
    BCM_Init(&BCM_UART_TX_Trans_Config);
    BCM_Send(u8_BCM_array,BCM_ARR_SIZE);
    for(int i=0;i<2000;i++){};
	
	while(1)
	{	

		/*BCM transmiter mangaer start it's work */
		BCM_TxDispatcher();

        
	}	
}

