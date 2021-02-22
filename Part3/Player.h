#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Map.h"
#include "Cards.h"
#include "bidding.h"

using namespace std;
class Player 
{

public:
	Player();
	~Player();
	Player(string name, int coin, int move, vector<Territory*> territory, vector<Cards*> handCard, bidding* bid);
	Player(const Player& other);
	Player& operator = (const Player& other);

	void PayCoin(int coin);
	void PlaceNewArmies(Territory* territory, int army);
	void MoveArmies(Territory* pointA, Territory* pointB, int army);
	void MoveOverLand(Territory* pointA, Territory* pointB, int army);
	void BuildCity(Territory* territory);
	void DestroyArmy(Territory* territory, int army);

	string GetName();
	int GetMove();
	void SetMove(int move);
	int GetCoin();
	void SetCoin(int coin);
	vector<Territory*> GetTerritorys();
	vector<Cards*> GetHandCard();
	void SetHandCard(Cards* other);

	void AddArmy(int army);

	bool CheckTerritory(Territory* other);
	void DisplayTerritory();

	friend ostream& operator<<(ostream& output, const Player& other);

private:
	string name;
	int coin;
	int move;
	int army;
	int city;
	vector<Territory*> territory;
	vector<Cards*> handCard;
	bidding* bid;

};