#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "TextureManager.h"
#include "Anim_Directional.h"
#include "Utilities.h"
#include <unordered_map>

using Animations = std::unordered_map<std::string, Anim_Base*>;

class SpriteSheet
{
public:
	SpriteSheet(TextureManager* l_textMgr) : m_textureManager(l_textMgr),
		m_animationCurrent(nullptr), m_spriteScale(1.f, 1.f), m_direction(Direction::Right) {};
	~SpriteSheet() { ReleaseSheet(); }

	void CropSprite(const sf::IntRect& l_rect) { m_sprite.setTextureRect(l_rect); }

	void SetSpriteSize(const sf::Vector2i& l_size);
	void SetSpritePosition(const sf::Vector2f& l_pos) { m_sprite.setPosition(l_pos); }
	void SetDirection(const Direction& l_dir);
	sf::Vector2i GetSpriteSize() { return m_spriteSize; }
	sf::Vector2f GetSpriteScale() { return m_spriteScale; }
	Direction GetDirection() { return m_direction; }

	bool LoadSheet(const std::string& l_file);
	void ReleaseSheet();

	Anim_Base* GetCurrentAnim() { return m_animationCurrent; }
	bool SetAnimation(const std::string& l_name, const bool& l_play = false, const bool& l_loop = false);

	void Update(const float& l_dT) { m_animationCurrent->Update(l_dT); }
	void Draw(sf::RenderWindow* l_wnd) { l_wnd->draw(m_sprite); }
private:
	std::string m_texture;
	sf::Sprite m_sprite;
	sf::Vector2i m_spriteSize;
	sf::Vector2f m_spriteScale;
	Direction m_direction;
	std::string m_animType;
	Animations m_animations;
	Anim_Base* m_animationCurrent;
	TextureManager* m_textureManager;
};

