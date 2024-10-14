#include "Block.h"

Block::Block(int initialNum) : GameObject(35), initialNumBlocks(initialNum) {

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
		position[i] = mi_position[i];
	}
	for (int i = index; i < m_numBlocks - 1; ++i)
	{
		block[i] = m_block[i + 1];
		position[i] = mi_position[i + 1];
	}

	delete[] m_block;
	delete[] mi_position;
	m_block = block;
	mi_position = position;
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
	delete[] mi_position;

	m_numBlocks = initialNumBlocks;

	m_block = new RectangleShape[initialNumBlocks];
	mi_position = new Position[initialNumBlocks];
	for (int i = 0; i < initialNumBlocks; ++i)
	{
		m_block[i].setFillColor(Color::Red);
		m_block[i].setOrigin(m_size / 2.f, m_size / 2.f);
		m_block[i].setSize(Vector2f(m_size, m_size));
	}

	for (int i = 0; i < initialNumBlocks; ++i)
	{
		mi_position[i].x = 40 * (i + 1);
		mi_position[i].y = 25;
		m_block[i].setPosition(mi_position[i].x, mi_position[i].y);
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