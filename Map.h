#ifndef MAP_H
#define MAP_H
#include <map>
#include <iostream>
#include <string>
#include <list>
#pragma once
using namespace std;

//declaration to make compiler happy.
class Territory;

class Territory
{
private:
    std::string *countryName;
    std::string *player;
	int *numOfArmies;
	
	
public:
	Territory();// default constructor
	Territory(std::string, std::string, int);// normal constructor.
	Territory(const Territory&);//copy constructor
	Territory& operator=(const Territory& );//assignment operator
	~Territory();//destructor
    std::string GetCountryName() const;
    std::string GetPlayer() const;
    int GetNumOfArmies() const;
	void RemoveArmy();
	void AddArmy();
	
};

struct Map {
	std::map<Territory*, std::map<Territory*, int>> allTerritory;
	std::list<std::list<Territory*>> allContinent;
	std::map<std::string, Territory*> territories;

public:
	Map();
	Map(const Map*); // copy constructor
	Map& operator = (const Map&); // assignement operator
	~Map(); // destrutor
	void addEdge(Territory*, Territory*, int);
	void pushContinent(std::list<Territory*>&);
	Territory* GetTerritory(std::string);
	bool validate();
	void show();
private:
	bool checkMapConnected();
	void traverse(Territory* node, std::map<Territory*,bool>* visitedList);
	bool checkContinentConnected(std::list<Territory*>*);
	// void traverse2(Territory* node, std::map<Territory*, bool>* visitedList);
	bool toOneContinent();
};

#endif