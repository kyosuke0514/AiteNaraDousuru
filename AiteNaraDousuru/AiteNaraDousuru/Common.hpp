#pragma once
#include <Siv3D.hpp>

//全部で何問遊ぶか
constexpr int32 MaxRounds = 3;

struct GameData
{
	String selectedTopic;

	int32 round = 1;		// 今何問目か
};

using App = SceneManager<String,GameData>;

class Common
{
public:
	static const Font& GetFont()
	{
		static const Font font{ 40 };
		return font;
	}

	static const Font& GetMainFont()
	{
		static const Font font{ 30 };
		return font;
	}

	static const Font& GetSmallFont()
	{
		static const Font font{ 22 };
		return font;
	}

	//文字色
	static constexpr ColorF TextColor{ 0.12, 0.16, 0.25 };
};

