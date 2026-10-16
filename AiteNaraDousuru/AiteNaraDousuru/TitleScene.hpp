#pragma once
#include <Siv3D.hpp>
#include "Common.hpp"

class TitleScene : public App::Scene
{
public:
	TitleScene(const InitData& init);
	void update() override;
	void draw() const override;

private:
	
};
