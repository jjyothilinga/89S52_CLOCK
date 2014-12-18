#ifndef TYPE_DEFS_H
#define TYPE_DEFS_H

/*
*------------------------------------------------------------------------------
* typedefs.h
*
* Include file for processor specific portable data types.
*
* (C)2008 Sam's Logic
*
* The copyright notice above does not evidence any
* actual or intended publication of such source code.
*
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: typedefs.h
* Created by		: Sam
* Last changed by	: Sam
* Last changed		: 28/10/2008
*------------------------------------------------------------------------------
*
* Revision 0.0 28/10/2008 Sam
* Initial revision
*
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/

#include <AT89X52.h>
//#include <AT89X51.h>


/*
*------------------------------------------------------------------------------
* Public Defines
*------------------------------------------------------------------------------
*/
//NOTE: - All basic data types are taken from MPLAB C18 compiler manual.
/*
*------------------------------------------------------------------------------
*		Basic Type 			New Type	Size 		Minimum 		Maximum
*------------------------------------------------------------------------------
*/

typedef	bit 		 		BOOL;		//1 bits 	0 				1
typedef	unsigned char 		UINT8;		//8 bits 	0 				255
typedef	unsigned int 		UINT16;		//16 bits 	0 				65,535
typedef	unsigned long 		UINT32;		//32 bits 	0 				4,294,967,295

typedef enum
{	
	FAILURE = 0,
	SUCCESS = 1	
}RESULT;

#define ENABLE_GLOBAL_INTERRUPT() (EA = 1)
#define DISABLE_GLOBAL_INTERRUPT() (EA = 0)

#define ENTER_CRITICAL_TIMER0_INTERRUPT() (ET0 = 0)
#define EXIT_CRITICAL_TIMER0_INTERRUPT() (ET0 = 1)


#endif
/*
*  End of typedefs.h
*/
