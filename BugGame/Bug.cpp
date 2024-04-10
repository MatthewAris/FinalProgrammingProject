#include "Bug.h"

Bug::Bug(int l_blockSize)
{
	m_size = l_blockSize;
	m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
	Reset();
}

Bug::~Bug() {}

void Bug::Extend()
{
	if (m_snakeBody.empty()) { return; }
	SnakeSegment& tail_head = m_snakeBody[m_snakeBody.size() - 1];

	if (m_snakeBody.size() > 1) {
		SnakeSegment& tail_bone = m_snakeBody[m_snakeBody.size() - 2];
		if (tail_head.position.x == tail_bone.position.x) {
			if (tail_head.position.y > tail_bone.position.y) {
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_bone.position.y + 1));
			}
			else {
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_bone.position.y - 1));
			}
		}
		else if (tail_head.position.y == tail_bone.position.y) {
			if (tail_head.position.x > tail_bone.position.x) {
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_bone.position.y));
			}
			else {
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_bone.position.y));
			}
		}
	}
	else {
		if (m_dir == Direction::Up) {
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		}
		else if (m_dir == Direction::Down) {
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		} 
		else if (m_dir == Direction::Left) {
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		}
		else if (m_dir == Direction::Right) {
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
	}
}

void Bug::Reset()
{
	m_snakeBody.clear();

	m_snakeBody.push_back(SnakeSegment(5, 7));
	m_snakeBody.push_back(SnakeSegment(5, 6));
	m_snakeBody.push_back(SnakeSegment(5, 5));

	SetDirection(Direction::None);
	m_speed = 15;
	m_lives = 3;
	m_score = 0;
	m_lost = false;

}

void Bug::Move()
{
	for (int i = m_snakeBody.size() - 1; i > 0; --i) {
		m_snakeBody[i].position = m_snakeBody[i - 1].position;
	}
	if (m_dir == Direction::Left) {
		--m_snakeBody[0]
	}
}

void Bug::Tick()
{
	if (m_snakeBody.empty()) { return; }
	if (m_dir == Direction::None) { return; }
	Move();
	CheckCollision();
}
