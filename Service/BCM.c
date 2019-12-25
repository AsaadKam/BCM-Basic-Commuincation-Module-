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
static uint8_t*sgu8p_BCM_TX_BUFFER=NullPointer;
static uint8_t  sgu8_BCM_ID=BCM_ID_0;
static uint8_t  sgu8_BCM_TX_State=0;
static uint8_t  sgu8_BCM_RX_State=0;
static uint32_t sgu32_BCM_Max_size_buffer=0;
static uint32_t sgu32_BCM_TX_BUFFER_SIZE=0;
static uint32_t sgu32_BCM_RX_BUFFER_SIZE=0;
static uint8_t  sgu8_BCM_TX_STATUS=BCM_TX_IDLE;
static uint8_t  sgu8_BCM_RX_STATUS=BCM_RX_IDLE;
static uint8_t  sgu8_BCM_Type_of_communication=0;
static uint8_t  sgu64_BCM_RX_lOCKED[255]={BCM_RX_UNLOCKED};
static uint8_t  sgu8_BCM_RX_lOCKED_INDEX=0;
static uint8_t  sgu8_BCM_Current_Buffer_ID=0U;
static uint8_t volatile  sgu8_BCM_TX_FLAG=0U,sgu8_BCM_CheckSum;
static volatile uint8_t volatile* sgu8p_BCM_RX_BUFFER=NullPointer;
static volatile uint32_t  sgu32_BCM_RX_BUFFER_INDEX=0,sgu32_BCM_RX_Buffer=0;

/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
/*- APIs IMPLEMENTATION -----------------------------------*/

