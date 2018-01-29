#include "stdafx.h"
#include "CharYuuna.h"


void CharYuuna::Init()
{
	Character::Init();
	eType = YUUNA;

	mat = { 1, 1, 700, 320, 0, 0 };
	frame = { 2, 1, 0, 0 };

	fFrameCheck = 0;

	IMAGEMANAGER->AddImage("YUUNA_DEF", "./Texture/Character/Yuuna/Sprite_Character_Yuuna.png");
	IMAGEMANAGER->AddImage("YUUNA_IDLE", "./Texture/Character/Yuuna/Sprite_Character_Yuuna_Idle.png");
	IMAGEMANAGER->AddImage("YUUNA_Walk", "./Texture/Character/Yuuna/Sprite_Character_Yuuna_Walk.png");
	IMAGEMANAGER->AddImage("YUUNA_PUNCH", "./Texture/Character/Yuuna/Sprite_Character_Yuuna_Punch.png");
}

void CharYuuna::Update(double deltaTime)
{
	FrameUpdate(deltaTime);
}

void CharYuuna::Render()
{
	IMAGEMANAGER->DrawFrameImage("YUUNA_IDLE", frame, mat);
}

void CharYuuna::Release()
{
}

//

void CharYuuna::FrameUpdate(double deltaTime)
{
	fFrameCheck += deltaTime;

	if (fFrameCheck >= 0.5f)
	{
		frame.wIndex++;
		if (frame.wIndex >= frame.wCount)
			frame.wIndex = 0;

		fFrameCheck = 0;
	}
}
