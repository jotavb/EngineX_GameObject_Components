#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "COGPhysics.h"
#include "COGPaddle.h"
#include "COGShape.h"
#include  <iostream>
#include <string>

const char* gWindowName = "Pong EngineX Student Game";
int MyGame::ScorePlayer1;
int MyGame::ScorePlayer2;

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
{
}

MyGame::~MyGame()
{
	for (GameObject* pGameObject : mGameObjects)
	{
		delete pGameObject;
	}
	mGameObjects.clear();
}


void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;
	mFontID = mEngine->LoadFont("BowlbyOneSC-Regular.ttf", 40);

	// Paddles
	GameObject* player1 = GameObject::CreatePaddle(mEngine, exVector2{ 50.0f, 300.0f }, exVector2{ 20.0f, 90.0f }, GOTag::Paddle);
	GameObject* player2 = GameObject::CreatePaddle(mEngine, exVector2{ 750.0f, 300.0f }, exVector2{ 20.0f, 90.0f }, GOTag::Paddle);
	mGameObjects.push_back(player1);
	mGameObjects.push_back(player2);

	// Players - Adding to the paddle to listen to OnCollision
	mP1 = new PlayerController(mEngine, player1, 0);	
	player1->FindComponent<COGPaddle>(ComponentType::Paddle)->SetPlayer(mP1);
	mP2 = new PlayerController(mEngine, player2, 1);
	player2->FindComponent<COGPaddle>(ComponentType::Paddle)->SetPlayer(mP2);
	
	// Ball
	GameObject* ball = GameObject::CreateBall(mEngine, exVector2{ 400.0f, 300.0f }, 15.0f, GOTag::Ball);
	mGameObjects.push_back(ball);
	ball->FindComponent<COGPhysics>(ComponentType::Physics)->Velocity(exVector2{ 300.0f, 0.0f });

	// Board
	GameObject* boardLeft = GameObject::CreateBox(mEngine, exVector2{ -10.0f, 300.0f }, exVector2{ 40.0f, 600.0f }, GOTag::BoardVerticalLeft);
	GameObject* boardRight = GameObject::CreateBox(mEngine, exVector2{ 810.0f, 300.0f }, exVector2{ 40.0f, 600.0f }, GOTag::BoardVerticalRight);
	GameObject* boardTop = GameObject::CreateBox(mEngine, exVector2{ 400.0f, -10.0f }, exVector2{ 800.0f, 40.0f }, GOTag::BoardHorizontalTop);
	GameObject* boardBottom = GameObject::CreateBox(mEngine, exVector2{ 400.0f, 610.0f }, exVector2{ 800.0f, 40.0f }, GOTag::BoardHorizontalBottom);
}

const char * MyGame::GetWindowName() const
{
	return gWindowName;
}

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

void MyGame::OnEvent(SDL_Event* pEvent) {}

void MyGame::OnEventsConsumed() {}

void MyGame::Run( float fDeltaT )
{
	mP1->Update(fDeltaT);
	mP2->Update(fDeltaT);

	// Score Player 1
	std::string str1 = std::to_string(ScorePlayer1);
	const char* c1 = str1.c_str();
	mEngine->DrawText(mFontID, exVector2{ 150,50 }, c1, Utils::GetColorRGB(0, 0, 255, 255), 1);
	// Score Player 2
	std::string str2 = std::to_string(ScorePlayer2);
	const char* c2 = str2.c_str();
	mEngine->DrawText(mFontID, exVector2{ 600,50 }, c2, Utils::GetColorRGB(255, 0, 0, 255), 1);
	
	// run simulation first
	for (COGPhysics* pPhysics : COGPhysics::mPhysicsComponents)
	{
		pPhysics->Update(fDeltaT);
	}

	// then render everything
	for (COGShape* pShape : COGShape::mShapeComponents)
	{
		pShape->Render();
	}
}
