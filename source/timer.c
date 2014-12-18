#include <AT89X52.h>
#include "typedefs.h"
#include "timer.h"
#include "digitDisplay.h"

extern UINT16 count;
extern UINT8 debounce_count;


/*----------------------------------------------------------------------------------------
																				TIMER-0
----------------------------------------------------------------------------------------*/

// Initializing Timer0 in mode-1
void Timer0_Init(void)
{
	TMOD |= 0X01;
	ET0 = 1;
	Timer0_Reload();
}

/* 1ms Timer

CALC: 1) 1ms/1.0856us = 922
			2) 65535 - 922 = 61614 = 0XFC66;

*/
void Timer0_Reload(void)
{
	TH0 = 0XFC;
	TL0 = 0X66;
	
	TR0 = 1;
	
}

// Timer-0 interrupt service routine
void Timer0_ISR(void) interrupt 1 using 2
{
	TF0 = 0;
	TR0 = 0;
	count++;					// main
	debounce_count++; // keypad
	Timer0_Reload();
}

/*----------------------------------------------------------------------------------------
																				TIMER-2
----------------------------------------------------------------------------------------*/
// Initializing Timer1 in mode-1
void Timer2_Init(void)
{
	T2MOD = 1;
	ET2 = 1;
	Timer2_Reload();
}

/* 2ms Timer
CALC: 1) 2ms/1.0856us = 1842
			2) 65535 - 1842 = 63693 = 0XF8CD;

*/
void Timer2_Reload(void)
{
	TH2 = 0XF8;
	TL2 = 0XCD;
	
	TR2 = 1;
	
}

// Timer-2 interrupt service routine
void Timer2_ISR(void) interrupt TF2_VECTOR
{
	TF2 = 0;
	TR2 = 0;
	Digit_Display_task();
	
	Timer2_Reload();
	
}

