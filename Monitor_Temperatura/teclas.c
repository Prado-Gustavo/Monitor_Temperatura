/*
 * File:   teclas.c
 * Author: 21193444
 *
 * Created on 12 de Maio de 2022, 08:04
 */


#include <xc.h>
#include "analog.h"
#include "config.h"
#include "lcd.h"
#include "sensor.h"
#include "teclas.h"

#define decrementar PORTCbits.RC4
#define incrementar PORTCbits.RC5

void teclas_init (void)
{
    TRISCbits.TRISC4 = 1;
    TRISCbits.TRISC5 = 1;        
}

unsigned char incrementar_anterior = 0; //Funcionamento da tecla incrementadora
unsigned char tecla_incrementar (void)
{
    return( incrementar );
}

unsigned char tecla_incrementar_subida (void) //Detecção da mudança de estado
{
    if (!incrementar_anterior && incrementar)
    {
        incrementar_anterior = incrementar;
        return (1);
    }
    else
    {
        incrementar_anterior = incrementar;
        return (0);
    }
}

unsigned char tecla_incrementar_descida (void) //Detecção da mudança de estado
{
    if (incrementar_anterior && !incrementar)
    {
        incrementar_anterior = incrementar;
        return (1);
    }
    else
    {
        incrementar_anterior = incrementar;
        return (0);
    }
}

unsigned char decrementar_anterior = 0; //Funcionamento da tecla incrementadora
unsigned char tecla_decrementar (void)
{
    return (decrementar);
}

unsigned char tecla_decrementar_subida (void) //Detecção da mudança de estado
{
    if (!decrementar_anterior && decrementar)
    {
        decrementar_anterior = decrementar;
        return (1);
    }
    else
    {
        decrementar_anterior = decrementar;
        return (0);
    }
}

unsigned char tecla_decrementar_descida (void) //Detecção da mudança de estado
{
    if (decrementar_anterior && !decrementar)
    {
        decrementar_anterior = decrementar;
        return (1);
    }
    else
    {
        decrementar_anterior = decrementar;
        return (0);
    }    
}

