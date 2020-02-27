#pragma once
#include "Component.h"
#include "Engine/Public/EngineInterface.h"

class COGTransform;

class COGShape : public Component
{
public:

	static std::vector<COGShape*> mShapeComponents;

public:

	COGShape(GameObject * pGO, exEngineInterface * pEngine, exColor pColor);

	virtual void	Initialize() override;

	virtual void	Destroy() override;

	virtual void	Render() = 0;

	exColor			Color() const;

protected:

	exColor			mColor;

	COGTransform*	mTransform;

};
