#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "prototypes.h"
#include "LED_TIMER.h"
#include "keypad.h"
#include "BUTTON.h"

#define LCD_DATA GPIOB
#define LCD_CTRL GPIOA
#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */







void LCD_vInit(void)
{
SYSCTL_RCGCGPIO_R |= 0x01; /* enable clock to GPIOA */
SYSCTL_RCGCGPIO_R |= 0x02; /* enable clock to GPIOB */
GPIO_PORTA_DIR_R |= 0xE0; /* set PORTA pin 7-5 as output for control */
GPIO_PORTA_DEN_R |= 0xE0; /* set PORTA pin 7-5 as digital pins */
GPIO_PORTB_DIR_R = 0xFF; /* set all PORTB pins as output for data */
GPIO_PORTB_DEN_R = 0xFF; /* set all PORTB pins as digital pins */
Delay(5); /* initialization sequence */
LCD_command(0x30);
Delay(5);
LCD_command(0x30);
Delay(5);
LCD_command(0x30);
LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */
LCD_command(0x06); /* move cursor right */
LCD_command(0x01); /* clear screen, move cursor to home */
LCD_command(0x0F); /* turn on display, cursor blinking */
}
void LCD_command(unsigned char cmnd)
{
GPIO_PORTA_DATA_R = 0; /* RS = 0, R/W = 0 */
GPIO_PORTB_DATA_R = cmnd;
GPIO_PORTA_DATA_R = EN; /* pulse E */
Delay(5);
GPIO_PORTA_DATA_R = 0;
if (cmnd < 4)
Delay(5); /* command 1 and 2 needs up to 1.64ms */
else
Delay(5); /* all others 40 us */
}
void lcd_data(unsigned char data)
{
GPIO_PORTA_DATA_R = RS; /* RS = 1, R/W = 0 */
GPIO_PORTB_DATA_R = data;
GPIO_PORTA_DATA_R = EN | RS; /* pulse E */
Delay(5);
GPIO_PORTA_DATA_R = 0;
Delay(5);
}
void LCD_vSendString(unsigned char *data){
	LCD_command(0x80);
	while (*data)
	{
		lcd_data((*data));
		data++;
	}
}
void LCD_ClearScreen(){
	LCD_command(1);
	LCD_command(0x80);
	Delay(10);
}
