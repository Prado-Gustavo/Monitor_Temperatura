#include <xc.h>
#include "analog.h"
#include "config.h"
#include "lcd.h"
#include "sensor.h"
#include "led.h"

    
void led_init (void) //inicialização
{    

    LED_VD = 0;
    LED_AM = 0;
    LED_VM = 0;
    
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
}

void led_reset (void)
{
    LED_VD = 0;
    LED_AM = 0;
    LED_VM = 0;
    
}
void led_monitorar(struct sensor_t * ptr ) //realiza a monitoração em si e muda de acordo com a temperatura
{
        if( sensor_danger ( ptr ) && sensor_alert (ptr) )
        {
            LED_VD = 0;           
            LED_AM = 0;
            LED_VM = 1;

        }
        else if(sensor_alert( ptr) && !sensor_danger (ptr))
        {
            LED_VD = 0;            
            LED_VM = 0;
            LED_AM = 1;
        }
        else
        {
            LED_VD = 1;
            LED_AM = 0;
            LED_VM = 0;
        }
        
}
