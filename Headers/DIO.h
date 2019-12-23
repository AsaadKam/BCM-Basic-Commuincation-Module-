/*
 *  DIO.h
 *  Created: 02/11/2019 00:35:59
 *  Author: Asaad
 */ 


#ifndef DIO_H_
#define DIO_H_

#include"BitManipulation.h"
#include"DATA_types.h"
#include"DIO.h"

/***************************************************************/
/*                  GENERAL_PARPOUS_INPUT_OUTPUT               */
/***************************************************************/

#include "Atmega32Registers.h"

#define PinsNeeded  32U
/* _________________DIO PINs__________________*/
#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7
#define B0 8
#define B1 9
#define B2 10
#define B3 11
#define B4 12
#define B5 13
#define B6 14
#define B7 15
#define C0 16
#define C1 17
#define C2 18
#define C3 19
#define C4 20
#define C5 21
#define C6 22
#define C7 23
#define D0 24
#define D1 25
#define D2 26
#define D3 27
#define D4 28
#define D5 29
#define D6 30
#define D7 31

#define P0          0
#define P1          1
#define P2          2
#define P3          3
#define P4          4
#define P5          5
#define P6          6
#define P7          7
#define P8          8
#define P9          9
#define P10         10//INT2
#define P11         11
#define P12         12
#define P13         13
#define P14         14
#define P15         15
#define P16         16
#define P17         17
#define P18         18
#define P19         19
#define P20         20
#define P21         21
#define P22         22
#define P23         23
#define P24         24
#define P25         25
#define P26         26//INT0
#define P27         27//INT1
#define P28         28
#define P29         29
#define P30         30
#define P31         31


#define No_of_pins  No_of_ports*PortSize

#define CPU_FLAG_Register                     SREG
#define INT_BIT                               I

#define ReadRegisterA                         PINA
#define WriteRegisterA                        PORTA
#define DirectionRegisterA                    DDRA
 
#define ReadRegisterB                         PINB
#define WriteRegisterB                        PORTB
#define DirectionRegisterB                    DDRB

#define ReadRegisterC                         PINC
#define WriteRegisterC                        PORTC
#define DirectionRegisterC                    DDRC

#define ReadRegisterD                         PIND
#define WriteRegisterD                        PORTD
#define DirectionRegisterD                    DDRD

#define ExternalInterruptRegister             GICR

#define ExternalInterrupt_2_ENABLE            INT2
#define ExternalInterrupt_0_ENABLE            INT0
#define ExternalInterrupt_1_ENABLE            INT1

#define ExternalInterruptSenseCntrlRegister_1 MCUCR

#define ExternalInterrupt_1_LOW_LEVEL         0b00000000
#define ExternalInterrupt_1_LOGICAL_CHANGE    0b00000100
#define ExternalInterrupt_1_RISING            0b00001000
#define ExternalInterrupt_1_FALLING           0b00001100
#define ExternalInterrupt_0_LOW_LEVEL         0b00000000
#define ExternalInterrupt_0_LOGICAL_CHANGE    0b00000001
#define ExternalInterrupt_0_RISING            0b00000010
#define ExternalInterrupt_0_FALLING           0b00000011

#define ExternalInterruptSenseCntrlRegister_2 MCUCSR

#define ExternalInterrupt_2_FALLING           0b00000000
#define ExternalInterrupt_2_RISING            0b01000000

/*
#define ReadRegisterE       PINE
#define WriteRegisterE      PORTE
#define DirectionRegisterE  DDRE

#define ReadRegisterF       PINF
#define WriteRegisterF      PORTF
#define DirectionRegisterF  DDRF
*/




/*_____________________________DIO_DIRECTION________________________________*/
#define OUTPUT 1
#define INPUT 0

/*______________________________DIO_DATA_________________________________*/
#define HIGH 1
#define LOW 0

/*________________________________________________________________*/
/******************************************************************/
/*                        ERROR STATUS                            */
/******************************************************************/
#define ERROR_OK     0
#define ERROR_NOK    1

#define LOWER_NIBBLE  0
#define HIGHER_NIBBLE 1

#define SHIFTED_LEFT 0
#define NOT_SHIFTED  1

//Macro
#define  EnableGeneralInterrupt()    SET_BIT(CPU_FLAG_Register,INT_BIT)

//Functions
uint8_t DIO_INIT_PORT(uint8_t por,uint8_t direction); // function used to initiate data direction of a given port.....  ex:- fun(LCD_PORT,INPUT)

uint8_t DIO_INIT_Pin(uint8_t pin, uint8_t direction); // function used to initiate data direction a single pin in a given register.....ex:- fun(KEY_BAD_PORT,6,INPUT)

uint8_t DIO_Init_Nibble(uint8_t por,uint8_t nibble,uint8_t direction); // function to initiate data direction of nibble in a given port.....  ex:- fun(SEVEN_SEGGMENT_PORT,LOWER_NIBBLE,OUTPUT)

uint8_t DIO_Read_Port (uint8_t por, uint8_t * ReadData); // function returns port state.....  ex:- fun(LCD_PORT)

uint8_t DIO_Read_Pin (uint8_t pin, uint8_t * ReadData); // function that returns the value of a pin in a register.....  ex:- fun(LCD_PORT,LCD_RS_PIN)

uint8_t DIO_Read_Nibble(uint8_t por,uint8_t nibble,uint8_t shifted_left_or_not); // this function is used to read a nibble ....ex:- fun(LCD_DATA_PORT,HIGHER_NIBBLE,NOT_SHIFTED)

uint8_t DIO_Write_Port (uint8_t por,uint8_t Data); // function to write data to given port.....  ex:- fun(LCD_PORT,99)

uint8_t DIO_Write_Pin(uint8_t pin,uint8_t BitValue); // function used to.....  ex:- fun(LCD_PORT,LCD_ENABLE_PIN,1)

uint8_t DIO_Write_Nibble(uint8_t por ,uint8_t lower_or_higher_nibble,uint8_t data); // this function is used to write on nibble ... ex:- fun(LCD_DATA_PORT,LOWER_NIBBLE,'M')

uint8_t DIO_toggle_Port(uint8_t por); // this function is used to toggle defined port.....  ex:- fun(LED_LINE_PORT)

uint8_t DIO_toggle_Pin(uint8_t pin); // this function is used to toggle pin in a defined port .....  ex:- fun(LED_PORT,LED_PIN)

uint8_t DIO_Activate_Pullup (uint8_t Pin_Number);






#endif/* DIO_H_ */

 