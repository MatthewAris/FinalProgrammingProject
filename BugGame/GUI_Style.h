#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>

enum class GUI_ElementState { Neutral, Focused, Clicked };

struct GUI_Style {
	GUI_Style() : m_textSize(12), m_textCenterOrigin(false), m_backgroundImageColour(255, 255, 255, 255) {
		sf::Color none = sf::Color(0, 0, 0, 0);
		m_backgroundColour = none;
		m_elementColour	= none;
		m_textColour = none;
	}

	sf::Vector2f m_size; // Element Size
	// Background properties
	sf::Color m_backgroundColour;
	sf::Color m_elementColour;
	std::string m_backgroundImage;
	sf::Color m_backgroundImageColour;
	// Text properties
	sf::Color m_textColour;
	std::string m_textFont;
	sf::Vector2f m_textPadding;
	unsigned int m_textSize;
	bool m_textCenterOrigin;
	// Glyph properties
	std::string m_glyph;
	sf::Vector2f m_glyphPadding;
};

struct GUI_Visual {
	sf::RectangleShape m_backgroundSolid;
	sf::Sprite m_backgroundImage;
	sf::Sprite m_glyph;
	sf::Text m_text;
};