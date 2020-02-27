#pragma once
#include "Component.h"
#include "IPhysicsCollisionEvent.h"

class exEngineInterface;
class COGTransform;

class COGBall : public Component, public IPhysicsCollisionEvent
{
public:

	COGBall(GameObject* pGO, exEngineInterface* pEngine);

	virtual ComponentType GetType() const;

	virtual void Initialize() override;

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther);

private:

	COGPhysics* mPhysics;
	COGTransform* mTransform;
};
