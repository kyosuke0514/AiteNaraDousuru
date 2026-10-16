#pragma once
#include <Siv3D.hpp>
#include "Common.hpp"

class RevealScene :public App::Scene
{
public:
	RevealScene(const InitData& init);
	void update()override;
	void draw() const override;
};
