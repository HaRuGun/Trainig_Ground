#pragma once
#include "Object.h"

struct unitStatus
{
	float fHp, fAtk, fDef;
};

class Unit :
	public Object
{
protected:
	unitStatus sStat;

public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render() {}
	virtual void Release() {}

	unitStatus* GetStat() { return &sStat; }
	void SetStat(unitStatus stat) { sStat = stat; }

	Unit() {}
	virtual ~Unit() {}
};

