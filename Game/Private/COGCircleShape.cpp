#include "COGCircleShape.h"
#include "COGTransform.h"

COGCircleShape::COGCircleShape(GameObject* pGO, exEngineInterface* pEngine, exColor color, float fRadius)
	: COGShape(pGO, pEngine, color)
	, mRadius(fRadius)
{
}

ComponentType COGCircleShape::GetType() const 
{ 
	return ComponentType::CircleShape; 
}

void COGCircleShape::Render()
{
	mEngine->DrawCircle(mTransform->Position(), mRadius, mColor, 1);
}

float COGCircleShape::Radius()
{
	return mRadius;
}

void COGCircleShape::Radius(float newRadius)
{
	mRadius = newRadius;
}
