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
	RiskMap::instantiateMapLinks();
	/*for (int i = 0; i < RiskMap::world.size(); i++)
	{
		RiskMap::world.at(i).InstantiateMapLinks();
	}*/
}
void RiskMap::instantiateMapLinks()
{
	for (int i = 0; i < this->world.size(); i++)
	{
		cout << "-------------" << endl;
		cout << this->world.at(i).getContinentName() << endl;
		cout << endl;
		Graph *Continent = &this->world.at(i);
		for (int j = 0; j < Continent->getContinent().size(); j++)
		{
			ifstream boarders;
			boarders.open("boarders.txt");
			cout << (Continent->getContinent().at(j)->getCountryName())<<":  ";

			regex nameOfCountryRx("^" + (Continent->getContinent().at(j)->countryName) + "(.*)");
			while (!boarders.eof())
			{
				string lineInBoarderTxt;
				getline(boarders, lineInBoarderTxt);
				if (regex_match(lineInBoarderTxt, nameOfCountryRx))
				{
					size_t pos = lineInBoarderTxt.find(":");
					int first = (int)pos + 1;
					lineInBoarderTxt = lineInBoarderTxt.substr(first, lineInBoarderTxt.length());
					istringstream ss(lineInBoarderTxt);
					string split;
					while (std::getline(ss, split, ',')) 
					{
						for (int k = 0; k < Continent->getContinent().size(); k++)
						{
							if (Continent->getContinent().at(k)->countryName == split)
							{
								Continent->getContinent().at(j)->addBoarders(Continent->getContinent().at(k));
								cout << split << ", ";
								break;
							}
							else
							{
								//looking through other continents to find the node
								Node* prt = this->searchForCountry(split);
								if (prt != nullptr)
								{
									cout << split << ", ";
									Continent->getContinent().at(j)->addBoarders(prt);
									break;
								}
							}
						}
					}
				}
			}
			cout << endl;
		}
		cout << "-------------" << endl;
	}
}
Node* RiskMap::searchForCountry(string name)
{
	Node* retVal;
	retVal = nullptr;
	for (int i = 0; i < this->world.size(); i++)
	{
		Graph *Continent = &this->world.at(i);
		for (int j = 0; j < Continent->getContinent().size(); j++)
		{
			if (Continent->getContinent().at(j)->countryName == name)
			{
				return Continent->getContinent().at(j);
			}
		}
	}
	return retVal;
}