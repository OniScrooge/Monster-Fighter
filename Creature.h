#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>

class Creature
{
protected:
	std::string m_name{};
	char m_symbol{};
	int_fast16_t m_health{};
	int_fast16_t m_damage{};
	int_fast16_t m_gold{};

public:
	Creature(const std::string& name, const char symbol, const int_fast16_t health, const int_fast16_t damage, const int_fast16_t gold)
		:m_name{ name }, m_symbol{ symbol }, m_health{health}, m_damage{damage}, m_gold{gold}
	{}

	std::string& getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int_fast16_t getHealth() { return m_health; }
	int_fast16_t getDamage() { return m_damage; }
	int_fast16_t getGold() { return m_gold; }

	void addGold(const int gold);
	bool isDead();
	void reduceHealth(const int damage);

};

#endif