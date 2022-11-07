#include "Creature.h"
#include "Monster.h"
#include "Player.h"
#include "GameLogic.h"

namespace Decide
{
	bool fail{0};
}

Player GameLogic::playerCreation()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;
	std::cout << "Welcome, " << name << '\n';

	return { name };
}

void GameLogic::startGame()
{
	Player player{ GameLogic::playerCreation() };

	while (true)
	{
		if ( player.isDead() || player.hasWon() )
			break;
		Monster m{ Monster::getRandomMonster() };
		std::cout << "You have encountered a " << m.getName() << ".\n";

		if (playerDecision(m, player))
			playerFight(Decide::fail, m, player);
		else
			continue;

		std::cout << '\n';
	}
}

void GameLogic::playerFight(bool choice, Monster& m, Player& p)
{
	if (choice)
	{
		while (!(m.isDead() || p.isDead()))
		{
			std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
			p.reduceHealth(m.getDamage());
			std::cout << "You have " << p.getHealth() << " health remaining.\n";

			if (p.isDead())
				std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
			else
			{
				std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
				m.reduceHealth(p.getDamage());
				std::cout << "The " << m.getName() << " has " << m.getHealth() << " health remaining.\n";
				std::cout << '\n';
			}

			if (p.isDead())
			{
				std::cout << "Too bad you can't take it with you!";
				std::cout << '\n';
				break;
			}
			else if (m.isDead())
			{
				std::cout << "You killed the " << m.getName() << ".\n";
				p.addGold(m.getGold());
				std::cout << "You found " << m.getGold() << " gold.\n";
				p.levelUp();
				std::cout << '\n';

				break;
			}

			if (playerDecision(m, p))
				continue;
			else
				break;
		}
	}
	else if (!(choice))
	{
		while (!(m.isDead() || p.isDead()))
		{
			std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
			m.reduceHealth(p.getDamage());
			std::cout << "The " << m.getName() << " has " << m.getHealth() << " health remaining.\n";

			if (m.isDead())
				std::cout << "You killed the " << m.getName() << ".\n";
			else
			{
				std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
				p.reduceHealth(m.getDamage());
				std::cout << "You have " << p.getHealth() << " health remaining.\n";
				std::cout << '\n';
			}

			if (p.isDead())
			{
				std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
				std::cout << "Too bad you can't take it with you!";
				std::cout << '\n';
				break;
			}
			else if (m.isDead())
			{
				p.addGold(m.getGold());
				std::cout << "You found " << m.getGold() << " gold.\n";
				p.levelUp();
				std::cout << '\n';

				break;
			}

			if (playerDecision(m, p))
			{
				continue;
			}
			else
				break;
		}
	}
}

bool GameLogic::playerDecision(Monster& m, Player& p)
{
	std::cout << "(R)un or (F)ight: ";
	char d{};
	while (true)
	{
		std::cin >> d;

		if (d == 'f')
		{
			Decide::fail = 0;
			return 1;
		}
		else if (d == 'r')
			return playerRun(m, p);
		else
		{
			std::cout << "Invalid input. Please try again: ";
			continue;
		}
	}
}

bool GameLogic::playerRun(Monster& m, Player& p)
{
	static std::mt19937 mt{ std::random_device{}() };
	static std::uniform_int_distribution escapeChance{ 0, 1 };

	if (escapeChance(mt) == 1)
	{
		std::cout << "You successfully fled.\n";
		std::cout << '\n';
		return 0;
	}
	else
	{
		Decide::fail = 1;
		std::cout << "You failed to flee.\n";
		return 1;
	}
}