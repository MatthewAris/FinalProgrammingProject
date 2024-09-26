#pragma once
#include "Window.h"
#include "EventManager.h"
#include "StateManager.h"
#include "SharedContext.h"
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void Update();
	void Render();
	void LateUpdate();

	sf::Time GetElapsed() { return m_clock.getElapsedTime(); }

	Window* GetWindow() { return &m_window; }

private:
	SharedContext m_context;
	Window m_window;
	StateManager m_stateManager;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	
	void RestartClock() { m_elapsed = m_clock.restart(); }
};

