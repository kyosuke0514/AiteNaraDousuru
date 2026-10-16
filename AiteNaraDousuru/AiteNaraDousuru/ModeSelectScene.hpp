#pragma once
#include <Siv3D.hpp>
#include "Common.hpp"

class ModeSelectScene : public App::Scene
{
public:
	ModeSelectScene(const InitData& init);
	void update() override;
	void draw() const override;

private:
	Array<String>m_topics =
	{
		U"好きな食べ物"
	};
	double m_offset = 0.0;			//カードの移動量
	double m_velocity = 0.0;		//慣性移動の速度
	double m_isDragging = false;	//ドラッグ中か
	double m_prevMouseX = 0.0;		//前フレームマウス位置
	int m_selectedIndex = 0;		//決定するお題番号

	static constexpr double CardSpacing = 300.0;	//カードの間隔
};

