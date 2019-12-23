/*
 * Atmega32Registers.h
 *
 * Created: 04/11/2019 01:15:54
 *  Author: Asaad
 */ 


#ifndef ATMEGA32REGISTERS_H_
#define ATMEGA32REGISTERS_H_

#include "DATA_types.h"
#define  ATMEGA     32

#define  DataBus    8
#define  PortSize   DataBus
#define  No_of_ports 4

#define  EnableGeneralInterrupt()      SET_BIT(CPU_FLAG_Register,INT_BIT)

//TWI Registers
#define TWBR    ( *((volatile uint8_t* )(0X20)) )
#define TWSR    ( *((volatile uint8_t* )(0X21)) )
#define TWAR    ( *((volatile uint8_t* )(0X22)) )
#define TWDR    ( *((volatile uint8_t* )(0X23)) )
//ADC Registers
#define ADCL    ( *((volatile uint8_t* )(0X24)) )
#define ADCH    ( *((volatile uint8_t* )(0X25)) )
#define ADCSRA  ( *((volatile uint8_t* )(0X26)) )          
#define ADMUX   ( *((volatile uint8_t* )(0X27)) )
//Analog Comparator Registers
#define ACSR    ( *((volatile uint8_t* )(0X28)) )
//UART Registers
#define UBRRL   ( *((volatile uint8_t* )(0X29)) )
#define UCSRB   ( *((volatile uint8_t* )(0X2A)) )
#define UCSZ2    2
#define TXEN     3
#define RXEN     4
#define UDRIE    5
#define TXCIE    6
#define RXCIE    7
#define UCSRA   ( *((volatile uint8_t* )(0X2B)) )
#define UDRE     5
#define RXC      7
#define UDR     ( *((volatile uint8_t* )(0X2C)) )


//SPI Registers
#define SPCR    ( *((volatile uint8_t* )(0X2D)) )
#define SPSR    ( *((volatile uint8_t* )(0X2E)) )
#define SPDR    ( *((volatile uint8_t* )(0X2F)) )
//DIO Registers
#define PIND    ( *((volatile uint8_t* )(0X30)) )
#define DDRD    ( *((volatile uint8_t* )(0X31)) )
#define PORTD   ( *((volatile uint8_t* )(0X32)) )
#define PINC    ( *((volatile const uint8_t* )(0X33)) )
#define DDRC    ( *((volatile uint8_t* )(0X34)) )
#define PORTC   ( *((volatile uint8_t* )(0X35)) )
#define PINB    ( *((volatile const uint8_t* )(0X36)) )
#define DDRB    ( *((volatile uint8_t* )(0X37)) )
#define PORTB   ( *((volatile uint8_t* )(0X38)) )
#define PINA    ( *((volatile const uint8_t* )(0X39)) )
#define DDRA    ( *((volatile uint8_t* )(0X3A)) )
#define PORTA   ( *((volatile uint8_t* )(0X3B)) )
//EEPROM Registers
#define EECR    ( *((volatile uint8_t* )(0X3C)) )
#define EEDR    ( *((volatile uint8_t* )(0X3D)) )
#define EEARL   ( *((volatile uint8_t* )(0X3E)) )
#define EEARH   ( *((volatile uint8_t* )(0X3F)) )
//The rest of UART Registers
#define UCSRC   ( *((volatile uint8_t* )(0X40)) )
#define UCPOL    0
#define UCSZ0    1
#define UCSZ1    2
#define USBS     3
#define UPMO     4
#define UPM1     5
#define UMSEL    6
#define URSEL    7
#define UBRRH   ( *((volatile uint8_t* )(0X40)) )
#define WDTCR   ( *((volatile uint8_t* )(0X41)) )
//Asynchronous Timer Registers
#define ASSR    ( *((volatile uint8_t* )(0X42)) )
#define OCR2    ( *((volatile uint8_t* )(0X43)) )
#define TCNT2   ( *((volatile uint8_t* )(0X44)) )
#define TCCR2   ( *((volatile uint8_t* )(0X45)) )
//Timer1 Registers
#define ICR1	( *((volatile uint16_t* )(0X46)) )
#define ICR1L	( *((volatile uint8_t* )(0X46)) )
#define ICR1H   ( *((volatile uint8_t* )(0X47)) )
#define OCR1B   ( *((volatile uint16_t*)(0X48)) )
#define OCR1BL  ( *((volatile uint8_t* )(0X48)) )
#define OCR1BH  ( *((volatile uint8_t* )(0X49)) )
#define OCR1A   ( *((volatile uint16_t* )(0X4A)) )
#define OCR1AL  ( *((volatile uint8_t* )(0X4A)) )
#define OCR1AH  ( *((volatile uint8_t* )(0X4B)) )
#define TCNT1   ( *((volatile uint16_t* )(0X4C)) )
#define TCNT1L  ( *((volatile uint8_t* )(0X4C)) )
#define TCNT1H  ( *((volatile uint8_t* )(0X4D)) )
#define TCCR1B  ( *((volatile uint8_t* )(0X4E)) )
#define TCCR1A  ( *((volatile uint8_t* )(0X4F)) )
//Special Function Register
#define SFIOR   ( *((volatile uint8_t* )(0X50)) )
//On-Chip Debug Register
#define OCDR    ( *((volatile uint8_t* )(0X51)) )
////On-Chip Debug Register
#define OSCCAL  ( *((volatile uint8_t* )(0X51)) )
//TIMER0 Registers
#define TCNT0   ( *((volatile uint8_t* )(0X52)) ) 
#define TCCR0   ( *((volatile uint8_t* )(0X53)) )
//MCU Status and Control Registers
#define MCUCSR  ( *((volatile uint8_t* )(0X54)) )
#define MCUCR   ( *((volatile uint8_t* )(0X55)) )
//Register of TWO WIRE Control Register
#define TWCR    ( *((volatile uint8_t* )(0X56)) )

#define SPMCR   ( *((volatile uint8_t* )(0X57)) )
//Timer's Interrupt Flags
#define TIFR    ( *((volatile uint8_t* )(0X58)) )
#define TOV0    0
#define TOV1    2
#define TOV2    6
#define OCF0    1
#define TIMSK   ( *((volatile uint8_t* )(0X59)) )
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define TOIE2   6
//General Interrupt Flags
#define GIFR    ( *((volatile uint8_t* )(0X5A)) )
#define GICR    ( *((volatile uint8_t* )(0X5B)) )
#define INT1    7
#define INT0    6
#define INT2    5
//TIMER0 Output Compare Register
#define OCR0    ( *((volatile uint8_t* )(0X5C)) )
//Stack pointer Register
#define SPL     ( *((volatile uint8_t* )(0X5D)) )
#define SPH     ( *((volatile uint8_t* )(0X5E)) )
//Status Register
#define SREG    ( *((volatile uint8_t* )(0X5F)) )
#define I       7

/*
#define A           0
#define B           1
#define C           2
#define D           3
#define PORT(PORT_NAME)    ( *((volatile INT8U* )      (0X3B-3(PORT_NAME)) )
#define DDRA(PORT_NAME)    ( *((volatile INT8U* )      (0X3A-3(PORT_NAME)) )
#define PINA(PORT_NAME)    ( *((volatile const INT8U* )(0X39-3(PORT_NAME)) )
*/

//Timer Registers


#endif /* ATMEGA32REGISTERS_H_ */