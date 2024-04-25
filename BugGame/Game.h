#pragma once
// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "World.h"
#include "Bug.h"
#include "Textbox.h"
#include "StateManager.h"
class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow() { return &m_window; }

	sf::Time GetElapsed() { return m_elapsed; }
	void RestartClock() { m_elapsed += m_clock.restart(); }

	void MoveSprite(EventDetails* l_details);

	void LateUpdate();

private:

	Window m_window;
	World m_world;
	Bug m_snake;
	Textbox m_textbox;

	sf::Clock m_clock;
	sf::Time m_elapsed;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	StateType m_state;
	StateManager m_stateManager;
	SharedContext m_context;
};

