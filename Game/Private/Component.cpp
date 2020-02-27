#include "Component.h"

Component::Component(GameObject* pGO, exEngineInterface* pEngine) 
	: mGameobject(pGO)
	, mEngine(pEngine)
{
}

GameObject * Component::Gameobject()
{
	return mGameobject;
}


