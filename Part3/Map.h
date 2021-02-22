#pragma once

#include <string>
#include <vector>
#include <set>
using namespace std;

class Territory
{
private:
	string name;
	int id;
	string continentName;
	int continentID;
	string player;
	int armyNum;
	bool connected;
	bool buildCity;

public:
	vector<int> nearTerritory;
	vector<int> nearTerritorySameContinent;

	Territory();
	~Territory();
	Territory(string name, string continentName, int id, int continentID);
	Territory(string name, string continentName, int id, int continentID, bool connectedForeignContient, string player, bool buildCity, int armyNum);
	Territory(const Territory& other);

	Territory& operator = (const Territory& other);

	string GetName();
	int GetID();
	string GetContinentName();
	int GetContinentID();
	string GetPlayer();
	int GetArmyCount();
	bool GetConnected();
	void SetConnected(bool canGoOut);
	vector<int> GetNearTerritory();
	vector<int> GetNearTerritorySameContinent();
	void SetTerritoryName(string name);
	void SetTerritoryID(int id);
	void DisplayTerritorys(vector<int> v);
	bool GetBuildCity();
	void SetBuildCity();
	void AddArmy(int armyNum);
	void SetPlayer(string player);
	friend ostream& operator<<(ostream& output, const Territory& other);

};

class Continent
{
public:
	string name;
	int id;
	vector<Territory*> territoryCount;
	set<int> setReachableContinent;

	Continent();
	~Continent();
	Continent(string name, int id);
	Continent(const Continent& other);
	Continent& operator = (const Continent&);
	friend ostream& operator<<(ostream& output, const Continent& other);

	string GetName();
	int GetID();
	vector<Territory*> GetTerritoryCount();
	bool CheckGraph();
	set<int> GetReachableContinent();
};

class Map
{
public:
	string name;
	int territoryCount;
	int continentCount;
	vector<Territory*> territorys;
	vector<Continent*> continents;

	Map();
	~Map();
	Map(string name, int territoryCount, int continentCount);
	Map(const Map& other);
	Map& operator = (const Map&);

	friend ostream& operator<<(ostream& output, const Map& other);

	string GetName();
	void SetName(string name);

	int GetTerritoryCount();
	int GetContinentCount();

	vector<Territory*> GetTerritorys();

	void DisplayTerritorys();
	void DisplayAllContinent();

	void validate();

};