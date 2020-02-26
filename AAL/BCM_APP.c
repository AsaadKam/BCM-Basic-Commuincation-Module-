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
#define BCM_ARR_SIZE 4U

/*- GLOBAL STATIC VARIABLES -------------------------------*/
static uint8_t u8_BCM_UART_BUFFER[BCM_ARR_SIZE]={0};
static uint8_t u8_BCM_array_2[BCM_ARR_SIZE]="tie1";

/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
static void UNLOCK_BUFFER(void)
{
	uint8_t u8_array_equal_flag=1U;

	if(u8_array_equal_flag==1U)
    {
		DIO_INIT_Pin(12,1);
		DIO_Write_Pin(12,1);
		BCM_RxUnlock(u8_BCM_UART_BUFFER);
	}
	else
	{
		DIO_INIT_Pin(12,1);
		DIO_Write_Pin(12,0);
	}
	
}

/*- APIs IMPLEMENTATION -----------------------------------*/
int main()
{

    /*Initalize the BCM*/
    BCM_Init(&BCM_UART_RX_Trans_Config);
	/***Setup BCM buuffer***/
    BCM_Setup_Receive(u8_BCM_UART_BUFFER,BCM_ARR_SIZE);
	
	while(1)
	{	
       /***Start BCM RX Dispatcher***/
       BCM_RxDispatcher(UNLOCK_BUFFER);
       
	}	
}


