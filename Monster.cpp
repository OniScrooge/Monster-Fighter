#include "Creature.h"
#include "Monster.h"
#include "Player.h"

const Creature& Monster::getDefaultCreature (Type& type)
{
	static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData
	{ {
		{"dragon", 'D', 20, 4, 100},
		{"orc", 'o', 4, 2, 25},
		{"slime", 's', 1, 1, 10}
	  }
	};

	return monsterData.at(static_cast<std::size_t>(type));
}

Monster Monster::getRandomMonster()
{
	static std::mt19937 mt{ std::random_device{}() };
	static std::uniform_int_distribution randomMonster{ 0, 2};

	return static_cast<Type>(randomMonster(mt));
}