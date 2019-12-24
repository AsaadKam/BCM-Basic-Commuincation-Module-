#ifndef UART_USER_INTERFACE_H_
#define UART_USER_INTERFACE_H_

/*- Includes---------------------------------------------------------*/

#include "Data_types.h"

/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/****NEEDED TO USE UART WITH COUNT OR ISR****/
#define COUNTER                         1
#define FLAG                            2
#define CALLBACK                        3

#ifndef UART_ISR_WITH_FLAG
#define UART_ISR_WITH_FLAG COUNTER
#endif 


#if UART_ISR_WITH_FLAG==FLAG
extern volatile uint8_t gu8_Uart_rec_char_flag;
extern volatile uint8_t gu8_Uart_send_char_flag;
#elif UART_ISR_WITH_FLAG==COUNTER
extern volatile uint8_t gu8_Uart_rec_char_counter;
extern volatile uint8_t gu8_Uart_send_char_counter;
#endif

/*- UART User Data types --------------------------------------------*/

/***Structure of config*****/
typedef struct
{
uint8_t  Trasmit;
uint8_t  Reciever;
uint8_t  BaudRate;
uint8_t  Parity;
uint8_t  Stop;
uint8_t  Data_size;
uint8_t  InterruptMode;

}UART_Confg_Stuct_t;

/***UART_ERROR_TYPE****/	
typedef uint8_t UART_Error_t ;
typedef uint8_t UART_TRANS_STATE_t;
typedef uint8_t UART_TRANS_REC_STATE_t;
/*- Defines --------------------------------------------------------*/

/******Trasmit*********/
#define UART_trasmit_Enable	                       13
#define UART_trasmit_Disable			           14
/******Reciever*********/
#define UART_Receive_Enable 	                   15
#define UART_Receive_Disable			           16
/****(Baud Rate Adjust speed of UART)****/
#define _bps_2400_    207U
#define _bps_4800_    103U
#define _bps_9600_    51U
#define _bps_14.4k_   34U
#define _bps_19.2k_   25U
#define _bps_28.8k_   16U
#define _bps_38.4k_   12U
#define _bps_57.6k_   8U
#define _bps_76.8k_   6U
#define _bps_115.2k_  3U
#define _bps_230.4k_  1U
#define _bps_250k_    1U
#define _bps_0.5M_    0U
          
/*** parity ***/
#define UART_Parity_Disabled                       0
#define UART_Parity_Even                           1
#define UART_Parity_Odd                            2
/*** Stop bit***/
#define UART_One_Stop_bit                          3
#define UART_two_Stop_bit                          4
/**Data_size**/
#define UART_Frame_5_bit_                          5
#define UART_Frame_6_bit_                          6
#define UART_Frame_7_bit_                          7
#define UART_Frame_8_bit_                          8
#define UART_Frame_9_bit_                          9
/**interrupt or polling mode**/
#define UART_Interrupt_mode_enable	               10  
#define UART_Polling_mode_enable	               11 		
/***UART_ERRORs****/
#define  UART_ERROR_NULL_POINTER                    12
/***For setCallbackfunction***/
#define UART_HAS_NO_TX_ISR                         NullPointer
#define UART_HAS_NO_RX_ISR                         NullPointer



/*- FUNCTION DECLARATIONS -------------------------------------------------*/


extern UART_Error_t UART_SetCallBack(PntrToFunc_t PntrToFunc_Copy_UART_tX_USER_ISR,PntrToFunc_t PntrToFunc_Copy_UART_RX_USER_ISR);
/*_______________________________________________________________________________________________________________________________*/
/*Description: It initiates the UART from pointer to configuration of UART
 * Input     : (char_t* pchar_index)It takes pointer to char
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern UART_Error_t UART_Init(UART_Confg_Stuct_t* pstr_Config_UART);
/*_______________________________________________________________________________________________________________________________*/
/*Description: It transmites character through UART
 * Input     : (char_t pchar_index)It takes  char
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern UART_Error_t UART_SendByte(uint8_t u8_Byte_UART);
/*_______________________________________________________________________________________________________________________________*/
/*Description: It transmites string through UART
 * Input     : Two paraameters 
 *              1-(char_t* pchar_index)It takes pointer to char 
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern UART_Error_t UART_SendString(uint8_t* pchar_index);
/*_______________________________________________________________________________________________________________________________*/
/*Description: It receives character from  UART
 * Input     : (char_t* pchar_index)It takes pointer to char
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern UART_Error_t UART_RecByte(uint8_t* pchar_index);
/*uint8_t UART_Print_Float(float32_t float32_FloatNumber);*/
extern UART_TRANS_STATE_t  UART_BYTE_TRASMITTED(void);
/*- FUNCTION-LIKE MACROS -----------------------------------*/

#define UART_Print_Float(N)         UART_SendString(ConvertFloatToString(N))


#endif