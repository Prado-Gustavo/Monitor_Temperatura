/*
 * File:   fmm.c
 * Author: 21193444
 *
 * Created on 1 de Junho de 2022, 09:06
 */


#include <xc.h>
#include "fmm.h"


long acc_temp = 0;
int fmm_temp[FMM_SIZE] = { 0 };
int fmm_temp_indice = 0;

int fmm_add( int valor )
{
    int i;
    i = fmm_temp_indice;
    acc_temp -= fmm_temp[i];
    fmm_temp[i] = valor;
    acc_temp += valor;
    fmm_temp_indice = (i+1) % FMM_SIZE;
    return( i );
}

int fmm_media( void )
{
    return( acc_temp / FMM_SIZE );
}

int fmm_add1( int valor )
{
    int i;
    i = fmm_temp_indice;
    acc_temp -= fmm_temp[i];
    fmm_temp[i] = valor;
    acc_temp += valor;
    fmm_temp_indice = (i+1) % FMM_SIZE;
    return( i );
}

int fmm_media1( void )
{
    return( acc_temp / FMM_SIZE );
}

int fmm_add2( int valor )
{
    int i;
    i = fmm_temp_indice;
    acc_temp -= fmm_temp[i];
    fmm_temp[i] = valor;
    acc_temp += valor;
    fmm_temp_indice = (i+1) % FMM_SIZE;
    return( i );
}

int fmm_media2( void )
{
    return( acc_temp / FMM_SIZE );
}

int fmm_add3( int valor )
{
    int i;
    i = fmm_temp_indice;
    acc_temp -= fmm_temp[i];
    fmm_temp[i] = valor;
    acc_temp += valor;
    fmm_temp_indice = (i+1) % FMM_SIZE;
    return( i );
}

int fmm_media3( void )
{
    return( acc_temp / FMM_SIZE );
}
