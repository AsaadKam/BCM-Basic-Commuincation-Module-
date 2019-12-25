/*
 *  BCM.h
 *  Created: 21/12/2019 5:36:45 PM
 *  Author: Asaad
 */ 


#ifndef BCM_H_
#define BCM_H_

/*- INCLUDES -----------------------------------------------*/
#include"BCM_USER_INTERFACE.h"
#include"UART.h"
#include"Data_Types.h"
/*- Defines ----------------------------------------------*/
/***Externs defines for BCM***/
#define  gu8_BCM_Uart_send_char_counter   gu8_Uart_send_char_counter
#define  gu8_BCM_Uart_rec_char_counter    gu8_Uart_rec_char_counter
/***BCM STATUS***/
#define BCM_RX_UNLOCKED                           0 
#define BCM_RX_LOCKED                             1
#define BCM_RX_IDLE                               2
#define BCM_RX_REQ_NOT_CONFIRMED_BUFFER_IS_LOCKED 3
#define BCM_RX_ID_RECIEVED_OK                     4
#define BCM_RX_ID_RECIEVED_NOK                    5
#define BCM_RX_SIZE_RECEIEVED_OK                  6
#define BCM_RX_SIZE_RECEIEVED_NOK                 7
#define BCM_RX_BUFFER_RECEIEVED_CHECKSUM_OK       8
#define BCM_RX_BUFFER_RECEIEVED_CHECKSUM_NOK      9
#define BCM_RX_REQ_NOT_CONFIRMED                 10
#define BCM_RX_REQ_NOT_CONFIRMED_CHANNEL_OFF     11
#define BCM_RX_REQ_NOT_CONFIRMED_SIZE            12
#define BCM_RX_REQ_CONFIRMED                     13
#define BCM_RX_FIST_BYTE_SIZE_RECIEVED_OK        14
#define BCM_RX_DATA_IN_BUFFER_RECIEVED           15

 
/***BCM TX STATUS***/
  


#define BCM_TX_BUFFER_SENDING                    16
#define BCM_TX_BUFFER_SENT                       17
#define BCM_TX_CHECKSUM_SENT                     18
#define BCM_TX_REQ_NOT_CONFIRMED_SIZE            19
#define BCM_TX_REQ_NOT_CONFIRMED_CHANNEL_OFF     20
#define BCM_TX_REQ_CONFIRMED                     21
#define BCM_TX_IDLE                              22
#define BCM_TX_LOCKED                            23
#define BCM_TX_UNLOCKED                          24
#define BCM_TX_FREE_TO_USE_AGAIN                 25
#define BCM_TX_ID_SENT                           26
#define BCM_TX_SIZE_SENT                         27
  
#endif