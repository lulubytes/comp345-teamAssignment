
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Map.h"
#include "Bidding.h"

using std::string;



class Player
{

private:
	string name;
	int numOfCoins;
	int numOfCubes;
	int numOfDisks;
	bidding* bidFaci;
	list<Territory*> playerTerritory;

public:
	
	Player();
	Player(string name, int coinNum);
	Player(const Player&);
	~Player();

	
	void payCoin(int cost);
	void placeNewArmies();
	void moveArmies();
	void moveOverLand();
	void buildCity(Territory* territory);
	void destroyArmy();
	string getName();
	void setName(string n);
	int getCoin();
	void setCoin(int c);

	Player& operator= (const Player&);


private:
	friend ostream& operator<<(ostream&, const Player&);

};

class Army
{
	.
private:
	Player* owner;
	Territory* position;

public:

	Army();
	Army(Player*, Territory*);
	Army(const Army&);
	~Army();

	string getOwnerName();
	Player* getOwner();
	Territory* getPosition();
	void setPosition(Territory*);
	Army& operator=(Army&);

private:
	friend ostream& operator<<(ostream&, const Army&);
};

class City
{
	Player* owner;
	Territory* position;

public:

	City();
	City(Player*, Territory*);
	City(const City&);
	~City();

	string getOwnerName();
	Player* getOwner();
	Territory* getPosition();
	City& operator=(City&);

private:
	friend ostream& operator<<(ostream&, const City&);
};


#endif
