#include "EntityBase.h"
#include "EntityManager.h"

void EntityBase::Move(float l_x, float l_y)
{
	m_positionOld = m_position;
	m_position += sf::Vector2f(l_x, l_y);
	sf::Vector2u mapSize = m_entityManager->GetContext()->m_gameMap->GetMapSize();
	if (m_position.x < 0) {
		m_position.x = 0;
	}
	else if (m_position.x > (mapSize.x + 1) * Sheet::Tile_Size) {
		m_position.x = (mapSize.x + 1) * Sheet::Tile_Size;
	}

	if (m_position.y < 0) {
		m_position.y = 0;
	}
	else if (m_position.y > (mapSize.y + 1) * Sheet::Tile_Size) {
		m_position.y = (mapSize.y + 1) * Sheet::Tile_Size;
		SetState(EntityState::Dying);
	}
	UpdateAABB();
}

void EntityBase::AddVelocity(float l_x, float l_y)
{
	m_velocity += sf::Vector2f(l_x, l_y);
	if (abs(m_velocity.x) > m_maxVelocity.x) {
		if(m_velocity.x < 0) { m_velocity.x = -m_maxVelocity.x; }
		else { m_velocity.x = m_maxVelocity.x; }
	}
	if (abs(m_velocity.y) > m_maxVelocity.y) {
		if (m_velocity.y < 0) { m_velocity.y = -m_maxVelocity.y; }
		else { m_velocity.y = m_maxVelocity.y; }
	}
}

void EntityBase::Accelerate(float l_x, float l_y)
{
	m_acceleration += sf::Vector2f(l_x, l_y);
}

void EntityBase::SetAcceleration(float l_x, float l_y)
{
	m_acceleration = sf::Vector2f(l_x, l_y);
}

void EntityBase::ApplyFriction(float l_x, float l_y)
{
	if (m_velocity.x != 0) {
		if (abs(m_velocity.x) - abs(l_x) < 0) { m_velocity.x = 0; }
		else {
			if (m_velocity.x < 0) { m_velocity.x += l_x; }
			else { m_velocity.x -= l_x; }
		}
	}

	if (m_velocity.y != 0) {
		if (abs(m_velocity.y) - abs(l_y) < 0) { m_velocity.y = 0; }
		else {
			if (m_velocity.y < 0) { m_velocity.y += l_y; }
			else { m_velocity.y -= l_y; }
		}
	}
}

void EntityBase::Update(float l_dT)
{
	Map* map = m_entityManager->GetContext()->m_gameMap;
	float gravity = map->GetGravity();
	Accelerate(0, gravity);
	AddVelocity(m_acceleration.x * l_dT, m_acceleration.y * l_dT);
	SetAcceleration(0.0f, 0.0f);
	sf::Vector2f frictionValue;
	if (m_referenceTile) {
		frictionValue = m_referenceTile->m_friction;
		if (m_referenceTile->m_deadly) { SetState(EntityState::Dying); }
	}
	else if (map->GetDefaultTile()) {
		frictionValue = map->GetDefaultTile()->m_friction;
	}
	else {
		frictionValue = m_friction;
	}

	float friction_x = (m_speed.x * frictionValue.x) * l_dT;
	float friction_y = (m_speed.y * frictionValue.y) * l_dT;
	ApplyFriction(friction_x, friction_y);
	sf::Vector2f deltaPos = m_velocity * l_dT;
	Move(deltaPos.x, deltaPos.y);
	m_collidingOnX = false;
	m_collidingOnY = false;
	CheckCollisions();
	ResolveCollisions();
}

void EntityBase::UpdateAABB()
{
	m_AABB = sf::FloatRect(m_position.x - (m_size.x / 2), m_position.y - m_size.y, m_size.x, m_size.y);
}

void EntityBase::CheckCollisions()
{
	Map* gameMap = m_entityManager->GetContext()->m_gameMap;
	unsigned int tileSize = gameMap->GetTileSize();
	int fromX = floor(m_AABB.left / tileSize);
	int toX = floor((m_AABB.left + m_AABB.width) / tileSize);
	int fromY = floor(m_AABB.top / tileSize);
	int toY = floor((m_AABB.top + m_AABB.height) / tileSize);

	for (int x = fromX; x <)
}

void EntityBase::ResolveCollisions()
{
}
