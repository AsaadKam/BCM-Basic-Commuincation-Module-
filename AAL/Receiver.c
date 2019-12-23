/*
 * Receiver.c
 *
 * Created: 17/12/2019 18:33:53
 *  Author: Asaad
 */ 
/*- INCLUDES ----------------------------------------------*/
#include""BCM.h"
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
    uint8_t u8_BCM_array[BCM_ARR_SIZE]={0};	
    /*Initalize the BCM*/
    BCM_Init(pstr_Receiever_config);
    
	while(1)
	{

		/*BCM reciever mangaer start it's work */		
		BCM_RxDispatcher();
		/**/
		BCM_Setup_Recevie();
		BCM_RxUnlock();
		
	}
}

