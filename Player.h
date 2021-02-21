#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Map.h"

using std::string;

class Player
{
private:
	string name;
	int coin;
	int numOfCubes;
	int numOfDisks;
	int armyOnhand;

	list<Territory*> territories;
	list<Card*> cards;
	list<City*> cities;
	list<Army*> armies;


public:

	Player();
	Player(string name, int coinNum);
	Player(const Player&);
	~Player();

	void payCoin(int cost);
	void placeNewArmies(Territory* territory, int numberOfArmies);
	void moveArmies(Army*, Territory*);
	void moveOverLand(Army* army, Territory* endLocation);
	void buildCity(Territory* territory);
	void destroyArmy();
	string getName();
	void setName(string n);
	int getCoins();
	void setCoin(int c);
	list<Army*>* getArmies();
	Player& operator= (const Player&);
private:
	friend ostream& operator<<(ostream&, const Player&);

};

class Army
{
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

	// Operators.
private:
	friend ostream& operator<<(ostream&, const Army&);
};

class City
{
	Player* owner;
	Territory* position;
	// Public methods.
public:
	// Constructors and destructors.
	City();
	City(Player*, Territory*);
	City(const City&);
	~City();
	// Useful methods.
	string getOwnerName();
	Player* getOwner();
	Territory* getPosition();
	City& operator=(City&);

	// Operators.
private:
	friend ostream& operator<<(ostream&, const City&);
};
class Card {

};
#endif