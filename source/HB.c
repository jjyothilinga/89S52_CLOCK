#include <AT89X52.h>
#include "HB.h"
#include "board.h"

bit Led_State;


void HeartBeat_Init(void)
{
	Led_State = 0;
}

// Heart Beat LED 
void HeartBeat_task(void)
{
	if (Led_State == 1)
	{
		HeartBeat = 1;
		Led_State = 0;
	}
	
	else 
	{
		HeartBeat = 0;
		Led_State = 1;
	}
	
}
