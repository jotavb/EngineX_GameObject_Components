#include "Engine/Public/EngineInterface.h"
#include "GameObject.h"
#include "COGTransform.h"
#include "COGBoxShape.h"
#include "COGCircleShape.h"
#include "COGPhysics.h"
#include "COGBall.h"
#include "COGPaddle.h"
#include "Utils.h"

GameObject::GameObject(exEngineInterface* pEngine)
	: mEngine(pEngine)
{
}

GameObject::GameObject(exEngineInterface* pEngine, GOTag tag)
	: mEngine(pEngine)
	, mTag(tag)
{
}

GameObject::~GameObject()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Destroy();

		delete pComponent;
	}
}

void GameObject::Initialize()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Initialize();
	}
}

void GameObject::AddComponent(Component* pComponent)
{
	mComponents.push_back(pComponent);
}

GOTag GameObject::Tag()
{
	return mTag;
}

void GameObject::Tag(GOTag newTag)
{
	mTag = newTag;
}

GameObject* GameObject::CreateBox(exEngineInterface* pEngine, exVector2 position, exVector2 size, GOTag tag)
{
	GameObject* pBox = new GameObject(pEngine, tag);

	COGTransform* pTransform = new COGTransform(pBox, pEngine);
	pBox->AddComponent(pTransform);
	pTransform->Position(position);

	COGBoxShape* pBoxShape = new COGBoxShape(pBox, pEngine, Utils::GetColorRGB(255, 255, 255, 255), size.x, size.y);
	pBox->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pBox, pEngine, false);
	pBox->AddComponent(pPhysics);

	pBox->Initialize();

	return pBox;
}

GameObject* GameObject::CreatePaddle(exEngineInterface* pEngine, exVector2 position, exVector2 size, GOTag tag)
{
	GameObject* pPaddle = new GameObject(pEngine, tag);

	COGTransform* pTransform = new COGTransform(pPaddle, pEngine);
	pPaddle->AddComponent(pTransform);
	pTransform->Position(position);

	COGBoxShape* pBoxShape = new COGBoxShape(pPaddle, pEngine, Utils::GetColorRGB(255, 255, 255, 255), size.x, size.y);
	pPaddle->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pPaddle, pEngine, true);
	pPaddle->AddComponent(pPhysics);

	COGPaddle* Paddle = new COGPaddle(pPaddle, pEngine);
	pPaddle->AddComponent(Paddle);

	pPaddle->Initialize();

	return pPaddle;
}

GameObject* GameObject::CreateBall(exEngineInterface* pEngine, exVector2 position, float radius, GOTag tag)
{
	GameObject* pBall = new GameObject(pEngine, tag);

	COGTransform* pTransform = new COGTransform(pBall, pEngine);
	pBall->AddComponent(pTransform);
	pTransform->Position(position);

	COGCircleShape* pBoxShape = new COGCircleShape(pBall, pEngine, Utils::GetColorRGB(255, 255, 255, 255), radius);
	pBall->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pBall, pEngine, true);
	pBall->AddComponent(pPhysics);

	COGBall* pBounce = new COGBall(pBall, pEngine);
	pBall->AddComponent(pBounce);

	pBall->Initialize();

	return pBall;
}