#include "stdafx.h"
#include "TitleScene.hpp"

TitleScene::TitleScene(const InitData& init)
	: IScene{ init }
{
}

void TitleScene::update()
{
	if (SimpleGUI::Button(U"スタート", Vec2{ 500, 400 }))
	{
		changeScene(U"ModeSelect");
	}
}

void TitleScene::draw() const
{
	Font{ 40 }(U"相手ならどうする？")
		.drawAt(Scene::Center().x, 180, Palette::Black);
}
