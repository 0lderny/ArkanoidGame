#include "Block.h"

Block::Block() : Block(26) {

}

Block::Block(int initialNum) : GameObject(35), m_initialNumBlocks(initialNum) {

	reset();
}

Block::~Block()
{
	delete[] m_block;
}

void Block::remove(int index)
{
	RectangleShape* block = new RectangleShape[m_numBlocks - 1];
	Position* position = new Position[m_numBlocks - 1];

	for (int i = 0; i < index; ++i)
	{
		block[i] = m_block[i];
		position[i] = mb_position[i];
	}
	for (int i = index; i < m_numBlocks - 1; ++i)
	{
		block[i] = m_block[i + 1];
		position[i] = mb_position[i + 1];
	}

	delete[] m_block;
	delete[] mb_position;
	m_block = block;
	mb_position = position;
	--m_numBlocks;

	for (int i = 0; i < m_numBlocks; ++i)
	{
		m_block[i].setFillColor(Color::Red);
		m_block[i].setOrigin(m_size / 2.f, m_size / 2.f);
		m_block[i].setSize(Vector2f(m_size, m_size));
		m_block[i].setPosition(position[i].x, position[i].y);
	}
}

void Block::reset()
{	
	delete[] m_block;
	delete[] mb_position;

	m_numBlocks = m_initialNumBlocks;

	m_block = new RectangleShape[m_initialNumBlocks];
	mb_position = new Position[m_initialNumBlocks];
	for (int i = 0; i < m_initialNumBlocks; ++i)
	{
		m_block[i].setFillColor(Color::Red);
		m_block[i].setOrigin(m_size / 2.f, m_size / 2.f);
		m_block[i].setSize(Vector2f(m_size, m_size));

		mb_position[i].x = 40 * (i + 1);
		mb_position[i].y = 140;
		m_block[i].setPosition(mb_position[i].x, mb_position[i].y);
	}
}

void Block::move(float deltaTime) {}

void Block::draw(RenderWindow& window)
{
	for (int i = 0; i < m_numBlocks; ++i)
	{
		window.draw(m_block[i]);
	}
}

bool Block::noBlocks() const
{
	return m_numBlocks == 0;
}
