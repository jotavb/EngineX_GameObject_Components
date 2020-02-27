#pragma once
#include "GameObject.h"
#include "Component.h"
#include "ComponentType.h"
#include "Engine/Public/EngineInterface.h"

class COGTransform : public Component
{
public:

	COGTransform(GameObject* pGO, exEngineInterface * pEngine);

	virtual ComponentType	GetType() const;

	exVector2&				Position();

	void					Position(exVector2 newPos);

private:

	exVector2				mPosition;

};

