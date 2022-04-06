/*
 * File:   analog.c
 * Author: 21193444
 *
 * Created on 17 de Março de 2022, 09:46
 */


#include <xc.h>
#include <pic16f887.h>
#include "analog.h"

void analog_init (void)
{
    ANSEL = 0x0F;
    ADCON0bits.ADCS  = FOSC_8;
    ADCON0bits.ADON  = 1;
    ADCON1bits.ADFM  = BIT_DIR;
    ADCON1bits.VCFG0 = VSS_REF;
    ADCON1bits.VCFG1 = VDD_REF;       
}
unsigned int sinal (unsigned char canais)
{
    unsigned int Valor_ADC = 0;
    float conversao;
    float val;
    ADCON0bits.CHS = canais < 5 ? canais : 0;
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO);
    Valor_ADC = ADRESH;
    Valor_ADC <<=8;
    Valor_ADC += ADRESL;
    val = Valor_ADC;
    conversao = ((val*500)/1023);  
    return (conversao);
}
