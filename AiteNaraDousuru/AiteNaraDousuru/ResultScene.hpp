#pragma once
#include <Siv3D.hpp>
#include "Common.hpp"

class ResultScene : public App::Scene
{
public:
	ResultScene(const InitData& init);
	void update()override;
	void draw()const override;
};

