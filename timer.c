#include "LCD.h"
#include "LED_TIMER.h"

void timer_clc(int Q, int W, int E, int R)
{
	char arr_ERROR[4] = { "ERR" };
	if(E<6)
	{
		char timer[]={'0','0',':','0','0'};
		int i;
		int j;
		int x;
		int z;

		for(i=Q;i>=0;i--)
			{
			for (j=W;j>=0;j--)
				{
				for (x=E;x>=0;x--)
					{
					for (z=R;z>=0;z--)
						{
						timer[0]=i;
						timer[1]=j;
						timer[3]=x;
						timer[4]=z;
						LCD_vSendString( *timer);
						Delay(1000);
						}
					}
				}
			}		
	}
	else
	{
	 LCD_vSendString( *arr_ERROR);
	}
}