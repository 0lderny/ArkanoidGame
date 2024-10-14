#include "Text.h"

Texts::Texts(const std::string s_text, int positionX, int positionY, int size)
{
	assert(font.loadFromFile(RESOURCES + "\\papyrus-pixel_1.ttf"));
	text.setFont(font);
	text.setPosition(positionX, positionY);
	text.setCharacterSize(size);
	text.setFillColor(Color::Yellow);
	text.setString(s_text);
}

void Texts::draw(RenderWindow& window)
{
	window.draw(text);
}