# include <Siv3D.hpp> // Siv3D v0.6.16
#include "TitleScene.hpp"
#include "ModeSelectScene.hpp"
#include "HowToPlayScene.hpp"
#include "GameScene.hpp"
#include "RevealScene.hpp"
#include "ResultScene.hpp"
using App = SceneManager<String>;

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	App manager;
	manager.add<TitleScene>(U"Title");
	manager.add<ModeSelectScene>(U"ModeSelect");
	manager.add<HowToPlayScene>(U"HowToPlay");
	manager.add<GameScene>(U"Game");
	manager.add<RevealScene>(U"Reveal");
	manager.add<ResultScene>(U"Result");
	
	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}
