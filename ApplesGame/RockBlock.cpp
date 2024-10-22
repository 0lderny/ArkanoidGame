#include "RockBlock.h"

RockBlock::RockBlock() : RockBlock(26) {

}

RockBlock::RockBlock(int initialNum) : GameObject(35), m_initialNumBlocks(initialNum) {

	reset();
}

RockBlock::~RockBlock()
{
	delete[] m_block;
}

void RockBlock::remove(int index)
{
	--m_hit[index];
	m_color[index] += 50;
	if (m_hit[index] <= 0)
	{
		RectangleShape* block = new RectangleShape[m_numBlocks - 1];
		Position* position = new Position[m_numBlocks - 1];
		int* hit = new int[m_numBlocks - 1];
		int* color = new int[m_numBlocks - 1];

		for (int i = 0; i < index; ++i)
		{
			block[i] = m_block[i];
			position[i] = mb_position[i];
			hit[i] = m_hit[i];
			color[i] = m_color[i];
		}
		for (int i = index; i < m_numBlocks - 1; ++i)
		{
			block[i] = m_block[i + 1];
			position[i] = mb_position[i + 1];
			hit[i] = m_hit[i + 1];
			color[i] = m_color[i + 1];
		}

		delete[] m_block;
		delete[] mb_position;
		delete[] m_hit;
		delete[] m_color;
		m_block = block;
		mb_position = position;
		m_hit = hit;
		m_color = color;
		--m_numBlocks;

		for (int i = 0; i < m_numBlocks; ++i)
		{
			m_block[i].setFillColor(Color(m_color[i], 0, 0));
			m_block[i].setOrigin(m_size / 2.f, m_size / 2.f);
			m_block[i].setSize(Vector2f(m_size, m_size));
			m_block[i].setPosition(position[i].x, position[i].y);
		}
	}
}

void RockBlock::reset()
{
	delete[] m_block;
	delete[] mb_position;
	delete[] m_hit;
	delete[] m_color;

	m_numBlocks = m_initialNumBlocks;

	m_block = new RectangleShape[m_initialNumBlocks];
	mb_position = new Position[m_initialNumBlocks];
	m_hit = new int[m_initialNumBlocks];
	m_color = new int[m_initialNumBlocks];
	for (int i = 0; i < m_initialNumBlocks; ++i)
	{
		m_hit[i] = 3;
		m_color[i] = 150;
		m_block[i].setFillColor(Color(m_color[i], 0, 0));
		m_block[i].setOrigin(m_size / 2.f, m_size / 2.f);
		m_block[i].setSize(Vector2f(m_size, m_size));

		mb_position[i].x = 40 * (i + 1);
		mb_position[i].y = 100;
		m_block[i].setPosition(mb_position[i].x, mb_position[i].y);
	}
}

void RockBlock::move(float deltaTime) {}

void RockBlock::draw(RenderWindow& window)
{
	for (int i = 0; i < m_numBlocks; ++i)
	{
		m_block[i].setFillColor(Color(m_color[i], 0, 0));
		window.draw(m_block[i]);
	}
}

bool RockBlock::noBlocks() const
{
	return m_numBlocks == 0;
}
