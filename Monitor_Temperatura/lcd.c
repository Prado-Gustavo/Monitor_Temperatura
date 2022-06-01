#include <xc.h>
#include "analog.h"
#include "config.h"
#include "lcd.h"
#include "sensor.h"
//Definição Porte e pinos

#define LCD_IHM 	//definição de ligação de LCD - lIGAÇÃO FÍSICA

#ifdef LCD_IHM			//LCD com ligação invertida

   #define LCD_BUS( x )    PORTD = ((PORTD & 0xF0)|(x & 0x0F))
   #define LCD_EN          PORTDbits.RD5
   #define LCD_RS          PORTDbits.RD4

#else  			//LCD ligação normal - Simulide ou Protheus

   #define LCD_BUS( x )    PORTD = ((PORTD & 0x0F)|(x<<4))
   #define LCD_EN          PORTDbits.RD3
   #define LCD_RS          PORTDbits.RD2

#endif

#define LCD_ROWS        2
#define LCD_COLS        16

//Lista de comandos LCD
#define LCD_CLEAR_DISPLAY           0x01

#define LCD_RETURN_HOME             0x02

#define LCD_ENTRY_MODE_SET          0x04
#define LCD_EMS_CURSOR_RIGHT        0x02
#define LCD_EMS_CURSOR_LEFT         0x00
#define LCD_EMS_SHIFT_DISPLAY       0x01

#define LCD_DISPLAY_CONTROL         0x08
#define LCD_DC_DISPLAY_ON           0x04
#define LCD_DC_DISPLAY_OFF          0x00
#define LCD_DC_CURSOR_ON            0x02
#define LCD_DC_CURSOR_OFF           0x00
#define LCD_DC_BLINK_ON             0x01
#define LCD_DC_BLINK_OFF            0x00

#define LCD_CURSOR_SHIFT            0x10
#define LCD_CS_LEFT                 0x00
#define LCD_CS_RIGHT                0x04

#define LCD_DISPLAY_SHIFT           0x10
#define LCD_DS_LEFT                 0x08
#define LCD_DS_RIGHt                0x0C

#define LCD_FUNCTION_SET            0x20
#define LCD_FS_DATA_LENGTH_8        0x10
#define LCD_FS_DATA_LENGTH_4        0x00
#define LCD_FS_LINE_NUMBER_1        0x00
#define LCD_FS_LINE_NUMBER_2        0x08
#define LCD_FS_DOTS_FORMAT_5x8      0x00
#define LCD_FS_DOTS_FORMAT_5x11     0x04

#define LCD_SET_CGRAM_ADDRS( adrs ) (0x40+(adrs & 0x3F))

#define LCD_SET_DDRAM_ADDRS( adrs ) (0x80+(adrs & 0x7F))
#define LCD_ADDR_LINE_0             0x00
#define LCD_ADDR_LINE_1             0x40

// Comandos ao LCD
void lcd_inst (unsigned char i)
{
    LCD_RS = 0;
    LCD_BUS (i>>4);
    
    LCD_EN =0;
    if ( i == LCD_CLEAR_DISPLAY || i == LCD_RETURN_HOME )
        __delay_ms (2);
    else
        __delay_us (40);
    LCD_EN = 1;

    if ( (i & 0xF0) == (LCD_FUNCTION_SET | LCD_FS_DATA_LENGTH_4) )
    {
        LCD_RS = 0;
        LCD_BUS (i>>4);
        LCD_EN = 0;
        __delay_us (40);
        LCD_EN = 1;
    }
    
    LCD_RS = 0;
    LCD_BUS(i);
    LCD_EN = 0;
    if ( i==LCD_CLEAR_DISPLAY || i == LCD_RETURN_HOME )
        __delay_ms(2);
    else
        __delay_us(40);
    LCD_EN = 1;
}

//Leitura de dados lcd
void lcd_data (unsigned char d)
{
    LCD_RS = 1;
    LCD_BUS (d>>4);
    LCD_EN = 0;
    __delay_us (40);
    LCD_EN = 1;
    
    LCD_RS = 1;
    LCD_BUS (d);
    LCD_EN = 0;
    __delay_us (40);
    LCD_EN = 1;
}

//Coordenada do cursor em forma matricial
void lcd_lincol ( unsigned char lin, unsigned char col)
{
    lcd_inst ( LCD_SET_DDRAM_ADDRS ( (LCD_ADDR_LINE_1 * lin) + (col + LCD_ADDR_LINE_0) ) );
}

//Inicialização do LCD
void lcd_init (void)
{
    __delay_ms(100);

	#ifdef LCD_IHM  
 
		//Ligação Física
    			TRISDbits.TRISD0 = 0;   // D4
    			TRISDbits.TRISD1 = 0;   // D5
    			TRISDbits.TRISD2 = 0;   // D6
    			TRISDbits.TRISD3 = 0;   // D7
    			TRISDbits.TRISD4 = 0;   // RS
    			TRISDbits.TRISD5 = 0;   // EN
    			TRISDbits.TRISD6 = 0;   // Botão 01
    			TRISDbits.TRISD7 = 0;   // Botão 02

	#else	
	
		//Ligação para simuladores
    			TRISDbits.TRISD0 = 1;   // Botão 01
    			TRISDbits.TRISD1 = 1;   // Botão 02
    			TRISDbits.TRISD2 = 0;   // RS
    			TRISDbits.TRISD3 = 0;   // EN
    			TRISDbits.TRISD4 = 0;   // D4
    			TRISDbits.TRISD5 = 0;   // D5
    			TRISDbits.TRISD6 = 0;   // D6
    			TRISDbits.TRISD7 = 0;   // D7
 	#endif
    
    __delay_ms(100);
    LCD_EN = 1;
    lcd_inst( LCD_FUNCTION_SET|LCD_FS_DATA_LENGTH_4|LCD_FS_LINE_NUMBER_2 );
    lcd_inst( LCD_DISPLAY_CONTROL|LCD_DC_DISPLAY_ON|LCD_DC_CURSOR_OFF|LCD_DC_BLINK_OFF );
    lcd_inst( LCD_CLEAR_DISPLAY );
    lcd_inst( LCD_RETURN_HOME );
    __delay_ms(100);
}

//Limpar tela do LCD
void lcd_clear (void)
{
    lcd_inst(LCD_CLEAR_DISPLAY);
}

//Escrever uma frase nas coordenadas "Linha/Coluna" do display

void lcd_print( unsigned char lin, unsigned char col, const char * str )
{
    char pos = col;
    lcd_lincol( lin, col );

    while( *str )
    {
        lcd_data( *str );
        ++str;
        ++pos;
    }
}

//Escrever um número inteiro no display
void lcd_num(  unsigned char lin, unsigned char col,
                    int num, unsigned char tam )
{
    int div;
    unsigned char size;
    char sinal; // 0:+ 1:-
   
    sinal = num < 0;
    if( sinal )
        num = (~num) + 1;

    lcd_lincol(lin, col);
   
    div=10000;
    size = 5;
    while( div >= 1 )
    {
        if( num/div == 0 )
            --size;
        else
            break;
        div/=10;
    }

    while( tam > (size+sinal) && tam > 1 )
    {
        lcd_data(' ');
        --tam;
    }  

    if( sinal )
        lcd_data('-');
 
    do
    {
        lcd_data( (unsigned char)(num / div) + '0' );
        num = num % div;
        div/=10;
    }
    while( div >= 1 );
}