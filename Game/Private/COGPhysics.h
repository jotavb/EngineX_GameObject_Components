#pragma once
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "Engine/Public/EngineInterface.h"

class COGTransform;
class COGBoxShape;
class COGCircleShape;

class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> mPhysicsComponents;

public:

	COGPhysics(GameObject* pGO, exEngineInterface* pEngine, bool bGenerateCollisionEvents);

	virtual ComponentType	GetType() const;

	virtual void			Initialize() override;

	virtual void			Destroy() override;

	virtual void			Update(float fDeltaT);

	exVector2&				Velocity();

	bool					IsColliding(COGPhysics* pOther);

	void					AddCollisionEventListener(IPhysicsCollisionEvent* pEvent);

private:
		
	COGTransform*			mTransform;

	COGBoxShape*			mBoxShape;	

	COGCircleShape*			mCircleShape;

	exVector2				mVelocity;

	bool					mGenerateCollisionEvents;

	std::vector<IPhysicsCollisionEvent*> mCollisionEventListeners;

};