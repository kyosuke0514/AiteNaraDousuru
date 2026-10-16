#pragma once
#include <Siv3D.hpp>
#include "Common.hpp"

class GameScene : public App::Scene
{
public:
	GameScene(const InitData& init);
	void update() override;
	void draw() const override;
};

