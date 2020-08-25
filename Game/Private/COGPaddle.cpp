#include "COGPaddle.h"
#include "COGPhysics.h"
#include "COGTransform.h"
#include "GameObject.h"
#include "GOTag.h"
#include "PlayerController.h"

COGPaddle::COGPaddle(GameObject* pGO, exEngineInterface* pEngine)
	: Component(pGO, pEngine)
{
}

ComponentType COGPaddle::GetType() const
{
	return ComponentType::Paddle;
}

void COGPaddle::Initialize()
{
	mPhysics = mGameobject->FindComponent<COGPhysics>(ComponentType::Physics);
	mTransform = mGameobject->FindComponent<COGTransform>(ComponentType::Transform);

	// add myself to the list of objects that are interested in collisions
	// COGPhysics is able to interface with us because we inherit from IPhysicsCollisionEvent
	mPhysics->AddCollisionEventListener(this);
}

void COGPaddle::OnCollision(COGPhysics* pMe, COGPhysics* pOther)
{
	if (pOther->Gameobject()->Tag() == GOTag::BoardHorizontalTop)
	{		
		mPlayer->BlockUpMove();
	}
	else if (pOther->Gameobject()->Tag() == GOTag::BoardHorizontalBottom)
	{
		mPlayer->BlockDownMove();
	}
}

void COGPaddle::SetPlayer(PlayerController * player)
{
	mPlayer = player;
}
