#include "Player.h"
#include"map.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;


Player::Player()
{
	name = "Test Player";
	numOfCoins = 0;
	playerTerritory = list<Territory*>();
	typedef list<int> cities;
	typedef list<int> armies;
	numOfCubes = 18;
	numOfDisks = 3;
}

Player::Player(string aName, int coinNum)
{
	name = aName;
	numOfCoins = coinNum;
	playerTerritory = list<Territory*>();
	typedef list<int> cities;
	typedef list<int> armies;
	numOfCubes = 18;
	numOfDisks = 3;
}

Player::Player(const Player& anotherPlayer)
{
	name = anotherPlayer.name;
	numOfCoins = anotherPlayer.numOfCoins;

	for (Territory* territory : anotherPlayer.playerTerritory)
	{
		playerTerritory.push_back(territory);
	}


	for (City* city : anotherPlayer.cities)
	{
		cities.push_back(new City(*city));
	}

	for (Army* army : anotherPlayer.armies)
	{
		armies.push_back(new Army(*army));
	}

	numOfCubes = anotherPlayer.numOfCubes;
	numOfDisks = anotherPlayer.numOfDisks;
}

Player::~Player()
{
	name = nullptr;
	numOfCoins = 0;
	//bidFaci = new bidding(4);
	playerTerritory = list<Territory*>();
	cities.clear();
	armies.clear();
	numOfCubes = 0;
	numOfDisks = 0;
}

// Switched Pay coin into a boolean type 
// Pay coin.
void Player::payCoin(int cost)
{
	if (this->numOfCoins >= cost)
	{
		numOfCoins = numOfCoins - cost;
		cout << this->name << "now owns" << this->numOfCoins << endl;

	}
	else
	{
		cout << this->name + " doesn't have enough coins to pay" << endl;
	}
}

// Creates new army.
void Player::placeNewArmies()
{

}

// Moves army. Should work for both land and water.
void Player::moveArmies()
{

}

// Moves army over land.
void Player::moveOverLand()
{
	
}

// Creates a city on the territory. Is not currently functional because we have no idea of what a city is.
void Player::buildCity(Territory* territory)
{
	if (numOfDisks <= 0)
	{
		cout << name << " does not have enough disks to place a new city." << endl;
		return;
	}
	numOfDisks--;
}

// Destroys army and deallocates dynamic memory.
void Player::destroyArmy()
{
	armies.clear();
	cout <<" army is destroyed!";
}

// Returns player name.
string Player::getName()
{
	return name;
}

void Player::setName(string n) {
	name = n;
}

int Player::getCoin() {
	return numOfCoins;
}

void Player::setCoin(int c) {
	numOfCoins = c;
}

ostream& operator<<(ostream& strm, const Player& player)
{
	return strm << player.name << ": " << player.numOfCoins << " coins";
}

Player& Player::operator= (const Player& anotherPlayer)
{
	if (&anotherPlayer == this)
		return *this;

	name = anotherPlayer.name;
	numOfCoins = anotherPlayer.numOfCoins;

	for (City* city : anotherPlayer.cities)
	{
		cities.push_back(new City(*city));
	}

	for (Army* army : anotherPlayer.armies)
	{
		armies.push_back(new Army(*army));
	}

	numOfCubes = anotherPlayer.numOfCubes;
	numOfDisks = anotherPlayer.numOfDisks;

	return *this;
}


Army::Army()
{
	owner = nullptr;
	position = nullptr;
}


Army::Army(Player* anOwner, Territory* aPosition)
{
	owner = anOwner;
	position = aPosition;
}

Army::Army(const Army& anotherArmy)
{

	if (anotherArmy.owner)
	{
		owner = anotherArmy.owner;
	}
	else
	{
		owner = nullptr;
	}

	if (anotherArmy.position)
	{
		position = anotherArmy.position;
	}
	else
	{
		position = nullptr;
	}
}


Army::~Army()
{

	owner = nullptr;
	position = nullptr;
}


string Army::getOwnerName()
{
	return (*owner).getName();
}


Player* Army::getOwner()
{
	return owner;
}


Territory* Army::getPosition()
{
	return position;
}


void Army::setPosition(Territory* newPosition)
{
	position = newPosition;
}


ostream& operator<<(ostream& strm, const Army& army)
{
	return strm << army.owner->getName() << "'s army";
}


Army& Army::operator=(Army& anotherArmy)
{
	if (&anotherArmy == this)
		return *this;


	if (anotherArmy.owner)
	{
		owner = anotherArmy.owner;
	}
	else
	{
		owner = nullptr;
	}

	if (anotherArmy.position)
	{
		position = anotherArmy.position;
	}
	else
	{
		position = nullptr;
	}

	return *this;
}


City::City()
{
	owner = nullptr;
	position = nullptr;
}


City::City(Player* anOwner, Territory* aPosition)
{
	owner = anOwner;
	position = aPosition;
}

City::City(const City& anotherCity)
{

	if (anotherCity.owner)
	{
		owner = anotherCity.owner;
	}
	else
	{
		owner = nullptr;
	}

	if (anotherCity.position)
	{
		position = anotherCity.position;
	}
	else
	{
		position = nullptr;
	}
}


City::~City()
{

	owner = nullptr;
	position = nullptr;
}


string City::getOwnerName()
{
	return owner->getName();
}

Player* City::getOwner()
{
	return owner;
}


Territory* City::getPosition()
{
	return position;
}


ostream& operator<<(ostream& strm, const City& city)
{
	return strm << city.owner->getName() << "'s city";
}


City& City::operator=(City& anotherCity)
{
	if (&anotherCity == this)
		return *this;

	if (anotherCity.owner)
	{
		owner = anotherCity.owner;
	}
	else
	{
		owner = nullptr;
	}

	if (anotherCity.position)
	{
		position = anotherCity.position;
	}
	else
	{
		position = nullptr;
	}

	return *this;
}


