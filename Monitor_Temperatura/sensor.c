#include <xc.h>
#include "analog.h"
#include "config.h"
#include "lcd.h"
#include "sensor.h"

//funções


void sensor_init(struct sensor_t * ptr, char ch, int tmin, int tmax, int alvo, char aceitavel, char toleravel)
{
    (ptr+ch)->CH = ch;
    (ptr+ch)->Tmin = tmin;
    (ptr+ch)->Tmax = tmax;
    (ptr+ch)->Alvo = alvo;
    (ptr+ch)->aceitavel = aceitavel;
    (ptr+ch)->toleravel = toleravel;
}

void sensor_read(struct sensor_t * ptr, char ch )
{
    (ptr+ch)->Valor = ( ( (ADC_read(ptr->CH) + 1) * (long)((ptr+ch)->Tmax - (ptr+ch)->Tmin) >>10 ) + (ptr+ch)->Tmin);
}


void sensor_readAll(struct sensor_t *ptr, char n )
{
    char i;
    for( i=0; i<n; i++ )
        (ptr+i)->Valor = (  ( (ADC_read((ptr+i)->CH) + 1) * (long)( (ptr+i)->Tmax - (ptr+i)->Tmin)>>10 ) + (ptr+i)->Tmin);
}


void sensor_setAlert( struct sensor_t * ptr, char p )
{
    ptr->aceitavel = p;
}
void sensor_setDanger( struct sensor_t * ptr, char p )
{
    ptr->toleravel = p;
}
void sensor_setAlvo( struct sensor_t * ptr, int alvo )
{
    ptr->Alvo = alvo;
}
char sensor_alert( struct sensor_t * ptr )
{
    int min, max;
    
    min = ptr->Alvo;
    min -= (min*ptr->aceitavel)/100;
    max = ptr->Alvo;
    max += (max*ptr->aceitavel)/100;
    
    if( ptr->Valor <= min || ptr->Valor >= max )
        return( 1 );
    else
        return( 0 );
}
char sensor_danger( struct sensor_t * ptr )
{
    int min, max;
    
    min = ptr->Alvo;
    min -= (min*ptr->toleravel)/100;
    max = ptr->Alvo;
    max += (max*ptr->toleravel)/100;
    
    if( ptr->Valor <= min || ptr->Valor >= max )
        return( 1 );
    else
        return( 0 );
}
int sensor_delta( struct sensor_t * ptr )
{
    return( ptr->Alvo - ptr->Valor );
}
