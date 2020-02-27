#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "PlayerController.h"
#include "Utils.h"
#include "GameObject.h"
#include <chrono>

class MyGame : public exGameInterface
{
public:
	static int ScorePlayer1;
	static int ScorePlayer2;

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	 const char*				GetWindowName() const;
	 virtual void				GetClearColor( exColor& color ) const;
	 virtual void				Run( float fDeltaT );
	 virtual void				OnEvent(SDL_Event* pEvent);
	 virtual void				OnEventsConsumed();

	 float oldTime;				// Save time from last loop.
	 float currentTime;			// Time since program began.
	 float deltaTime;			// Calculate time taken by game loop.

private:

	exEngineInterface*			mEngine;
	int							mFontID;

	std::vector<GameObject*> mGameObjects;
	PlayerController* mP1;
	PlayerController* mP2;
};
