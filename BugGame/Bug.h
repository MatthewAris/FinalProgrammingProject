#pragma once
#include <SFML/Graphics.hpp>

struct SnakeSegment {
	SnakeSegment(int x, int y) : position(x,y) {}
	sf::Vector2i position;
};

using BugContainer = std::vector<SnakeSegment>;
enum class Direction { None, Up, Down, Left, Right };

class Bug
{
public:
	Bug(int l_blockSize);
	~Bug();

	// Helper methods;
	void SetDirection(Direction l_dir) { m_dir = l_dir; }
	Direction GetDirection() { return m_dir; }
	int GetSpeed() { return m_speed; }
	sf::Vector2i GetPosition() { 
		return (!m_snakeBody.empty() ? m_snakeBody.front().position : sf::Vector2i(1,1)); 
	}

	int GetLives() { return m_lives; }
	int GetScore() { return m_score; }

	void IncreaseScore() { m_score += 10; }
	bool HasLost() { return m_lost; }
	void Lose() { m_lost = true; }
	void ToggleLost() { m_lost = !m_lost; }

	void Extend();
	void Reset();

	void Move();
	void Tick();
	void Cut(int l_segments);
	void Render(sf::RenderWindow& l_window);

	Direction GetPhysicalDirection();

private:
	void CheckCollision();

	BugContainer m_snakeBody;
	int m_size;
	Direction m_dir;
	int m_speed;
	int m_lives;
	int m_score;
	bool m_lost;
	sf::RectangleShape m_bodyRect;

};

