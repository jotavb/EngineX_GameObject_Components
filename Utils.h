#pragma once
#include "Engine/Public/EngineInterface.h"

namespace Utils 
{
	static exColor GetColorRGB(int r, int g, int b, int a)
	{
		exColor color;
		color.mColor[0] = r;
		color.mColor[1] = g;
		color.mColor[2] = b;
		color.mColor[3] = a;
		return color;
	}
}