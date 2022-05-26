#include <xc.h>
#include "analog.h"
#include "config.h"
#include "lcd.h"
#include "sensor.h"

void analog_init (void) //inicialização das configurações de conversão analógico para digital
{
    ANSEL = 0x0F;
    ADCON0bits.ADCS  = FOSC_8;
    ADCON0bits.ADON  = 1;
    ADCON1bits.ADFM  = BIT_DIR;
    ADCON1bits.VCFG0 = VSS_REF;
    ADCON1bits.VCFG1 = VDD_REF;       
}
unsigned int ADC_read (unsigned char canais) //conversão de analógico para digital em si
{
    unsigned int Valor_ADC = 0;
    ADCON0bits.CHS = canais < 4 ? canais : 0;
    ADCON0bits.GO = 1;
    
   
    while (ADCON0bits.GO);
    Valor_ADC = ADRESH;
    Valor_ADC <<=8;
    Valor_ADC += ADRESL;  
    return (Valor_ADC);
}
