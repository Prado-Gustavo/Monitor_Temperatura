#ifndef LED_H
#define LED_H

// definição de nomes
#define  LED_VD     PORTCbits.RC0
#define  LED_AM     PORTCbits.RC1
#define  LED_VM     PORTCbits.RC2

//funções
void led_init      (void);
void led_monitorar(struct sensor_t * ptr );
void led_reset( void );
void led_condition (struct sensor_t *ptr, char l);

#endif