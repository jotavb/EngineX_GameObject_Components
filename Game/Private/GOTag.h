#pragma once

enum class GOTag : int
{
	None = 0,
	Paddle,
	Ball,
	BoardHorizontalTop,
	BoardHorizontalBottom,
	BoardVerticalLeft,
	BoardVerticalRight
};

const char* GOTagToString(GOTag Value);