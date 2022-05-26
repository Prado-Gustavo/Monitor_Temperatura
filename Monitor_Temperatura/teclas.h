#ifndef TECLAS_H
#define	TECLAS_H
#include <xc.h>  

//funções relacionadas as teclas
void          teclas_init (void);
unsigned char tecla_incrementar (void);
unsigned char tecla_incrementar_subida (void);
unsigned char tecla_incrementar_descida (void);
unsigned char tecla_decrementar (void);
unsigned char tecla_decrementar_subida (void);
unsigned char tecla_decrementar_descida (void);

#endif

