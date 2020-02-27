#pragma once
#include "COGShape.h"

class COGBoxShape : public COGShape
{
public:

	COGBoxShape(GameObject* pGO, exEngineInterface* pEngine, exColor color, float fWidth, float fHeight);

	virtual ComponentType	GetType() const;

	virtual void			Render() override;

	float					Width();

	void					Width(float newWidth);

	float					Height();

	void					Height(float newHeight);

private:

	float mWidth;
	float mHeight;

};
