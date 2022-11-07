#ifndef PLAYER_H
#define PLAYER_H
#include <cstdint>

class Player : public Creature
{
private:
	int_fast16_t m_level{};

public:
	Player(const std::string& name = "",
		const char symbol = '@',
		const int_fast16_t health = 10,
		const int_fast16_t damage = 1,
		const int_fast16_t gold = 0,
		const int_fast16_t level = 1)
		:Creature{name, symbol, health, damage, gold}, m_level{level}
	{}

	void levelUp();
	int getLevel() { return m_level; }
	bool hasWon();
};

#endif