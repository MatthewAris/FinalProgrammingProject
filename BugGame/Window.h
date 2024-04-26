#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "EventManager.h"

class Window
{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void BeginDraw() { m_window.clear(sf::Color::Black); } // Clear display
	void EndDraw() { m_window.display(); } // Display the changes
	
	void Update();

	bool IsDone() { return m_isDone; }
	bool IsFullScreen() { return m_isFullscreen; }
	sf::Vector2u GetWindowSize() { return m_windowSize; }
	sf::RenderWindow* GetRenderWindow() { return &m_window; }

	bool IsFocused() { return m_isFocused; }
	EventManager* GetEventManager() { return &m_eventManager; }

	void ToggleFullscreen(EventDetails* l_details);
	void Close(EventDetails* l_details = nullptr) { m_isDone = true; }
	
	void Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }

	sf::FloatRect GetViewSpace();
private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();
	
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;

	EventManager m_eventManager;
	bool m_isFocused;
};