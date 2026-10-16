#pragma once
#include <Siv3D.hpp>

using App = SceneManager<String>;

class Common
{
public:
	static const Font& GetFont()
	{
		static const Font font{ 40 };
		return font;
	}
};

