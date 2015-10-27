#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
class Node
{
private:
	
	int numOfTroops;
	std::vector<Node*> boarders;
	
public:
	std::string countryName;
	//accessor and mutators
	Node(std::string name, int num);
	~Node();
	Node(const Node &obj);
	void setCountryName(std::string name);
	void setNumOfTroops(int number);
	void setBoarders(std::vector<Node*> continent);
	void addBoarders(Node* country);
	std::vector<Node*> getBoarders();
	std::string getCountryName();
	int getNumOfTroops();
};


#endif