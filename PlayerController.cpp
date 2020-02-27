#pragma once
#include "PlayerController.h"
#include "GameObject.h"
#include "COGPhysics.h"
#include "ComponentType.h"
#include "PlayerController.h"

PlayerController::PlayerController(exEngineInterface * pEngine, GameObject* pPaddle, int pPlayer)
	:mEngine(pEngine)
	,mPaddle(pPaddle)
{	
	Initialize(pPlayer);
}

PlayerController::~PlayerController() {}

void PlayerController::Initialize( int player )
{
	mPhysics = mPaddle->FindComponent<COGPhysics>(ComponentType::Physics);
	mScore = 0;
	mCanGoDown = true;
	mCanGoUp = true;
	if (player == 0)
	{		
		Up = SDL_SCANCODE_W;
		Down = SDL_SCANCODE_S;		
	}
	else 
	{		
		Up = SDL_SCANCODE_UP;
		Down = SDL_SCANCODE_DOWN;
	}
}

int PlayerController::Score() const
{
	return mScore;
}

void PlayerController::Score(int pScore)
{
	mScore = pScore;
}

void PlayerController::BlockUpMove()
{
	mCanGoUp = false;
}

void PlayerController::BlockDownMove()
{
	mCanGoDown = false;
}

void PlayerController::Update( float fDeltaTime )
{
	if (mPaddle != nullptr)
	{
		HandleInput();
	}
}

void PlayerController::HandleInput()
{
	if (SDL_GetKeyboardState(0)[Up] && mCanGoUp)
	{		
		mPhysics->Velocity(exVector2{ 0, -1 * 500 });
		mCanGoDown = true;
	}
	else if (SDL_GetKeyboardState(0)[Down] && mCanGoDown)
	{
		mPhysics->Velocity(exVector2{ 0, 1 * 500 });
		mCanGoUp = true;
	}
	else
	{ 
		mPhysics->Velocity(exVector2{ 0, 0 });
	}
}
