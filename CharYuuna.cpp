#include "stdafx.h"
#include "CharYuuna.h"


void CharYuuna::Init()
{
	Character::Init();
	eType = YUUNA;

	mat = { D3DXVECTOR2(700, 360), 1, 1, 0, 0 };
	idleFrame = { 2, 1, 0, 0 };
	walkFrame = { 4, 1, 0, 0 };
	punchFrame = { 2, 1, 0, 0 };

	eAnimation = IDLE;
	fFrameCheck = 0;

	iCharDir = -1;
	fCharSpeed = 5.0f;
	bIsAttacking = false;

	SetCollider();

	IMAGEMANAGER->AddImage("YUUNA_DEF", "./Texture/Character/Yuuna/Sprite_Character_Yuuna.png");
	IMAGEMANAGER->AddImage("YUUNA_IDLE", "./Texture/Character/Yuuna/Sprite_Character_Yuuna_Idle.png");
	IMAGEMANAGER->AddImage("YUUNA_WALK", "./Texture/Character/Yuuna/Sprite_Character_Yuuna_Walk.png");
	IMAGEMANAGER->AddImage("YUUNA_PUNCH", "./Texture/Character/Yuuna/Sprite_Character_Yuuna_Punch.png");
}

void CharYuuna::Update(double deltaTime)
{
	switch (eAnimation)
	{
	case IDLE:	AnimationIdle(deltaTime);	break;
	case WALK:	AnimationWalk(deltaTime);	break;
	case PUNCH:	AnimationPunch(deltaTime);	break;
	}

	PlayWalk();
	PlayPunch();
	PlayIdle();
}

void CharYuuna::Render()
{
	switch (eAnimation)
	{
	case IDLE:	IMAGEMANAGER->DrawFrameImage("YUUNA_IDLE", idleFrame, mat);		break;
	case WALK:	IMAGEMANAGER->DrawFrameImage("YUUNA_WALK", walkFrame, mat);		break;
	case PUNCH:	IMAGEMANAGER->DrawFrameImage("YUUNA_PUNCH", punchFrame, mat);	break;
	}
}

void CharYuuna::Release()
{
}

//

void CharYuuna::PlayIdle()
{
	if (!(INPUTMANAGER->IsKeyHold(VK_LEFT) || INPUTMANAGER->IsKeyHold(VK_RIGHT) || bIsAttacking))
		eAnimation = IDLE;
}

void CharYuuna::PlayWalk()
{
	if (bIsAttacking)
		return;

	//walkFrame = { 4, 1, 0, 0 };
	if (INPUTMANAGER->IsKeyHold(VK_LEFT))
	{
		iCharDir = 1;
		eAnimation = WALK;

		mat.width = iCharDir;
		mat.pos.x -= iCharDir * fCharSpeed;
	}
	if (INPUTMANAGER->IsKeyHold(VK_RIGHT))
	{
		iCharDir = -1;
		eAnimation = WALK;

		mat.width = iCharDir;
		mat.pos.x -= iCharDir * fCharSpeed;
	}
}

void CharYuuna::PlayPunch()
{
	if (INPUTMANAGER->IsKeyDown('A'))
	{
		if (eAnimation != PUNCH)
		{
			punchFrame = { 2, 1, 0, 0 };
			fFrameCheck = 0;
		}
		eAnimation = PUNCH;
		bIsAttacking = true;
	}
}

void CharYuuna::AnimationIdle(double deltaTime)
{
	fFrameCheck += deltaTime;

	if (fFrameCheck >= 0.3f)
	{
		idleFrame.wIndex++;
		if (idleFrame.wIndex >= idleFrame.wCount)
			idleFrame.wIndex = 0;

		fFrameCheck = 0;
	}
}

void CharYuuna::AnimationWalk(double deltaTime)
{
	fFrameCheck += deltaTime;

	if (fFrameCheck >= 0.1f)
	{
		walkFrame.wIndex++;
		if (walkFrame.wIndex >= walkFrame.wCount)
			walkFrame.wIndex = 0;

		fFrameCheck = 0;
	}
}

void CharYuuna::AnimationPunch(double deltaTime)
{
	fFrameCheck += deltaTime;

	if (fFrameCheck >= 0.1f)
	{
		punchFrame.wIndex++;
		if (punchFrame.wIndex >= punchFrame.wCount)
		{
			punchFrame = { 2, 1, 0, 0 };
			PlayIdle();
			bIsAttacking = false;
		}

		fFrameCheck = 0;
	}
}

void CharYuuna::SetCollider()
{
	CircleCollider* destA = new CircleCollider(mat.pos, D3DXVECTOR2(18.0f, 20.0f), 24.0f);
	col.colliderList.push_back(destA);
	RectCollider* destB = new RectCollider(mat.pos, D3DXVECTOR2(12.0f, 31.0f), 27.0f, 58.0f);
	col.colliderList.push_back(destB);
}
