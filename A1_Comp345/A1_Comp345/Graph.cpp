#include "Graph.h"

Graph::Graph()
{

}
Graph::~Graph()
{

}
void Graph::setContinent(std::vector<Node> listOfContries)
{
	contriesOnContinent = listOfContries;
}
std::vector<Node> Graph::getContinent()
{
	return contriesOnContinent;
}
void Graph::addCountryToContinent(Node newCountry)
{
	contriesOnContinent.push_back(newCountry);
}
Node Graph::getInfoAboutCountryByIndex(int index)
{
	return contriesOnContinent.at(index);
}
void Graph::setContinentName(std::string name)
{
	continentName = name;
}
std::string Graph::getContinentName()
{
	return continentName;
}