/*********Called Back function of BCM****************/
/*****BCM UART RECEIVER CALL BACK FUNCTION IN ISR*****/
void BCM_UART_REC_ISR(void)
{
	
/* 	DIO_INIT_Pin(5,1);
	DIO_Write_Pin(5,1); */
	
	UART_RecByte(&sgu32_BCM_RX_Buffer);
	/***If my state is BCM_RX_REQ_CONFIRMED***/
	if(BCM_RX_REQ_CONFIRMED==sgu8_BCM_RX_STATUS)
	{
		/***Check the byte that have sent is The ID Byte***/
		if(sgu8_BCM_ID==sgu32_BCM_RX_Buffer)
		{
			sgu8_BCM_RX_STATUS=BCM_RX_ID_RECIEVED_OK;
		}
		else
		{
		}
	}
	/***If my state is BCM_RX_ID_RECIEVED_OK***/
	else if(BCM_RX_ID_RECIEVED_OK==sgu8_BCM_RX_STATUS)
	{
		/***Check the first byte of size is ok***/
		if(sgu32_BCM_RX_BUFFER_SIZE==sgu32_BCM_RX_Buffer)
		{
		    /*DIO_INIT_Pin(5,1);
	        DIO_Write_Pin(5,1);*/
			
			sgu8_BCM_RX_STATUS=BCM_RX_FIST_BYTE_SIZE_RECIEVED_OK;
		}
		else
		{
		}		
	}
	/***If my state is BCM_RX_FIST_BYTE_SIZE_RECIEVED_OK***/
	else if(BCM_RX_FIST_BYTE_SIZE_RECIEVED_OK==sgu8_BCM_RX_STATUS)
	{
		/***Check the second byte of size is ok***/
		if((sgu32_BCM_RX_BUFFER_SIZE>>8)== sgu32_BCM_RX_Buffer)
		{
/* 		    DIO_INIT_Pin(5,1);
	        DIO_Write_Pin(5,1); */
			sgu8_BCM_RX_STATUS=BCM_RX_SIZE_RECEIEVED_OK;
		}
		else
		{
		}		
	}
	/***If my state is BCM_RX_SIZE_RECEIEVED_OK***/
	else if(BCM_RX_SIZE_RECEIEVED_OK==sgu8_BCM_RX_STATUS)
	{
		/***Write bytes recieved in the buffer***/
		if(sgu32_BCM_RX_BUFFER_INDEX<sgu32_BCM_RX_BUFFER_SIZE)
		{

			sgu8p_BCM_RX_BUFFER[sgu32_BCM_RX_BUFFER_INDEX]=sgu32_BCM_RX_Buffer;
			sgu8_BCM_CheckSum+=sgu32_BCM_RX_Buffer;
			sgu32_BCM_RX_BUFFER_INDEX++;
			/*DIO_INIT_Pin(5,1);
			  DIO_toggle_Pin(5);  */
			
		}
		else if(sgu32_BCM_RX_BUFFER_INDEX==sgu32_BCM_RX_BUFFER_SIZE)
		{
			if(sgu32_BCM_RX_Buffer==sgu8_BCM_CheckSum)
			{
/* 				DIO_INIT_Pin(5,1);
	            DIO_Write_Pin(5,1); */
				sgu8_BCM_RX_STATUS=BCM_RX_BUFFER_RECEIEVED_CHECKSUM_OK;
			}
			else
			{
				sgu8_BCM_RX_STATUS=BCM_RX_BUFFER_RECEIEVED_CHECKSUM_NOK;				
			}
			sgu8_BCM_CheckSum=0U;
			sgu32_BCM_RX_BUFFER_INDEX=0U;
		}		
	}
	else
	{
	}
}
/*****BCM UART TRANSIMTER CALL BACK FUNCTION IN ISR****/
void BCM_UART_TRANS_ISR(void)
{
	sgu8_BCM_TX_FLAG=1U;
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
		sgu8_BCM_TX_State=Copy_pBCM_Config->BCM_Transimition_State;
		sgu8_BCM_RX_State=Copy_pBCM_Config->BCM_Reception_State;
		/******************************************
		 * Check the type of communication and    * 
		 * whether it is transmision or reception * 
		 * or both of them and start initializtion*
		 ******************************************/
		 if(sgu8_BCM_Type_of_communication==UART)
		 {
		   
			 DIO_INIT_Pin(4,1);
			 DIO_Write_Pin(4,1);
		
			 UART_Confg_Stuct_t BCM_UART_Config={sgu8_BCM_TX_State,
												 sgu8_BCM_RX_State,
												  _bps_9600_, 
												  UART_Parity_Disabled, 
												  UART_One_Stop_bit, 
												  UART_Frame_8_bit_,
												  UART_Interrupt_mode_enable};
		     UART_Init(&BCM_UART_Config);
             UART_SetCallBack(BCM_UART_TRANS_ISR,BCM_UART_REC_ISR);		 
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

		  
	}
	else
	{
    }
}
BCM_ERROR_t BCM_Send(uint8_t* Copy_pu8_BCM_TX_Buffer,uint8_t Copy_u8_BCM_TX_Buffer)
{

	/*Check if the unit is free to use for sending 
	to Reception unit by sgu8_BCM_TX_STATUS and if it
	is locked get out returning error messege   */
	if(BCM_TX_IDLE==sgu8_BCM_TX_STATUS)
	{	

		/*Check if the BCM unit is initalized to transmit or not**/ 
		if(sgu8_BCM_TX_State==BCM_Transimition_Enable)
		{

			/***Check the size of buffer is in the range of initalized configuration or not
			by comparing size of buffer to the maximum size of buffer(sgu8_Max_size_buffer)***/		
			if(Copy_u8_BCM_TX_Buffer<=sgu32_BCM_Max_size_buffer)
			{
	
				/*Put in the value global pointer to char (sgu8p_BCM_TX_BUFFER )for dipatcher to send and
				  also global for size and update status*/
				if(NullPointer!=Copy_pu8_BCM_TX_Buffer)
				{
					
					sgu8p_BCM_TX_BUFFER=Copy_pu8_BCM_TX_Buffer;
					sgu32_BCM_TX_BUFFER_SIZE=Copy_u8_BCM_TX_Buffer;
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
		if(Copy_u8_BCM_TX_Buffer<=sgu32_BCM_Max_size_buffer)
		{
			/*Put in the value global pointer to char (sgu8p_BCM_TX_BUFFER )for dipatcher to send and
			  also global for size and update status*/
			if(NullPointer!=Copy_pu8_BCM_TX_Buffer)
			{
				sgu8p_BCM_TX_BUFFER=Copy_pu8_BCM_TX_Buffer;
				sgu32_BCM_TX_BUFFER_SIZE=Copy_u8_BCM_TX_Buffer;
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
     if(BCM_RX_IDLE==sgu8_BCM_RX_STATUS)
    {
		DIO_INIT_Pin(6,1);
		DIO_Write_Pin(6,1);
		sgu8p_BCM_RX_BUFFER=Copy_pu8_BCM_RX_Buffer;
		if(Copy_pu32_BCM_RX_Buffer<=sgu32_BCM_Max_size_buffer)
		{
			DIO_INIT_Pin(7,1);
			DIO_Write_Pin(7,1);
		  
			/*Put in the value global pointer to char (sgu8p_BCM_RX_BUFFER)for dipatcher to send and
			  also global for size and update status*/
			if(NullPointer!=Copy_pu8_BCM_RX_Buffer)
			{
			    DIO_INIT_Pin(8,1);
			    DIO_Write_Pin(8,1);
				if(sgu8_BCM_RX_lOCKED_INDEX>0)
				{

					for(uint8_t u8_Index=0;u8_Index<sgu8_BCM_RX_lOCKED_INDEX;u8_Index++)
					{
						if(sgu64_BCM_RX_lOCKED[u8_Index]==Copy_pu8_BCM_RX_Buffer) 
						{
							sgu8_BCM_RX_STATUS=BCM_RX_REQ_NOT_CONFIRMED_BUFFER_IS_LOCKED;
							break;
						}
					}
				}
                else
                {
					DIO_INIT_Pin(13,1);
					DIO_Write_Pin(13,1);
				    sgu8p_BCM_RX_BUFFER=Copy_pu8_BCM_RX_Buffer;
				    sgu32_BCM_RX_BUFFER_SIZE=Copy_pu32_BCM_RX_Buffer;
					sgu64_BCM_RX_lOCKED[sgu8_BCM_RX_lOCKED_INDEX]=sgu8p_BCM_RX_BUFFER;
					sgu8_BCM_RX_lOCKED_INDEX++;
					sgu8_BCM_RX_STATUS=BCM_RX_REQ_CONFIRMED;
                }					

			}
			else
			{
			}
		}
		else
		{
		}
	}
	else
	{
	}
  		
}
BCM_ERROR_t BCM_RxDispatcher(PntrToFunc_t Copy_PntrToFun_RxDispatcher)
{
	if(BCM_RX_BUFFER_RECEIEVED_CHECKSUM_OK==sgu8_BCM_RX_STATUS)
	{
		Copy_PntrToFun_RxDispatcher();
		DIO_INIT_Pin(10,1);
		DIO_Write_Pin(10,1);
		sgu8_BCM_RX_STATUS=BCM_RX_IDLE;
	}
	else
	{
		
	}

}
BCM_ERROR_t BCM_TxDispatcher(void)
{
	static uint32_t su32_BCM_Data_Buffr_index=0;
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

		if(sgu8_BCM_TX_FLAG&&su8_BCM_Data_Size_index<2U)	
		{
			sgu8_BCM_TX_FLAG=0U;

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
		if(sgu8_BCM_TX_FLAG&&(su32_BCM_Data_Buffr_index<sgu32_BCM_TX_BUFFER_SIZE)) 
		{
			sgu8_BCM_TX_FLAG=0U;;
			UART_SendByte(sgu8p_BCM_TX_BUFFER[su32_BCM_Data_Buffr_index]);
			su8_BCM_TX_CheckSUM+=sgu8p_BCM_TX_BUFFER[su32_BCM_Data_Buffr_index];
			su32_BCM_Data_Buffr_index++;

		}
		/*Send Checksum and reset value of static variables and change state to idle */
		else if(sgu8_BCM_TX_FLAG&&(su32_BCM_Data_Buffr_index==sgu32_BCM_TX_BUFFER_SIZE))
		{
            sgu8_BCM_TX_FLAG=0U;
            UART_SendByte(su8_BCM_TX_CheckSUM);
			su32_BCM_Data_Buffr_index++;
			su8_BCM_Data_Size_index=0;
			su8_BCM_TX_CheckSUM=0;
		
		}

		else if(sgu8_BCM_TX_FLAG&&su32_BCM_Data_Buffr_index==4)
		{
			sgu8_BCM_TX_FLAG=0U;
			su32_BCM_Data_Buffr_index=0;
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
BCM_ERROR_t BCM_RxUnlock(uint8_t*Copy_pu8_BCM_RX_Buffer)
{
	/**Let the BCM_RX_STATUS unlock and ready writing the new packet**/
	if(sgu8_BCM_RX_lOCKED_INDEX>0)
	{

		for(uint8_t u8_Index=0;u8_Index<sgu8_BCM_RX_lOCKED_INDEX;u8_Index++)
		{

			if(sgu64_BCM_RX_lOCKED[u8_Index]==Copy_pu8_BCM_RX_Buffer) 
			{
			    DIO_INIT_Pin(14,1);
		        DIO_Write_Pin(14,1);
				sgu64_BCM_RX_lOCKED[u8_Index]=BCM_RX_UNLOCKED;
				sgu8_BCM_RX_lOCKED_INDEX--;
				break;
			}
		}
	}
}