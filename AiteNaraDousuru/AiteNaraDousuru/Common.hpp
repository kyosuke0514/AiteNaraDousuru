#pragma once
#include <Siv3D.hpp>

struct GameData
{
	String selectedTopic;
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
};

