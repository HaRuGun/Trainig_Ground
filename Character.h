#pragma once
#include "Unit.h"

enum CHARACTER_TYPE
{
	YUUNA = 1,
	TOGO,
	HUU,
	ITSUKI,
	KARIN
};

class Character :
	public Unit
{
protected:
	CHARACTER_TYPE eType;
	
	//Texture
	matrix mat;
	frameData frame;

	int iPetalCount;
	bool bIsBloomed;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	Character() {}
	virtual ~Character() {}
};

