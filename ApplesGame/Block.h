#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "const.h"
#include "Math.h"
using namespace sf;

class Block : public GameObject
{
	RectangleShape* m_block;
	Position* mi_position;
	const int initialNumBlocks;
	int m_numBlocks;

public:
	Block(int numBlocks);
	~Block();
	Position getPosition(int index) const { return mi_position[index]; }
	int getNumBlocks() const { return m_numBlocks; }
	int getSize() const { return m_size; }

	void remove(int index);
	void reset() override;
	void move(float deltaTime) override;
	void draw(RenderWindow& window) override;
	bool noBlocks() const;
};