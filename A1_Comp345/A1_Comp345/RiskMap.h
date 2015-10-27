#ifndef RISKMAP_H
#define RISKMAP_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include "Node.h"
#include "Graph.h"
using namespace std;
class RiskMap
{
private:
	vector<Graph> world;
public:
	RiskMap();
	~RiskMap();
	void addContinent(Graph T);
	void loadContinentsFromFile();
	vector<Graph> getWorld();
	vector<Node> getContinentbyIndex(int index);
	Node* searchForCountry(string name);
	bool isCountryAdjacent(Node* country1, Node* country2);
	vector<Node*> getAllAdjacentContries(Node* country);
protected:
	void instantiateMapLinks();
};

#endif