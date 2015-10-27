#include "Node.h"
//implementation of Node.h
//defines a county in the risk game
//the name, number of troops on the node
//the list of countries it is ajacent to
Node::Node(std::string name, int num, Player * owner)
{
	this->countryName = name;
	this->numOfTroops = num;
	this->owner = owner;
}
Node::~Node()
{
}
void Node::addBoarders(Node* T)
{
	this->boarders.push_back(T);
}
Node::Node(const Node &obj)
{

}
void Node::setBoarders(std::vector<Node*> T)
{
	this->boarders = T;
}
void Node::setCountryName(std::string name)
{
	this->countryName = name;
}
void Node::setNumOfTroops(int num)
{
	this->numOfTroops = num;
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
