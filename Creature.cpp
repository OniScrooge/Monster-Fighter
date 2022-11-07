#include "Creature.h"
#include "Monster.h"
#include "Player.h"

void Creature::addGold(const int gold)
{
	m_gold += gold;
}

bool Creature::isDead()
{
	if (m_health <= 0)
		return 1;
	else
		return 0;
}

void Creature::reduceHealth(const int damage)
{
	m_health -= damage;
}