#ifndef GAMELOGIC_H
#define GAMELOGIC_H

class GameLogic
{
public:
	static void startGame();

	static Player playerCreation();

	static void playerFight(bool choice, Monster& m, Player& p);

	static bool playerDecision(Monster& m, Player& p);

	static bool playerRun(Monster& m, Player& p);
};

#endif