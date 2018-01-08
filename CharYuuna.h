#pragma once
#include "Character.h"

class CharYuuna :
	public Character
{
public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	CharYuuna() {}
	virtual ~CharYuuna() {}
};

