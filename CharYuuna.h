#pragma once
#include "Character.h"

class CharYuuna :
	public Character
{
protected:
	float fFrameCheck;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	void FrameUpdate(double deltaTime);

	CharYuuna() {}
	virtual ~CharYuuna() {}
};

