#pragma once
// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>
#include "Window.h"

class GameWorld
{
public:
	GameWorld() : m_window("Game", sf::Vector2u(800, 600))
	{
		m_mushroomTexture.loadFromFile("dvd.png");
		m_mushroom.setTexture(m_mushroomTexture);
		m_increment = sf::Vector2i(400, 400);
	}
	
	~GameWorld() {};

	void HandleInput() {};
	void Update();
	void Render();
	Window* GetWindow() { return &m_window; }

	sf::Time GetElapsed() { return m_elapsed; }
	void RestartClock() { m_elapsed = m_clock.restart(); }

private:
	void MoveMushroom();
	Window m_window;
	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2i m_increment;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};

