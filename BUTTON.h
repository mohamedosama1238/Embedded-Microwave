#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "macros.h"

void Button_Init(unsigned char port_name,unsigned char pin_number);
unsigned char Button_read(unsigned char port_name,unsigned char pin_number);
void Button_InitPullUp(unsigned char port_name,unsigned char pin_number);
