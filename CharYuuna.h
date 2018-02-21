#pragma once
#include "Character.h"


class CharYuuna :
	public Character
{
protected:
	enum ANIMATION_TYPE
	{
		IDLE = 0,
		WALK,
		PUNCH
	} eAnimation;

	float fFrameCheck;

	matrix mat;
	int iCharDir;
	float fCharSpeed;
	bool bIsAttacking;

	frameData idleFrame;
	frameData walkFrame;
	frameData punchFrame;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	void PlayIdle();
	void PlayWalk();
	void PlayPunch();

	void AnimationIdle(double deltaTime);
	void AnimationWalk(double deltaTime);
	void AnimationPunch(double deltaTime);

	void SetCollider();

	CharYuuna() {}
	virtual ~CharYuuna() {}
};

