#pragma once
#include "COGShape.h"

class COGCircleShape : public COGShape
{
public:

	COGCircleShape(GameObject* pGO, exEngineInterface* pEngine, exColor color, float fRadius);

	virtual ComponentType	GetType() const;

	virtual void			Render() override;

	float					Radius();

	void					Radius(float newRadius);

private:

	float mRadius;

};
