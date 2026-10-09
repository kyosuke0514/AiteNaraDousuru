#pragma once
#include <Siv3D.hpp>

using App = SceneManager<String>;

class TitleScene : public App::Scene
{
public:
	TitleScene(const InitData& init) : IScene{ init } {}
	void update() override;
	void draw() const override;
};
