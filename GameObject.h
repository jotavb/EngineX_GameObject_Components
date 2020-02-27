#pragma once
#include "Component.h"
#include <vector>
#include "GOTag.h"

class exEngineInterface;
struct exVector2;

class GameObject
{
public:

	GameObject(exEngineInterface* pEngine);
	GameObject(exEngineInterface* pEngine, GOTag tag);
	~GameObject();

	void	Initialize();	
	void	AddComponent(Component* pComponent);

	template<class T>
	T* FindComponent(ComponentType eType)
	{
		for (Component* pComponent : mComponents)
		{
			if (pComponent->GetType() == eType)
			{
				return (T*)pComponent;
			}
		}
		return nullptr;
	}

	GOTag				Tag();

	void				Tag(GOTag newTag);

	static GameObject*	CreateBox(exEngineInterface* pEngine, exVector2 position, exVector2 size, GOTag tag);

	static GameObject*	CreatePaddle(exEngineInterface* pEngine, exVector2 position, exVector2 size, GOTag tag);

	static GameObject*	CreateBall(exEngineInterface* pEngine, exVector2 position, float radius, GOTag tag);



private:	

	std::vector<Component*>		mComponents;

	exEngineInterface*			mEngine;

	GOTag						mTag;
};
