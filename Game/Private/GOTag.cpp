#include "GOTag.h"

const char * GOTagToString(GOTag Value)
{
	const char* szGOTag[] = {
		"None",
		"Paddle",
		"Ball",
		"BoardHorizontalTop",
		"BoardHorizontalBottom",
		"BoardVerticalLeft",
		"BoardVerticalRight"
	};	
	return szGOTag[(int)Value];
}
