#pragma once
#include "Unit.h"


class Monster :
	public Unit
{
protected:
	enum MONSTER_TYPE
	{
		STARDUST = 1,
		VERTEX
	} eType;
	float fHate;

	matrix mat;
	frameData frame;

	Collider col;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	void SetCollider() {}
	Collider GetCollider() { return col; }

	Monster() {}
	virtual ~Monster() {}
};