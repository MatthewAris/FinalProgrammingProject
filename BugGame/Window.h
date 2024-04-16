#pragma once
#include <string>
#include <SFML/Graphics.hpp>
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
	bool IsFullScreen() { return m_isFullScreen; }
	sf::Vector2u GetWindowSize() { return m_windowSize; }
	sf::RenderWindow* GetRenderWindow() { return &m_window; }
	
	void ToggleFullScreen();
	
	void Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }
	
private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();
	
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullScreen;
};