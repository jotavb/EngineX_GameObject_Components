#include "COGBoxShape.h"
#include "COGTransform.h"

COGBoxShape::COGBoxShape(GameObject* pGO, exEngineInterface* pEngine, exColor color, float fWidth, float fHeight)
	: COGShape(pGO, pEngine, color)
	, mWidth(fWidth)
	, mHeight(fHeight)
{
}

ComponentType COGBoxShape::GetType() const
{ 
	return ComponentType::BoxShape;
}

void COGBoxShape::Render()
{
	p1 = { mTransform->Position().x - mWidth / 2, mTransform->Position().y + mHeight / 2 };

	p2 = { mTransform->Position().x + mWidth / 2, mTransform->Position().y - mHeight / 2 };

	mEngine->DrawBox(p1, p2, mColor, 1);
}

float COGBoxShape::Width()
{
	return mWidth;
}

void COGBoxShape::Width(float newWidth)
{
	mWidth = newWidth;
}

float COGBoxShape::Height()
{
	return mHeight;
}

void COGBoxShape::Height(float newHeight)
{
	mHeight = newHeight;
}
