#pragma once
#include "Component.h"
#include "IPhysicsCollisionEvent.h"

class exEngineInterface;
class COGTransform;
class PlayerController;

class COGPaddle : public Component, public IPhysicsCollisionEvent
{
public:

	COGPaddle(GameObject* pGO, exEngineInterface* pEngine);

	virtual ComponentType	GetType() const;

	virtual void			Initialize() override;

	virtual void			OnCollision(COGPhysics* pMe, COGPhysics* pOther);

	void					SetPlayer(PlayerController* player);

private:

	PlayerController*		mPlayer;

	COGPhysics*				mPhysics;

	COGTransform*			mTransform;
};
