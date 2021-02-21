
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Map.h"
#include "Bidding.h"

using std::string;


// Player class.
class Player
{
	// Local variables.
private:
	string name;
	int numOfCoins;
	int numOfCubes;
	int numOfDisks;
	bidding* bidFaci;
	list<Territory*> playerTerritory;

	// Public methods
public:
	// Constructors and destructors.
	Player();
	Player(string name, int coinNum);
	Player(const Player&);
	~Player();

	// Methods.
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
	//BiddingFacility* getBidFaci() const;
	Player& operator= (const Player&);

	// Operators
private:
	friend ostream& operator<<(ostream&, const Player&);

};

class Army
{
	// Local variables.
private:
	Player* owner;
	Territory* position;

	// Public methods.
public:
	// Constructors and destructors.
	Army();
	Army(Player*, Territory*);
	Army(const Army&);
	~Army();
	// Useful methods.
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


#endif
