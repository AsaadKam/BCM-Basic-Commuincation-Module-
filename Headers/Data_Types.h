/*
 *  Data_types.h
 *  Created: 11/1/2019 5:36:45 PM
 *  Author: Asaad
 */ 


#ifndef DATA_tYPES_H_
#define DATA_tYPES_H_


typedef   char                 char_t;
typedef   unsigned char       uint8_t;
typedef   signed char          int8_t;
typedef   unsigned short int uint16_t;
typedef   signed short int    int16_t;
typedef   unsigned int       uint32_t;
typedef   signed int          int32_t;
typedef   unsigned long      uint64_t;
typedef   signed long         int64_t;
typedef   float             float32_t;
typedef   double            float64_t;
typedef   long double      float128_t;
typedef   void(*PntrToFunc_t)(void);   

#define   NullPointer      ((void *)0)


#endif /* Data_types.h */