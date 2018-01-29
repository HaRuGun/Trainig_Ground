#include "stdafx.h"

#include "CharYuuna.h"
#include "StarDust.h"

#include "SMain.h"

SMain::SMain()
{
}

SMain::~SMain()
{
}

void SMain::Init() 
{
	SOUNDMANAGER->LoadSound("BFLY", "./Sound/03. Butterfly.mp3", BGM);
	SOUNDMANAGER->LoadSound("PING", "./Sound/PING.wav", SE);

	yuuna = new CharYuuna();
	yuuna->Init();

	star = new StarDust();
	star->Init();
}

void SMain::Update(double deltaTime)
{
	if (INPUTMANAGER->IsKeyDown('Z'))
		SOUNDMANAGER->PlaySound("BFLY");
	if (INPUTMANAGER->IsKeyDown('X'))
		SOUNDMANAGER->StopSound("BFLY");

	if (INPUTMANAGER->IsKeyDown('C'))
		SOUNDMANAGER->PlaySound("PING");

	yuuna->Update(deltaTime);
	star->Update(deltaTime);
}

void SMain::Render() 
{
	yuuna->Render();
	star->Render();
}

void SMain::Release()
{
	yuuna->Release();
	star->Release();
}