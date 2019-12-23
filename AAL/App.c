/*
 * Transimter.c
 *
 * Created: 17/12/2019 18:33:53
 *  Author: Asaad
 */ 
/*- INCLUDES ----------------------------------------------*/
#include"BCM.h"
#include"BCM_PostLConfig.h"
/*- LOCAL MACROS ------------------------------------------*/
#define BCM_ARR_SIZE 15/*"Mohamed Hesham"*/
/*- LOCAL Dataypes ----------------------------------------*/
/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
/*- GLOBAL STATIC VARIABLES -------------------------------*/
/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
/*- APIs IMPLEMENTATION -----------------------------------*/
int main()
{
	/*The array that we will send to the BCM receiver*/
	uint8_t u8_BCM_array[BCM_ARR_SIZE]="Mohamed Hesham";
    /*Initalize the BCM*/
    /*BCM_Init(pstr_Transimter_config);*/

	
	while(1)
	{
		/*BCM_Send(u8_BCM_array,BCM_ARR_SIZE);*/
		/*BCM transmiter mangaer start it's work */
		BCM_TxDispatcher();
	}	
}

