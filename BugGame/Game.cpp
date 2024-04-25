#include "Game.h"
#include <iostream>

Game::Game() : m_window("Chapter 5",  sf::Vector2u(800,600)), m_stateManager(&m_context)
{
	m_textbox.Setup(5, 14, 360, sf::Vector2f(255, 0));

	//m_textbox.Add("Seeded Ranfom Number Generator With: " + std::to_string(time(NULL)));
	//m_texture.loadFromFile("Data/dvd.png");
	//m_sprite.setTexture(m_texture);

	//m_window.GetEventManager()->AddCallback("Intro_Continue", &Game::, this);

	m_context.m_wind = &m_window;
	m_context.m_eventManager = m_window.GetEventManager();
	m_stateManager.SwitchTo(StateType::Intro);
}

Game::~Game() {}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetPhysicalDirection() != Direction::Down) {
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetPhysicalDirection() != Direction::Up) {
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right) {
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left) {
		m_snake.SetDirection(Direction::Right);
	}
}

void Game::Update()
{
	m_window.Update();
	m_stateManager.Update(m_elapsed);
}

void Game::Render()
{
	m_window.BeginDraw();
	m_stateManager.Draw();
	m_window.EndDraw();
}

void Game::MoveSprite(EventDetails* l_details)
{
	sf::Vector2i mousepos = m_window.GetEventManager()->GetMousePos(m_window.GetRenderWindow());
	m_sprite.setPosition(mousepos.x, mousepos.y);
	std::cout << "Moving sprite to: " << mousepos.x << ":" << mousepos.y << std::endl;
}

void Game::LateUpdate()
{
	m_stateManager.ProcessRequests();
	RestartClock();
}
