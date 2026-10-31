#include "stdafx.h"
#include "ModeSelectScene.hpp"
#include "Common.hpp"

ModeSelectScene::ModeSelectScene(const InitData& init)
	: IScene{ init }
{
	Scene::SetBackground(ColorF{ 0.94, 0.96, 0.99 });
}

void ModeSelectScene::update()
{
	const double centerX = Scene::Center().x;

	const double minOffset = -CardSpacing * (m_topics.size() - 1);

	//マウスを押した瞬間
	const double mouseY = Cursor::PosF().y;
	if (MouseL.down()&& (CardAreaTop <= mouseY)&&(mouseY <= CardAreaBottom))
	{
		m_isDragging = true;
		m_prevMouseX = Cursor::PosF().x;
		m_velocity = 0.0;
	}

	//ドラッグ中
	if (m_isDragging && MouseL.pressed())
	{
		const double mouseX = Cursor::PosF().x;
		const double deltaX = mouseX - m_prevMouseX;

		m_offset += deltaX;
		m_velocity = deltaX;

		m_prevMouseX = mouseX;

		m_offset = Clamp(m_offset, minOffset, 0.0);
	}

	if (MouseL.up())
	{
		m_isDragging = false;
	}

	if (not m_isDragging)
	{
		m_offset += m_velocity;
		m_velocity *= 0.90;

		if (m_offset > 0.0)
		{
			m_offset = 0.0;
			m_velocity = 0.0;
		}

		if (m_offset < minOffset)
		{
			m_offset = minOffset;
			m_velocity = 0.0;
		}
	}

	m_selectedIndex = Clamp(static_cast<int>(Math::Round(-m_offset / CardSpacing)), 0, static_cast<int>(m_topics.size()) - 1);

	// 勢いがなくなったら、一番近いカードが中央に来るように吸い寄せる
	if ((not m_isDragging) && (Abs(m_velocity) < 1.0))
	{
		m_velocity = 0.0;
		const double target = -m_selectedIndex * CardSpacing;
		m_offset = Math::Lerp(m_offset, target, 0.2);
	}

	if ((not m_isDragging) && SimpleGUI::Button(U"このお題に決める", Vec2{ centerX - 100, 510 }, 200))
	{
		getData().selectedTopic = m_topics[m_selectedIndex];
		changeScene(U"HowToPlay", 0.4s);
	}

	if ((not m_isDragging) && SimpleGUI::Button(U"タイトルに戻る", Vec2{ 20, 20 }, 160))
	{
		changeScene(U"Title");
	}
}

void ModeSelectScene::draw() const
{
	const double centerX = Scene::Center().x;

	//何問目か
	Common::GetMainFont()(U"第{}問 / 全{}問"_fmt(getData().round, MaxRounds))
		.drawAt(centerX, 110, Common::TextColor);

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

		const RoundRect card{ x - cardWidth / 2, y - cardHeight / 2, cardWidth, cardHeight, 18 };

		if (isSelected)
		{
			card.draw(ColorF{ 0.25, 0.55, 0.95 });
			card.drawFrame(4, ColorF{ 0.10, 0.35, 0.80 });
		}
		else
		{
			card.draw(ColorF{ 1.0 });
			card.drawFrame(2, ColorF{ 0.80, 0.83, 0.88 });
		}

		//お題名をカードに表示
		Common::GetSmallFont()(m_topics[i])
			.drawAt(x, y - 10, isSelected ? ColorF{ 1.0 } : Common::TextColor);

		//選択中の表示
		if (isSelected)
		{
			Common::GetMainFont()(U"SELECTED")
				.drawAt(x, card.y + card.h - 25, ColorF{ 1.0, 0.9, 0.6 });
		}
	}

	//選択中のお題
	Common::GetMainFont()(U"選択中：" + m_topics[m_selectedIndex])
	.drawAt(centerX, 430, Common::TextColor);
}
