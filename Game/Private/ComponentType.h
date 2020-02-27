#pragma once
enum class ComponentType : int
{
	Transform = 0,
	Physics,
	BoxShape,
	CircleShape,
	Ball,
	Paddle,
	MAX
};

const char* ComponentTypeToString(ComponentType Value);