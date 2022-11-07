#ifndef MONSTER_H
#define MONSTER_H
#include <array>
#include <random>

class Monster : public Creature
{
public:
	enum Type
	{
		dragon,
		orc,
		slime,

		max_types,
	};

	Monster(Type type)
		:Creature{getDefaultCreature(type)}
	{}

	static const Creature& getDefaultCreature(Type& type);
	static Monster getRandomMonster();

};

#endif