#pragma once
#include "Monster.h"
class Character;

class MonStardust :
	public Monster
{
private:
	float fYMove;
	int iYMoveCount;

	Character* pChar;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	void SetPosition(D3DXVECTOR2 pos);

	void MoveY(double deltaTime);

	void SetCollider();
	void SetChar(Character * p) { pChar = p; }

	MonStardust() {}
	virtual ~MonStardust() {}
};

