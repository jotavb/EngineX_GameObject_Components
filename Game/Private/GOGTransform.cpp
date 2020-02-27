#include "COGTransform.h"

COGTransform::COGTransform(GameObject* pGO, exEngineInterface * pEngine)
	: Component(pGO, pEngine)
{
}

ComponentType COGTransform::GetType() const
{
	return ComponentType::Transform;
}

exVector2& COGTransform::Position()
{ 
	return mPosition;
}

void COGTransform::Position(exVector2 newPos)
{
	mPosition = newPos;
}
