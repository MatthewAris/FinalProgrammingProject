#pragma once
#include "Window.h"
enum class StateType {
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};

struct SharedContext {
	SharedContext() : m_wind(nullptr), m_eventManager(nullptr) {}
	Window* m_wind;
	EventManager* m_eventManager;
};
