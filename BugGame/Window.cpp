#include "Window.h"

Window::Window() {	Setup("Window", sf::Vector2u(640, 480));  }

Window::Window(const std::string& l_title, const sf::Vector2u& l_size) {  Setup(l_title, l_size);  }

Window::~Window() {	 Destroy();	}

