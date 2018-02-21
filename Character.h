#pragma once
#include "Unit.h"


class Character :
	public Unit
{
protected:
	enum CHARACTER_TYPE
	{
		YUUNA = 1,
		TOGO,
		HUU,
		ITSUKI,
		KARIN
	} eType;

	Collider col;

	int iPetalCount;
	bool bIsBloomed;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	void SetCollider() {}
	Collider GetCollider() { return col; }

	Character() {}
	virtual ~Character() {}
};