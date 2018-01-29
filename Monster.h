#pragma once
#include "Unit.h"

enum MONSTER_TYPE
{
	STARDUST = 1,
	VERTEX
};

class Monster :
	public Unit
{
protected:
	MONSTER_TYPE eType;
	float fHate;

	matrix mat;
	frameData frame;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();
	
	Monster() {}
	virtual ~Monster() {}
};

