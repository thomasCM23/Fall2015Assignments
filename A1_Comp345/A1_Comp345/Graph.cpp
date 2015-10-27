#include "Graph.h"

Graph::Graph(std::string name)
{

	//read file of countries
	Graph::continentName = name;
	std::ifstream fin;
	fin.open(name + ".txt");
	std::string nameOfCountry;
	if (fin.is_open())
	{
		while (std::getline(fin, nameOfCountry))
		{
			Node *toBePushed;
			Player * forNow = new Player();
			toBePushed = new Node(nameOfCountry, 0, forNow);
			this->contriesOnContinent.push_back(toBePushed);
		}
	}
	fin.close();
}
Graph::~Graph()
{

}
void Graph::setContinent(std::vector<Node*> listOfContries)
{
	contriesOnContinent = listOfContries;
}
std::vector<Node*> Graph::getContinent()
{
	return this->contriesOnContinent;
}
void Graph::addCountryToContinent(Node* newCountry)
{
	this->contriesOnContinent.push_back(newCountry);
}
Node* Graph::getInfoAboutCountryByIndex(int index)
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