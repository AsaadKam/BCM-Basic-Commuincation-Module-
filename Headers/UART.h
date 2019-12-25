#ifndef UART_H_
#define UART_H_


/*- INCLUDES -----------------------------------------------*/

#include"UART_USER_INTERFACE.h"
#include"UART_PreLConfig.h"




/*-  MACROS -------------------------------------------------*/
/******************************************************************/
/*         Names of UART Registers and bits                      */
/******************************************************************/
#define CPU_FLAG_Register                          SREG
#define INT_BIT                                    I
 
#define UART_CNTRL_STATUS_REG_A	                   UCSRA
#define UART_CNTRL_STATUS_REG_B                    UCSRB
		 /***Interrupt Enable bits ***/
#define UART_RX_Complete_Interrupt_Enable          RXCIE
#define UART_TX_Complete_Interrupt_Enable          TXCIE
#define UART_Data_REG_Empty_Interrupt_Enable       UDRIE
#define UART_CNTRL_STATUS_REG_C	                   UCSRC

#define UART_Bit_Data_Size_bit_0                   UCSZ0               
#define UART_Bit_Data_Size_bit_1                   UCSZ1       
#define UART_STOP_setting_Bit                      USBS   
#define UART_Parity_Bit_0                          UPMO     
#define UART_Parity_Bit_1                          UPM1    

#define UART_Reciever_EN_BIT                       RXEN
#define UART_transimter_EN_BIT                     TXEN
#define UART_BAUD_RATE_REG_HIGH                    UBRRH
#define UART_BAUD_RATE_REG_LOW                     UBRRL
#define UART_DATA_REGISTER_EMPETY_FLAG             UDRE
#define UART_DATA_REGISTER                         UDR
#define UART_Bit_Data_Size_bit_2                   UCSZ2 
#define UART_Receive_Complete_FLAG                 RXC 
#define UART_Transmit_Complete_FLAG                TXC

/*________________________________________________________________*/



/*- GLOBAL EXTERN VARIABLES -------------------------------*/

#if UART_ISR_WITH_FLAG==FLAG
extern volatile uint8_t gu8_Uart_rec_char_flag;
extern volatile uint8_t gu8_Uart_send_char_flag;
#elif UART_ISR_WITH_FLAG==COUNTER
extern volatile uint8_t gu8_Uart_rec_char_counter;
extern volatile uint8_t gu8_Uart_send_char_counter;
#endif




#endif /* UART_H_ */