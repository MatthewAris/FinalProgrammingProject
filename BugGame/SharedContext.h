#pragma once
#include "Window.h"
#include "EventManager.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "Map.h"

enum class StateType {
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};

struct SharedContext {
	SharedContext() :
		m_wind(nullptr), 
		m_eventManager(nullptr), 
		m_textureManager(nullptr),
		m_entityManager(nullptr), 
		m_gameMap(nullptr){}
	Window* m_wind;
	EventManager* m_eventManager;
	TextureManager* m_textureManager;
	EntityManager* m_entityManager;
	Map* m_gameMap;
};
