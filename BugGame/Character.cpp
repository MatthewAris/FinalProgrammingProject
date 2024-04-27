#include "Character.h"
#include "EntityManager.h"
#include "StateManager.h"

void Character::Move(const Direction& l_dir) {
	if (GetState() == EntityState::Dying) { return; }
	m_spriteSheet.SetDirection(l_dir);
	if (l_dir == Direction::Left) { Accelerate(-m_speed.x, 0); }
	else { Accelerate(m_speed.x, 0); }
	if (GetState() == EntityState::Idle) { SetState(EntityState::Walking); }
}

void Character::Jump() {
	if (GetState() == EntityState::Dying || GetState() == EntityState::Jumping || GetState() == EntityState::Hurt) { return; }
	SetState(EntityState::Jumping);
	AddVelocity(0, -m_jumpVelocity);
}

void Character::Attack() {
	if (GetState() == EntityState::Dying || GetState() == EntityState::Jumping ||
		GetState() == EntityState::Hurt || GetState() == EntityState::Attacking)
	{
		return;
	}
	SetState(EntityState::Attacking);
}

void Character::GetHurt(const int& l_damage) {
	if (GetState() == EntityState::Dying || GetState() == EntityState::Hurt) { return; }
	m_hitpoints = (m_hitpoints - l_damage > 0 ? m_hitpoints - l_damage : 0);
	if (m_hitpoints) { SetState(EntityState::Hurt); }
	else { SetState(EntityState::Dying); }
}
