/*
 * File:   LM35.c
 * Author: 21193444
 *
 * Created on 16 de Março de 2022, 08:36
 */


#include <xc.h>
#include <pic16f887.h>
#include "LM35.h"

void sens_conf (void)
{
    #define LM35 PORTAbits.RA0
    ANSELH.ANS0 = 1;
    
}