#ifndef ANALOG_H
#define	ANALOG_H
#include <xc.h>

//Comandos e endereços de pinos analógicos\\
//Definição de frequência
#define FOSC_2    0x0
#define FOSC_8    0x1
#define FOSC_32   0x2
#define FCR       0x3

//Definição de endereços analógicos
#define CH0      0x0
#define CH1      0x1
#define CH2      0x2
#define CH3      0x3
#define CH4      0x4
#define CH5      0x5
#define CH6      0x6
#define CH7      0x7
#define CH8      0x8
#define CH9      0x9
#define CH10     0xA
#define CH11     0xB
#define CH12     0xC
#define CH13     0xD

//Definição de comandos
#define CVREF   0xE //Habilita o comparador - Desnecessário
#define REF_FIX 0xF //Tensão fixa (0.6V) para calibragem?
#define BIT_DIR 1   //Byte justificado a direita
#define BIT_ESQ 0   //Byte justificado a esquerda
#define CH2_VSS 1   //Define AN2 como pino referencial VSS
#define CH3_VDD 1   //Define AN3 como pino referencial VDD
#define VSS_REF 0   //Define VSS como pino referencial padrão
#define VDD_REF 0   //Define VDD como pino referencial padrão
void            analog_init (void);
unsigned int    sinal       (unsigned char canais);
unsigned int    Valor_ADC   (void);
unsigned int    conversao   (unsigned int Valor_ADC);
#endif	/* XC_HEADER_TEMPLATE_H */

