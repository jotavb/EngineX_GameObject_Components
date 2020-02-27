#pragma once
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "MathLibrary.h"
#include "Utils.h"
#include <vector>

class GameObject;
class COGPhysics;

class PlayerController
{
public:
	PlayerController(exEngineInterface* pEngine, GameObject* paddle, int player);
	~PlayerController();

	void Update( float fDeltaTime );
	void Initialize( int player );

	int Score() const;	
	void Score(int pScore);

	void BlockUpMove();

	void BlockDownMove();

	void HandleInput();	

protected:
	exEngineInterface*	mEngine;

	SDL_Scancode		Up;

	SDL_Scancode		Down;

	GameObject*			mPaddle;

	COGPhysics*			mPhysics;

	int					mScore;	
	
	bool				mCanGoUp;

	bool				mCanGoDown;
};

