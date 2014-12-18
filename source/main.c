#include "typedefs.h"
#include "timer.h"
#include "HB.h"
#include "digitDisplay.h"
#include "app.h"


UINT16 count = 0;

//char key_array[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};

void main()
{	
	Timer0_Init();		// Timer initialization
	Timer2_Init();		// Timer1 initialization
	HeartBeat_Init();	// HearBeat initialization
	EA = 1;						// Enabling global interrupts
	Digit_Display_init();
	App_init();
	
	
	while(1)
	{
		if (count >= 500)			//Turn ON Heart Beat Led for every 500ms
		{
			HeartBeat_task();
			count = 0;
		}
		
		App_task();
		
	}
	
}
