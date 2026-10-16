#include "stdafx.h"
#include "ModeSelectScene.hpp"
#include "Common.hpp"

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
	const double centerX = Scene::Center().x;

	Scene::SetBackground(ColorF{ 0.94,0.96,0.99 });

	for (int i = 0; i < static_cast<int>(m_topics.size()); ++i)
	{
		const double x = centerX + i * CardSpacing + m_offset;

		if (x < -200 || x > Scene::Width() + 200)
		{
			continue;
		}

		const bool isSelected = (i == m_selectedIndex);

		const double cardWidth = isSelected ? 270.0 : 240.0;
		const double cardHeight = isSelected ? 190.0 : 170.0;

		const double y = 280.0;

		const RectF card
		{
			x - cardWidth / 2,
			y - cardHeight / 2,
			cardWidth,
			cardHeight
		};

		if (isSelected)
		{
			RoundRect
			{
				card.x,card.y,card.w,card.h,18
			}.draw(ColorF{ 0.25,0.55,0.95 });

			RoundRect
			{
				card.x,card.y,card.w,card.h,18
			}.drawFrame(4, ColorF{ 0.10,0.35,0.80 });
		}
		else
		{
			RoundRect
			{
				card.x,card.y,card.w,card.h	,18
			}.draw(ColorF{ 1.0 });
			RoundRect
			{
				card.x,card.y,card.w,card.h,18
			}.drawFrame(2, ColorF{ 0.80, 0.83, 0.88 });
		}

		//選択中の表示
		if (isSelected)
		{
			Common::GetMainFont()(U"SELECTED")
			.drawAt(x, card.y + card.h - 25,ColorF{ 1.0, 0.9, 0.6 });
		}
	}

	//選択中のお題
	Common::GetMainFont()(U"選択中：" + m_topics[m_selectedIndex])
	.drawAt(centerX, 430,ColorF{ 0.12, 0.16, 0.25 });
}
