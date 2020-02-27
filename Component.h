#pragma once
#include <ComponentType.h>
#include <vector>
#include <algorithm>

class GameObject;
class exEngineInterface;

class Component
{
public:

	Component(GameObject* pGO, exEngineInterface* pEngine);

	virtual ComponentType	GetType() const = 0;

	virtual void			Initialize() { };

	virtual void			Destroy() { };
	
	GameObject*				Gameobject();

protected:

	template<class T>
	void AddToComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.push_back((T*)this);
	}

	template<class T>
	void RemoveFromComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.erase(std::remove(componentVector.begin(), componentVector.end(), this), componentVector.end());
	}

protected:

	GameObject*	mGameobject;
	exEngineInterface * mEngine;

};