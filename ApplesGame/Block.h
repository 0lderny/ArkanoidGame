#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "const.h"
#include "Math.h"
using namespace sf;

class Block : public GameObject
{
	RectangleShape* m_block;
	Position* mb_position;
	const int m_initialNumBlocks;
	int m_numBlocks;

public:
	Block();
	Block(int numBlocks);
	~Block();
	Position getPosition(int index) const { return mb_position[index]; }
	int getNumBlocks() const { return m_numBlocks; }
	int getSize() const { return m_size; }

	void remove(int index);
	virtual void reset() override;
	virtual void move(float deltaTime) override;
	virtual void draw(RenderWindow& window) override;
	bool noBlocks() const;
};