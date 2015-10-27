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
	std::cout << "Setting up map..." << endl;
	for (int i = 0; i < this->world.size(); i++)
	{
		std::cout << "-------------" << endl;
		std::cout << this->world.at(i).getContinentName() << endl;
		std::cout << endl;
		Graph *Continent = &this->world.at(i);
		for (int j = 0; j < Continent->getContinent().size(); j++)
		{
			ifstream boarders;
			boarders.open("boarders.txt");
			std::cout << (Continent->getContinent().at(j)->getCountryName())<<":  ";

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
								std::cout << split << ", ";
								break;
							}
							else
							{
								//looking through other continents to find the node
								Node* prt = this->searchForCountry(split);
								if (prt != nullptr)
								{
									std::cout << split << ", ";
									Continent->getContinent().at(j)->addBoarders(prt);
									break;
								}
							}
						}
					}
				}
			}
			boarders.close();
			std::cout << endl;
		}
		std::cout << "-------------" << endl;
	}

	std::cout << "Set up done!" << endl;
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
RiskMap::~RiskMap()
{

}
bool RiskMap::isCountryAdjacent(Node* country1, Node* country2)
{
	for (int i = 0; i < country1->getBoarders().size(); i++)
	{
		if (country2->countryName == country1->getBoarders().at(i)->countryName)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
vector<Node*> RiskMap::getAllAdjacentContries(Node* country)
{
	return country->getBoarders();
}