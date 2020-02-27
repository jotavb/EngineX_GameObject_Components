#pragma once
#include "Engine/Public/EngineTypes.h"
#include <cmath> 

namespace MathLibrary
{
	// Increment one vector from another
	static void operator+=(exVector2& v1, const exVector2 v2)
	{
		v1 = { v1.x + v2.x, v1.y + v2.y };
	}

	// Decrement one vector from another
	static void operator-=(exVector2& v1, const exVector2 v2)
	{
		v1 = { v1.x - v2.x, v1.y - v2.y };
	}

	// Add one vector to another
	static exVector2 operator+(const exVector2 v1, const exVector2 v2)
	{
		return { v1.x + v2.x, v1.y + v2.y };
	}

	// Substract one vector from another
	static exVector2 operator-(const exVector2 v1, const exVector2 v2)
	{
		return { v1.x - v2.x, v1.y - v2.y };
	}

	// Divide vector with a float
	static exVector2 operator/(const exVector2 v1, const float number)
	{
		return { v1.x / number, v1.y / number };
	}

	// Multiple vector with a float
	static exVector2 operator*(const exVector2 v1, const float number)
	{
		return { v1.x * number, v1.y * number };
	}

	// Magnitude of a vector
	static float Magnitude(const exVector2 v1)
	{
		return sqrt(pow(v1.x, 2) + pow(v1.y, 2));
	}

	// Normalize Vector
	static exVector2 Normalize(const exVector2 v1)
	{
		float magnitude = Magnitude(v1);
		if (magnitude > 0.001f)
			return { v1.x / magnitude, v1.y / magnitude };
		return { 0, 0 }; // Magnitude ZERO
	}

	// Clamp
	static float Clamp(const float value, const float min, const float max)
	{
		if (value < min) return min;
		if (value > max) return max;
		return value;
	}

	// Dot product
	static float Dot(const exVector2 v1, const exVector2 v2)
	{
		return { v1.x * v2.x + v1.y * v2.y };
	}

	// Cross product 
	static float Cross(const exVector2 v1, const exVector2 v2)
	{
		return { (v1.x * v2.y) - (v1.y * v2.x) };
	}

	// Determinant
	static float Determinant(const exVector2 m_row1, const exVector2 m_row2)
	{
		return (m_row1.x * m_row2.y) - (m_row1.y * m_row2.x);
	}

	// Distance between two vectors
	static float Distance(const exVector2 v1, const exVector2 v2)
	{
		return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
	}

}; 
