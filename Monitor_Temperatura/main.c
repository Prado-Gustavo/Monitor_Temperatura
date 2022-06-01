/*
 * 
 * Author: 21193444
 *
 * Created on 30 de Março de 2022, 09:00
 */

#include <xc.h>
#include "analog.h"
#include "config.h"
#include "lcd.h"
#include "sensor.h"
#include "led.h"
#include "teclas.h"
#include "fmm.h"

struct sensor_t sensor[4];
int canal;


void main(void) 
{
    long refresh = 1;
    analog_init();
    lcd_init();
    led_init();
    teclas_init();

      sensor_init(sensor, 0,   0, 100, 25, 20, 40);
        sensor_init(sensor, 1,   0, 100, 25, 20, 40);
        sensor_init(sensor, 2,   0, 100, 25, 20, 40);
        sensor_init(sensor, 3,   0, 100, 25, 20, 40);
            
    while(1)
    {
        __delay_ms (5);
        lcd_print(0, 0, "Temp. Sensor:   ");
        
        sensor_readAll(sensor, 4);
        
        fmm_add (sensor[0].Valor);
        fmm_add1(sensor[1].Valor);
        fmm_add2(sensor[2].Valor);
        fmm_add3(sensor[3].Valor);
        
        lcd_num(0,14, (int)canal, 1 );
        if( !--refresh )
        {
            refresh = 50;
            lcd_num(1, 8, fmm_media (), 3);
            lcd_num(1, 8, fmm_media1(), 3);
            lcd_num(1, 8, fmm_media2(), 3);
            lcd_num(1, 8, fmm_media3(), 3);
        }
        
        if (tecla_incrementar_subida() )
        {
            canal = ++canal % 4;
        }
        if (tecla_decrementar_descida() )
        {
            canal = --canal % 4;
        }
        
        
        for( char i=0; i<4; i++ )
            led_monitorar(&sensor[i]);           
    }
}

