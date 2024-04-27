#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

enum class EntityType{ Base, Enemy, Player };
enum class EntityState{ Idle, Walking, Jumping, Attacking, Hurt, Dying };

struct TileInfo;

struct CollisionElement {
	CollisionElement(float l_area, TileInfo* l_info, const sf::FloatRect& l_bounds) : 
		m_area(l_area), m_tile(l_info), m_tileBounds(l_bounds) {}
	float m_area;
	TileInfo* m_tile;
	sf::FloatRect m_tileBounds;
};

using Collisions = std::vector<CollisionElement>;

bool SortCollisions(const CollisionElement& l_1, const CollisionElement& l_2) { return l_1.m_area > l_2.m_area; };

class EntityManager;
class EntityBase
{
	friend class EntityManager;
public:
	EntityBase(EntityManager* l_entityMgr) : m_entityManager(l_entityMgr), m_name("BaseEntity"),
		m_type(EntityType::Base), m_referenceTile(nullptr), m_state(EntityState::Idle), m_id(0),
		m_collidingOnX(false), m_collidingOnY(false) {};
	virtual ~EntityBase() {};

	void SetPosition(const float& l_x, const float& l_y) { m_position = sf::Vector2f(l_x, l_y); UpdateAABB(); }
	void SetPosition(const sf::Vector2f& l_pos) { m_position = l_pos; UpdateAABB(); }
	void SetSize(const float& l_x, const float& l_y) { m_size = sf::Vector2f(l_x, l_y); UpdateAABB(); }
	void SetState(const EntityState& l_state) { 
		if (m_state == EntityState::Dying) { return; } 
		m_state = l_state; 
	}
	const sf::Vector2f& GetSize() const { return m_size; }
	std::string GetName() const { return m_name; }
	EntityState GetState() const { return m_state; }
	unsigned int GetId() const { return m_id; }
	EntityType GetType() const { return m_type; }
	const sf::Vector2f& GetPosition() const { return m_position; }

	void Move(float l_x, float l_y);
	void AddVelocity(float l_x, float l_y);
	void Accelerate(float l_x, float l_y);
	void SetAcceleration(float l_x, float l_y);
	void ApplyFriction(float l_x, float l_y);
	virtual void Update(float l_dT);
	virtual void Draw(sf::RenderWindow* l_wind) = 0;
protected:
	void UpdateAABB();
	void CheckCollisions();
	void ResolveCollisions();
	virtual void OnEntityCollision(EntityBase* l_collider, bool l_attack) = 0;

	std::string m_name;
	EntityType m_type;
	unsigned int m_id;
	sf::Vector2f m_position;
	sf::Vector2f m_positionOld;
	sf::Vector2f m_velocity;
	sf::Vector2f m_maxVelocity;
	sf::Vector2f m_speed;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_friction;
	TileInfo* m_referenceTile;
	sf::Vector2f m_size;
	sf::FloatRect m_AABB;
	EntityState m_state;
	
	bool m_collidingOnX;
	bool m_collidingOnY;
	
	Collisions m_collisions;
	EntityManager* m_entityManager;
};

