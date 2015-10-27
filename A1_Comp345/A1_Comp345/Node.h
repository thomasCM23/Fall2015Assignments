#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include "Player.h"
class Node
{
private:
	
	int numOfTroops;
	std::vector<Node*> boarders;
	Player * owner;
public:
	std::string countryName;
	//accessor and mutators
	Node(std::string name, int num, Player * owner);
	~Node();
	Node(const Node &obj);
	void setCountryName(std::string name);
	void setNumOfTroops(int number);
	void setBoarders(std::vector<Node*> continent);
	void addBoarders(Node* country);
	std::vector<Node*> getBoarders();
	std::string getCountryName();
	int getNumOfTroops();
	Player * getOwner();
	void setOwner(Player *owner);
};


#endif