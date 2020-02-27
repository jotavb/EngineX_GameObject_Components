#include "ComponentType.h"

const char* ComponentTypeToString(ComponentType Value)
{
	const char* szComponentTypes[] = {
		"Transform",
		"Physics",
		"BoxShape",
		"CircleShape",
		"Ball",
		"Paddle"
	};

	return szComponentTypes[(int)Value];
}
