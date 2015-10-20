#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include "Node.h"
class Graph
{
private:
	std::vector<Node*> contriesOnContinent;
	std::string continentName;
public:
	Graph(std::string name);
	~Graph();
	std::vector<Node*> getContinent();
	void setContinent(std::vector<Node*> listOfCountries);
	void addCountryToContinent(Node* newContry);
	Node* getInfoAboutCountryByIndex(int index);
	void setContinentName(std::string name);
	std::string getContinentName();
	void InstantiateMapLinks();
};

#endif