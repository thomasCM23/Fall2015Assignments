#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class Player
{
	enum Color { red, green, blue, black, yellow, orange };
	int totalArmySize;

public:
	Player();
	~Player();
};

#endif