#include "COGPhysics.h"
#include "COGTransform.h"
#include "COGBoxShape.h"
#include "COGCircleShape.h"
#include "MathLibrary.h"
#include "GOTag.h"
using namespace MathLibrary;

std::vector<COGPhysics*> COGPhysics::mPhysicsComponents;

COGPhysics::COGPhysics(GameObject* pGO, exEngineInterface* pEngine, bool bGenerateCollisionEvents)
	: Component(pGO, pEngine)
	, mGenerateCollisionEvents(bGenerateCollisionEvents)
{
}

ComponentType COGPhysics::GetType() const 
{ 
	return ComponentType::Physics; 
}

void COGPhysics::Initialize()
{
	mTransform = mGameobject->FindComponent<COGTransform>(ComponentType::Transform);
	mBoxShape = mGameobject->FindComponent<COGBoxShape>(ComponentType::BoxShape);
	mCircleShape = mGameobject->FindComponent<COGCircleShape>(ComponentType::CircleShape);
	AddToComponentVector(mPhysicsComponents);
}

void COGPhysics::Destroy()
{
	RemoveFromComponentVector(mPhysicsComponents);
}

void COGPhysics::Update(float fDeltaT)
{
	// Integrate velocity
	exVector2& myPosition = mTransform->Position();

	myPosition += mVelocity * fDeltaT;
	mTransform->Position(myPosition);

	// Check collisions
	if (mGenerateCollisionEvents)
	{
		for (COGPhysics* pPhysicsOther : COGPhysics::mPhysicsComponents)
		{
			// do not collide with self
			if (pPhysicsOther == this)
			{
				continue;
			}

			// TODO - maybe have IsColliding produce a vector/struct that contains the normal and then pass that into OnCollision?
			const bool bResult = IsColliding(pPhysicsOther);

			if (bResult)
			{
				for (IPhysicsCollisionEvent* pCollisionEventListener : mCollisionEventListeners)
				{
					pCollisionEventListener->OnCollision(this, pPhysicsOther);
				}
			}
		}
	}
}

exVector2 COGPhysics::Velocity()
{
	return mVelocity;
}

void COGPhysics::Velocity(exVector2 newVelocity)
{
	mVelocity = newVelocity;
}

bool COGPhysics::IsColliding(COGPhysics* pOther)
{
	
	if (mBoxShape != nullptr && pOther->mBoxShape != nullptr)
	{
		if (abs(mTransform->Position().x - pOther->mTransform->Position().x) * 2 < (mBoxShape->Width() + pOther->mBoxShape->Width()) &&
			(abs(mTransform->Position().y - pOther->mTransform->Position().y) * 2 < (mBoxShape->Height() + pOther->mBoxShape->Height())))
		{
			return true;
		}
	}
	else if (mCircleShape != nullptr && pOther->mBoxShape != nullptr)
	{		
		exVector2 difference = mTransform->Position() - pOther->mTransform->Position();

		exVector2 clamped = { Clamp(difference.x, -pOther->mBoxShape->Width() / 2.0f, pOther->mBoxShape->Width() / 2.0f)
							, Clamp(difference.y, -pOther->mBoxShape->Height() / 2.0f, pOther->mBoxShape->Height() / 2.0f) };

		exVector2 closest = pOther->mTransform->Position() + clamped;

		difference = closest - mTransform->Position();
		return Magnitude(difference) < mCircleShape->Radius();
	}

	return false;
}

void COGPhysics::AddCollisionEventListener(IPhysicsCollisionEvent* pEvent)
{
	mCollisionEventListeners.push_back(pEvent);
}
