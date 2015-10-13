#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
class Node
{
private:
	std::string countryName;
	int numOfTroops;
	std::vector<Node> boarders;
public:
	//accessor and mutators
	Node(std::string name, int num);
	~Node();
	void setCountryName(std::string name);
	void setNumOfTroops(int number);
	void setBoarders(std::vector<Node> continent);
	void addBoarders(Node country);
	std::vector<Node> getBoarders();
	std::string getCountryName();
	int getNumOfTroops();
};


#endif