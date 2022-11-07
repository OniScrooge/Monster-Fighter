#include "Creature.h"
#include "Monster.h"
#include "Player.h"

void Player::levelUp()
{
	m_level += 1;
	m_damage += 1;

	std::cout << "You are now level " << m_level << ".\n";
}

bool Player::hasWon()
{
	if (m_level == 20)
		return true;
	else
		return false;
}