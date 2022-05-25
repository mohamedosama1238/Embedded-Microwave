#include "DIO.h"
#include "LCD_config.h"
#include "LED_TIMER.h"


void LCD_command(unsigned char cmnd);
void LCD_vInit(void);
void lcd_data(unsigned char data);
void LCD_vSendString(unsigned char *data);
void LCD_ClearScreen();
unsigned char *Enter_Time();
void LCD_Countdown(unsigned char* time);
unsigned char *Timer (unsigned char kilo, unsigned char time);