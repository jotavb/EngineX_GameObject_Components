#include "COGBall.h"
#include "COGPhysics.h"
#include "COGTransform.h"
#include "GameObject.h"
#include "GOTag.h"
#include "Game/Private/Game.h"

COGBall::COGBall(GameObject* pGO, exEngineInterface* pEngine)
	: Component(pGO, pEngine)
{
}

ComponentType COGBall::GetType() const
{ 
	return ComponentType::Ball; 
}

void COGBall::Initialize() 
{
	mPhysics = mGameobject->FindComponent<COGPhysics>(ComponentType::Physics);
	mTransform = mGameobject->FindComponent<COGTransform>(ComponentType::Transform);
	mPhysics->AddCollisionEventListener(this);
}

void COGBall::OnCollision(COGPhysics* pMe, COGPhysics* pOther) 
{
	if (pOther->Gameobject()->Tag() == GOTag::Paddle)
	{
		exVector2 newVelocity = { -mPhysics->Velocity().x * 1.1f, mPhysics->Velocity().y + (pOther->Velocity().y * 0.15f) };
		mPhysics->Velocity(newVelocity);
	}
	if (pOther->Gameobject()->Tag() == GOTag::BoardHorizontalTop || pOther->Gameobject()->Tag() == GOTag::BoardHorizontalBottom)
	{
		exVector2 newVelocity = { mPhysics->Velocity().x, -mPhysics->Velocity().y };
		mPhysics->Velocity(newVelocity);
	}
	if (pOther->Gameobject()->Tag() == GOTag::BoardVerticalRight)
	{
		mTransform->Position(exVector2{ 400.0f, 300.0f });
		mPhysics->Velocity(exVector2{ -270.0f, 0.0f });
		MyGame::ScorePlayer1++;
	}
	if (pOther->Gameobject()->Tag() == GOTag::BoardVerticalLeft)
	{
		mTransform->Position(exVector2{ 400.0f, 300.0f });		
		mPhysics->Velocity(exVector2{ 270.0f, 0.0f });
		MyGame::ScorePlayer2++;
	}
}