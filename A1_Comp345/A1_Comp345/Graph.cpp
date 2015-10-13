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
			Node toBePushed(nameOfCountry, 0);
			Graph::contriesOnContinent.push_back(toBePushed);
		}
	}
	fin.close();


}
Graph::~Graph()
{

}
void Graph::InstantiateMapLinks()
{
	//now link the countries together
	
	for (int i = 0; i < Graph::contriesOnContinent.size(); i++)
	{
		//open file with boarder links
		std::ifstream boarders;
		boarders.open("boarders.txt");
		
		std::regex nameOfCountryRx("^" + Graph::contriesOnContinent.at(i).getCountryName() + "(.*)");
		while (!boarders.eof())
		{
			std::string lineInBoarderTxt;
			std::getline(boarders, lineInBoarderTxt);
			//check if its the current node name
			if (std::regex_match(lineInBoarderTxt, nameOfCountryRx))
			{
				std::size_t pos = lineInBoarderTxt.find(":");
				int first = (int)pos+1;
				lineInBoarderTxt = lineInBoarderTxt.substr(first, lineInBoarderTxt.length());
				std::istringstream ss(lineInBoarderTxt);
				std::string split;
				while (std::getline(ss, split, ',')) {
					for (int j = 0; j < Graph::contriesOnContinent.size(); j++)
					{
						if (Graph::contriesOnContinent.at(j).getCountryName() == split)
						{
							Node link = Graph::contriesOnContinent.at(j);
							Graph::contriesOnContinent.at(i).addBoarders(link);
						}
						else if (false)
						{
							//links that are not part of this continent
							Node link = Graph::contriesOnContinent.at(j);
							Graph::contriesOnContinent.at(i).addBoarders(link);
						}
					}
				}
				break;
			}

		}
		boarders.clear();
		boarders.close();

	}
	
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