#include "COGShape.h"
#include "GameObject.h"

std::vector<COGShape*> COGShape::mShapeComponents;

COGShape::COGShape(GameObject* pGO, exEngineInterface* pEngine, exColor pColor)
	: Component(pGO, pEngine)
	, mColor(pColor)
{
}

void COGShape::Initialize()
{
	mTransform = mGameobject->FindComponent<COGTransform>(ComponentType::Transform);	
	AddToComponentVector(mShapeComponents);
}

void COGShape::Destroy()
{
	RemoveFromComponentVector(mShapeComponents);
}

exColor COGShape::Color() const
{
	return mColor;
}