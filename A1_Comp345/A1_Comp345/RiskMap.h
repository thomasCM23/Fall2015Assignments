#ifndef RISKMAP_H
#define RISKMAP_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
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
};

#endif