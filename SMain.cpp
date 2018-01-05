#include "stdafx.h"
#include "SMain.h"

SMain::SMain()
{
}

SMain::~SMain()
{
}

void SMain::Init() 
{
	IMAGEMANAGER->AddImage("MAIN", "./Texture/sprites.jpg");
	SOUNDMANAGER->LoadSound("BFLY", "./Sound/03. Butterfly.mp3", BGM);
	SOUNDMANAGER->LoadSound("PING", "./Sound/PING.wav", SE);
	mat = { 0, 0, 0, 0, 0, 0 };
}

void SMain::Update(double deltaTime)
{
	if (INPUTMANAGER->IsKeyDown('Z'))
		SOUNDMANAGER->PlaySound("BFLY");
	if (INPUTMANAGER->IsKeyDown('X'))
		SOUNDMANAGER->StopSound("BFLY");

	if (INPUTMANAGER->IsKeyDown('C'))
		SOUNDMANAGER->PlaySound("PING");
}

void SMain::Render() 
{
	IMAGEMANAGER->DrawImage("MAIN", mat);
}

void SMain::Release()
{

}