#pragma once
#include "Monster.h"
class StarDust :
	public Monster
{
private:
	float fYMove;
	int iYMoveCount;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	void MoveY(double deltaTime);

	StarDust() {}
	virtual ~StarDust() {}
};

