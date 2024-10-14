#pragma once
#include <SFML/Graphics.hpp>
#include <cassert>
#include "Math.h"
#include "const.h"
using namespace sf;

class Texts
{
	Font font;
	Text text;

public:
	Texts(const std::string s_text, int positionX, int positionY, int size);
	void draw(RenderWindow& window);
};