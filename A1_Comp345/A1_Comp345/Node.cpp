#include "Node.h"
//implementation of Node.h
//defines a county in the risk game
//the name, number of troops on the node
//the list of countries it is ajacent to
Node::Node(std::string name, int num)
{
	Node::countryName = name;
	Node::numOfTroops = num;
	//read file of boarders

}
Node::~Node()
{

}
void Node::addBoarders(Node* T)
{
	this->boarders.push_back(T);
}
void Node::setBoarders(std::vector<Node*> T)
{
	this->boarders = T;
}
void Node::setCountryName(std::string name)
{
	Node::countryName = name;
}
void Node::setNumOfTroops(int num)
{
	Node::numOfTroops = num;
}
int Node::getNumOfTroops()
{
	return numOfTroops;
}
std::string Node::getCountryName()
{
	return this->countryName;
}
std::vector<Node*> Node::getBoarders()
{
	return this->boarders;
}
