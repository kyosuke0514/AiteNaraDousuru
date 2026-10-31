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
	//お題1つ分のデータ
	struct Topic
	{
		String category;								//タグに表示するカテゴリー
		String title;									//お題
		String hint;									//回答例
		String emoji;									//カードに大きく表示する絵文字
		ColorF color;									//カードのテーマ色
	};

	// 画面上でのカードの置き方
	struct CardLayout
	{
		Vec2 center;									//中心位置
		double scale;									//大きさ（1.0 = 中央のカード）
		double fog;										//背景色に溶け込む量（左右ほど大きい）
		double alpha;									//不透明度（遠いカードは消える）
		double offset;									//中央から何枚ずれているか（マイナス = 左）
	};

	Array<String>m_topics =
	{
		U"好きな食べ物"
	};
	double m_offset = 0.0;								//カードの移動量
	double m_velocity = 0.0;							//慣性移動の速度
	double m_isDragging = false;						//ドラッグ中か
	double m_prevMouseX = 0.0;							//前フレームマウス位置
	int m_selectedIndex = 0;							//決定するお題番号

	static constexpr double CardSpacing = 300.0;		//カードの間隔
	static constexpr double CardAreaTop = 170.0;		//ドラッグを受け付ける範囲（上）
	static constexpr double CardAreaBottom = 390.0;		//ドラッグを受け付ける範囲（下）
};

