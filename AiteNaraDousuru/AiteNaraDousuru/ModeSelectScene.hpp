#pragma once
#include <Siv3D.hpp>
using App = SceneManager<String>;

class ModeSelectScene : public App::Scene
{
public:
	ModeSelectScene(const InitData& init) : IScene{ init }{}
	void update() override;
	void draw() const override;
};

