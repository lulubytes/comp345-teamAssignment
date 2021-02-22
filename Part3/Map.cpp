#include "Map.h"
#include <iostream>
#include <iomanip>
#include <stack>
#include <typeinfo>

using namespace std;

Territory::Territory()
{
	name = "";
	id = 0;
	continentName = "";
	continentID = 0;
	player = "";
	armyNum = 0;
	connected = false;

}
Territory::Territory(string name, string continentName, int id, int continentID)
{
	this->name = name;
	this->id = id;
	this->continentName = continentName;
	this->continentID = continentID;
	this->armyNum = 0;
	this->connected = false;

}


Territory::Territory(string name, string continentName, int id, int continentID, bool connectedForeignContient, string player, bool buildCity, int armyNum) 
{
	this->name = name;
	this->continentName = continentName;
	this->id = id;
	this->continentID = continentID;
	this->connected = connectedForeignContient;
	this->player = player;
	this->armyNum = armyNum;
	this->buildCity = buildCity;
}

Territory::Territory(const Territory& other) 
{
	this->name = other.name;
	this->continentName = other.continentName;
	this->id = other.id;
	this->continentID = other.continentID;
	this->connected = other.connected;
	this->player = other.player;
	this->armyNum = other.armyNum;
	this->buildCity = other.buildCity;
}


Territory& Territory::operator = (const Territory& other) 
{
	this->name = other.name;
	this->continentName = other.continentName;
	this->id = other.id;
	this->continentID = other.continentID;
	this->connected = other.connected;
	this->player = other.player;
	this->armyNum = other.armyNum;
	this->buildCity = other.buildCity;
	return *this;
};

Territory::~Territory() 
{

}

string Territory::GetName() 
{ 
	return name; 
}

int Territory::GetID()
{ 
	return id; 
}

string Territory::GetContinentName() 
{
	return continentName; 
}

int Territory::GetContinentID() 
{ 
	return continentID; 
}

string Territory::GetPlayer() 
{ 
	return player; 
}

int Territory::GetArmyCount()
{ 
	return armyNum; 
}

bool Territory::GetConnected() 
{ 
	return connected; 
}

vector<int> Territory::GetNearTerritory() 
{ 
	return nearTerritory; 
}
vector<int> Territory::GetNearTerritorySameContinent() 
{ 
	return nearTerritorySameContinent; 
}

void Territory::SetTerritoryName(string name)
{
	name = name;
}

void Territory::SetTerritoryID(int id)
{
	id = id;
}

void Territory::SetConnected(bool canGoOut)
{
	connected = canGoOut;
}

void Territory::DisplayTerritorys(vector<int> v)
{
	if (v.size() != NULL) 
	{
		int len = v.size();
		for (int i = 0; i < len; i++) 
		{
			cout << " " << v[i];
		}
	}
	else 
	{
		cout << " no element ";
	}

}

bool Territory::GetBuildCity() 
{
	return buildCity;
}

void Territory::AddArmy(int armyNum) 
{
	this->armyNum += armyNum;
}

void Territory::SetBuildCity() 
{
	buildCity = true;
}

void Territory::SetPlayer(string player) 
{
	this->player = player;
}

ostream& operator<<(ostream& output, const Territory& other) 
{
	string temp;
	if (other.buildCity == 0) 
		temp = "No";
	else 
		temp = "Yes";
	
	output << "Territory Name: " << other.name << " Player: " << other.player << " Build City: " << temp << " Army: " << other.armyNum << endl;
	return output;
}


Continent::Continent()
{
	name = "";
	id = 0;
}

Continent::Continent(string name, int id)
{
	this->name = name;
	this->id = id;
}


Continent::Continent(const Continent& other) 
{
	this->name = other.name;
	this->id = other.id;
}

Continent& Continent::operator = (const Continent& other) 
{
	this->name = other.name;
	this->id = other.id;
	return *this;
}

Continent::~Continent() 
{

}

ostream& operator<<(ostream& output, const Continent& other) 
{
	output << "Continent name: " << other.name << "id: " << other.id << endl;
	return output;
}


string Continent::GetName() 
{ 
	return name; 
}
int Continent::GetID() 
{ 
	return id; 
}
vector<Territory*> Continent::GetTerritoryCount() 
{ 
	return territoryCount; 
}

bool Continent::CheckGraph()
{
	int len = this->territoryCount.size();
	vector<int> visited;

	for (int i = 0; i < len; i++) 
	{
		if (visited.empty()) 
		{
			visited.push_back(this->territoryCount[i]->GetID());
		}
		int len1 = this->territoryCount[i]->nearTerritorySameContinent.size();
		for (int j = 0; j < len1; j++) 
		{
			int temp = this->territoryCount[i]->nearTerritorySameContinent[j];
			int len2 = visited.size();
			for (int k = 0; k < len2; k++)
			{
				if (temp == visited[k])
				{
					break;
				}
				if (k == (len2 - 1)) 
				{
					if (temp != visited[k])
					{
						visited.push_back(temp);
					}
				}
			}
		}
	}
	if (visited.size() != len) 
	{
		return false;
	}
	return true;

}

set<int> Continent::GetReachableContinent() 
{
	return setReachableContinent; 
}


Map::Map()
{
	name = "";
	continentCount = 0;
	territoryCount = 0;

}

Map::Map(string name, int territoryCount, int continentCount)
{
	this->name = name;
	this->territoryCount = territoryCount;
	this->continentCount = continentCount;

}

Map::Map(const Map& other) 
{
	this->name = other.name;
	this->territoryCount = other.territoryCount;
	this->continentCount = other.continentCount;
	this->territorys = other.territorys;
	this->continents = other.continents;
}


Map& Map::operator = (const Map& other) 
{
	this->name = other.name;
	this->territoryCount = other.territoryCount;
	this->continentCount = other.continentCount;
	this->territorys = other.territorys;
	this->continents = other.continents;
	return *this;
}

Map::~Map() 
{}


ostream& operator<<(ostream& output, const Map& other) 
{
	return output << "Map:" << other.name << " num of territory: " << other.territoryCount << " num of continent: " << other.continentCount << endl;
}


string Map::GetName() 
{
	return name; 
}

int Map::GetTerritoryCount() 
{ 
	return territoryCount; 
}

int Map::GetContinentCount() 
{
	return continentCount; 
}

vector<Territory*> Map::GetTerritorys() 
{ 
	return territorys; 
}

void Map::SetName(string name)
{
	name = name;
}

void Map::DisplayTerritorys()
{
	cout << territorys.size() << endl;
}

void Map::DisplayAllContinent()
{
	cout << continents.size() << endl;
}


void Map::validate()
{
	int len = this->continents.size();
	set<int> visitedContinent;
	set<int>::const_iterator iter;
	for (int i = 0; i < len; i++) 
	{
		if (this->continents[i]->CheckGraph()) 
		{
			cout << "Map's Continent->" << this->continents[i]->GetName() << " is connected." << endl;
		}
		else 
		{
			cout << "Map's Continent->" << this->continents[i]->GetName() << " is disconnected." << endl;
			cout << "Map is invalid because at least one continent subgraph is not connected." << endl;
			break;
		}
	}
	for (int j = 0; j < len; j++) 
	{
		for (iter = this->continents[j]->setReachableContinent.begin(); iter != this->continents[j]->setReachableContinent.end(); ++iter) 
		{
			visitedContinent.insert(*iter);
		}
	}
	if (visitedContinent.size() != len) 
	{
		cout << "Map is invalid!" << endl;
	}
	else 
	{
		cout << "Map is valid, enjoy the game." << endl;
	}
}