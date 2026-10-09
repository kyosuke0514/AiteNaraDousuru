#include "stdafx.h"
#include "ModeSelectScene.hpp"

ModeSelectScene::ModeSelectScene(const InitData& init)
	: IScene{ init }
{
}

void ModeSelectScene::update()
{
	if (SimpleGUI::Button(U"通常モード", Vec2{ 300, 280 }, 200))
	{
		changeScene(U"HowToPlay");
	}

	if (SimpleGUI::Button(U"タイトルへ戻る", Vec2{ 300, 340 }, 200))
	{
		changeScene(U"Title");
	}

}

void ModeSelectScene::draw() const
{
	Font{ 36 }(U"モード選択")
		.drawAt(Scene::Center().x, 180, Palette::Black);
}
