#include "Node.h"
//implementation of Node.h
//defines a county in the risk game
//the name, number of troops on the node
//the list of countries it is ajacent to
Node::Node()
{

}
Node::~Node()
{

}
void Node::addBoarders(Node T)
{
	Node::boarders.push_back(T);
}
void Node::setBoarders(std::vector<Node> T)
{
	Node::boarders = T;
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
	return countryName;
}
std::vector<Node> Node::getBoarders()
{
	return boarders;
}
