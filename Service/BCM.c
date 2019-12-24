/*
 *  BCM.c
 *  Created: 21/12/2019 5:36:45 PM
 *  Author: Asaad
 */ 



/*- INCLUDES ----------------------------------------------*/

#include"BCM.h"
#include"UART.h"
#include"DIO.h"
/*- LOCAL MACROS ------------------------------------------*/

/*- LOCAL Dataypes ----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/

/*- GLOBAL STATIC VARIABLES -------------------------------*/
static uint8_t* sgu8p_BCM_TX_BUFFER=NullPointer;
static volatile uint8_t volatile* sgu8p_BCM_RX_BUFFER=NullPointer;
static volatile uint8_t  sgu8_BCM_RX_BUFFER_INDEX=0;
static uint8_t  sgu8_BCM_ID=BCM_ID_0;
static uint8_t  sgu8_BCM_Transmition_State=0;
static uint8_t  sgu8_BCM_Reception_State=0;
static uint32_t sgu32_BCM_Max_size_buffer=0;
static uint32_t sgu32_BCM_TX_BUFFER_SIZE=0;
static uint32_t sgu32_BCM_RX_BUFFER_SIZE=0;
static uint8_t  sgu8_BCM_TX_STATUS=BCM_TX_IDLE;
static uint8_t  sgu8_BCM_RX_STATUS=BCM_RX_IDLE;
static uint8_t  sgu8_BCM_Type_of_communication=0;
static uint8_t  sgu8_BCM_RX_lOCKED=BCM_RX_UNLOCKED;
static uint8_t  sgu8_BCM_TX_lOCKED=BCM_TX_UNLOCKED;
/*- GLOBAL EXTERN VARIABLES -------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/

/*- APIs IMPLEMENTATION -----------------------------------*/
/*********Called Back function of BCM receiver***********/
void BCM_UART_REC_ISR(void)
{
   sgu8p_BCM_RX_BUFFER[sgu8_BCM_RX_BUFFER_INDEX]=UART_DATA_REGISTER;
   sgu8_BCM_RX_BUFFER_INDEX++;
	
}
/*********Init BCM*********/
BCM_ERROR_t BCM_Init(BCM_Config_t* Copy_pBCM_Config)
{
if(NullPointer!=Copy_pBCM_Config)
{
	/**Register  BCM_ID to be able to seen by other functions***/
	sgu8_BCM_ID=Copy_pBCM_Config->BCM_ID;
	/****Register size of maximum numbers of bytes could be sent for the other functions****/
	sgu32_BCM_Max_size_buffer=Copy_pBCM_Config->BCM_MAX_SIZE_OF_CHAR;
	/***Register in variable sgu8_BCM_Type_of_communication the type of comm. for the other functions ***/
	sgu8_BCM_Type_of_communication=Copy_pBCM_Config->BCM_Type_of_Communication;
	/***Register whether mode transmistion or reception***/
	sgu8_BCM_Transmition_State=Copy_pBCM_Config->BCM_Transimition_State;
	sgu8_BCM_Reception_State=Copy_pBCM_Config->BCM_Reception_State;
	/******************************************
	 * Check the type of communication and    * 
	 * whether it is transmision or reception * 
	 * or both of them and start initializtion*
	 ******************************************/
	 if(sgu8_BCM_Type_of_communication==UART)
	 {
	/*
		 DIO_INIT_Pin(15,1);
		 DIO_Write_Pin(15,1);
	*/
		 UART_Confg_Stuct_t BCM_UART_Config={sgu8_BCM_Transmition_State,
											 sgu8_BCM_Reception_State,
											  _bps_9600_, 
											  UART_Parity_Disabled, 
											  UART_One_Stop_bit, 
											  UART_Frame_8_bit_,
											  UART_Interrupt_mode_enable};
		 UART_Init(&BCM_UART_Config);
	 }
	 else if(sgu8_BCM_Type_of_communication==SPI)
	 {
	 }
	 else if(sgu8_BCM_Type_of_communication==I2C)
	 {
	 }
	 else if(sgu8_BCM_Type_of_communication==CAN)
	 {
	 }
	 else if(sgu8_BCM_Type_of_communication==LIN)
	 {
	 }
	 else if(sgu8_BCM_Type_of_communication==Ethernet)
	 {
	 }
	 else
	 {
	 }
	 /**If transmision state is reception setcallback for the called back
     	 function that we will form**/
	 if(sgu8_BCM_Reception_State==BCM_Reception_Enable)  UART_SetCallBack(UART_HAS_NO_TX_ISR,BCM_UART_REC_ISR);
	  
}
else
{
}
}
BCM_ERROR_t BCM_Send(uint8_t* Copy_pu8_BCM_TX_Buffer,uint8_t Copy_pu32_BCM_RX_Buffer)
{

	/*Check if the unit is free to use for sending 
	to Reception unit by sgu8_BCM_TX_STATUS and if it
	is locked get out returning error messege   */
	if(BCM_TX_IDLE==sgu8_BCM_TX_STATUS)
	{	

		/*Check if the BCM unit is initalized to transmit or not**/ 
		if(sgu8_BCM_Transmition_State==BCM_Transimition_Enable)
		{
			/***Check the size of buffer is in the range of initalized configuration or not
			by comparing size of buffer to the maximum size of buffer(sgu8_Max_size_buffer)***/		
			if(Copy_pu32_BCM_RX_Buffer<=sgu32_BCM_Max_size_buffer)
			{
				/*Put in the value global pointer to char (sgu8p_BCM_TX_BUFFER )for dipatcher to send and
				  also global for size and update status*/
				if(NullPointer!=Copy_pu8_BCM_TX_Buffer)
				{
					sgu8p_BCM_TX_BUFFER=Copy_pu8_BCM_TX_Buffer;
					sgu32_BCM_TX_BUFFER_SIZE=Copy_pu32_BCM_RX_Buffer;
					sgu8_BCM_TX_STATUS=BCM_TX_REQ_CONFIRMED;
				}
				else
				{
				}
			}
			else
			{
				sgu8_BCM_TX_STATUS=BCM_TX_REQ_NOT_CONFIRMED_SIZE;
			}
		}
		else
		{
			sgu8_BCM_TX_STATUS=BCM_TX_REQ_NOT_CONFIRMED_CHANNEL_OFF;		
		}
	
	}
	else if(BCM_TX_FREE_TO_USE_AGAIN==sgu8_BCM_TX_STATUS)
	{	
		/***Check the size of buffer is in the range of initalized configuration or not
		by comparing size of buffer to the maximum size of buffer(sgu8_Max_size_buffer)***/		
		if(Copy_pu32_BCM_RX_Buffer<=sgu32_BCM_Max_size_buffer)
		{
			/*Put in the value global pointer to char (sgu8p_BCM_TX_BUFFER )for dipatcher to send and
			  also global for size and update status*/
			if(NullPointer!=Copy_pu8_BCM_TX_Buffer)
			{
				sgu8p_BCM_TX_BUFFER=Copy_pu8_BCM_TX_Buffer;
				sgu32_BCM_TX_BUFFER_SIZE=Copy_pu32_BCM_RX_Buffer;
				sgu8_BCM_TX_STATUS=BCM_TX_REQ_CONFIRMED;
			}
			else
			{
			}
		}
		else
		{
			sgu8_BCM_TX_STATUS=BCM_TX_REQ_NOT_CONFIRMED_SIZE;
		}      
    }
	else
	{
	}

}
BCM_ERROR_t BCM_Setup_Receive(uint8_t* Copy_pu8_BCM_RX_Buffer,uint8_t Copy_pu32_BCM_RX_Buffer)
{
/*Check the size of buffer is in the range of   initalized 
  configuration or not by comparing size of buffer to the 
  maximum size of buffer(sgu8_Max_size_buffer)*/
  sgu8p_BCM_RX_BUFFER=Copy_pu8_BCM_RX_Buffer;
  if(Copy_pu32_BCM_RX_Buffer<=sgu32_BCM_Max_size_buffer)
  {
		/*Put in the value global pointer to char (sgu8p_BCM_RX_BUFFER )for dipatcher to send and
		  also global for size and update status*/
		if(NullPointer!=Copy_pu8_BCM_TX_Buffer)
		{
			sgu8p_BCM_RX_BUFFER=Copy_pu8_BCM_RX_Buffer;
			sgu32_BCM_RX_BUFFER_SIZE=Copy_pu32_BCM_RX_Buffer;
			sgu8_BCM_TX_STATUS=BCM_RX_REQ_CONFIRMED;
		}
		else
		{
		}
  }
  else
  {
  }
  		
}
BCM_ERROR_t BCM_RxDispatcher(void)
{
	
}
BCM_ERROR_t BCM_TxDispatcher(void)
{
	static uint32_t su32_BCM_Data_Buffr_index=0;;
	static uint8_t su8_BCM_Data_Size_index=0,su8_BCM_TX_CheckSUM=0;
	/***Check if the transmission is confirmed by BCM_SEND****/
    if(BCM_TX_REQ_CONFIRMED==sgu8_BCM_TX_STATUS)
	{
		UART_SendByte(sgu8_BCM_ID);
		sgu8_BCM_TX_STATUS=BCM_TX_ID_SENT;

	}
	/**Secondly,send the Size of packet***/
	else if(BCM_TX_ID_SENT==sgu8_BCM_TX_STATUS)
	{
		if(BIT_IS_SET(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG)&&(su8_BCM_Data_Size_index<2U))	
		{
			SET_BIT(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG);
			UART_SendByte(sgu32_BCM_TX_BUFFER_SIZE>>(su8_BCM_Data_Size_index*8U));
			su8_BCM_Data_Size_index++;
		}
		else if(su8_BCM_Data_Size_index==2U)
		{

			sgu8_BCM_TX_STATUS=BCM_TX_SIZE_SENT;
			su8_BCM_Data_Size_index=0;
		}
    }
	/**Send the packet with checksum**/
    else if(BCM_TX_SIZE_SENT==sgu8_BCM_TX_STATUS)
	{
        
        /*Send the data (byte by byte)that exists inside the buffer*/
		if(BIT_IS_SET(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG)&&(su32_BCM_Data_Buffr_index<sgu32_BCM_TX_BUFFER_SIZE)) 
		{
			SET_BIT(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG);
			UART_SendByte(sgu8p_BCM_TX_BUFFER[su32_BCM_Data_Buffr_index]);
			su8_BCM_TX_CheckSUM+=sgu8p_BCM_TX_BUFFER[su32_BCM_Data_Buffr_index];
			su32_BCM_Data_Buffr_index++;

		}
		/*Send Checksum and reset value of static variables and change state to idle */
		else if((su32_BCM_Data_Buffr_index==sgu32_BCM_TX_BUFFER_SIZE)&&BIT_IS_SET(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG))
		{
			SET_BIT(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG);
            UART_SendByte(su8_BCM_TX_CheckSUM);
			su32_BCM_Data_Buffr_index++;
			su8_BCM_Data_Size_index=0;
			su8_BCM_TX_CheckSUM=0;

		
		
		}

		else if(BIT_IS_SET(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG)&&su32_BCM_Data_Buffr_index==4)
		{
			su32_BCM_Data_Buffr_index=0;
			SET_BIT(UART_CNTRL_STATUS_REG_A,UART_Transmit_Complete_FLAG);
			sgu8_BCM_TX_STATUS=BCM_TX_FREE_TO_USE_AGAIN;
		}
		else
		{
		}
	}
	else
	{
	}

}
BCM_ERROR_t BCM_RxUnlock(void)
{
/**Let the BCM_RX_STATUS unlock and ready writing the new packet**/
sgu8_BCM_RX_STATUS=BCM_RX_IDLE;
}