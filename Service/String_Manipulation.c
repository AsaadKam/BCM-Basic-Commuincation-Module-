/*- INCLUDES ----------------------------------------------*/
#include"Data_Types.h"
/*- LOCAL MACROS ------------------------------------------*/
/*- LOCAL Dataypes ----------------------------------------*/
/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
char_t TransformIntToString(long long int Number,char_t* str);

/*- GLOBAL STATIC VARIABLES -------------------------------*/
/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
char_t TransformIntToString(long long int Number,char_t* str)
{
    uint8_t digits=0;
    while(Number/(long long int)pow(10,digits++));
    digits--;
    char_t index=0;
    while (Number) 
    { 
        str[(digits-1)-index] = (Number%10) + '0'; 
        Number= Number/10; 
        index++;
    } 
    return index;
}

/*- APIs IMPLEMENTATION -----------------------------------*/


char_t* ConvertFloatToString(double FloatNumber )
{ 
    static char_t FloatString[40],index=0;
    long int  OverZeroValue=FloatNumber,UnderZeroValue=0,countForOver=0,countForUnder=0;
    while(FloatNumber*pow(10,countForUnder)-(long long int )((FloatNumber)*pow(10,countForUnder++))!=0.0);
    countForUnder--;
    UnderZeroValue=(FloatNumber-OverZeroValue)*(long long int )pow(10,countForUnder);
    index+=TransformIntToString(OverZeroValue,FloatString+index);
    FloatString[index++]='.';
    index+=TransformIntToString(UnderZeroValue,FloatString+index);
    FloatString[index]='\0';
    return FloatString;
}
