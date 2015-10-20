#include "RiskMap.h"

RiskMap::RiskMap()
{
	//read file of continents
	ifstream fin;
	fin.open("Continents.txt");
	if (fin.is_open()){
		string temp;
		while (getline(fin, temp))
		{
			Graph pushedInRiskGraph(temp);
			RiskMap::world.push_back(pushedInRiskGraph);
		}
	}
	fin.close();
	for (int i = 0; i < RiskMap::world.size(); i++)
	{
		RiskMap::world.at(i).InstantiateMapLinks();
	}
}
bool RiskMap::searchForCountry(string name)
{
	for (int i = 0; i < RiskMap::world.size(); i++)
	{
		vector<Node*> ContriesOnContinent = RiskMap::world.at(i).getContinent();
		for (int j = 0; j < ContriesOnContinent.size(); j++)
		{
			if (ContriesOnContinent.at(j)->getCountryName() == name)
			{
				return true;
			}
		}
	}


	return false;
}