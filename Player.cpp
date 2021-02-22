#include "Player.h"
#include <iostream>
using namespace std;


Player::Player()
{
	name = "Test Player";
	coin = 0;
	typedef list<string> terriotories;;
	typedef list<int> cards;
	typedef list<int> cities;;
	typedef list<int> armies;
	armyOnhand = 100;
	numOfCubes = 18;
	numOfDisks = 3;
}

// Player value constructor.
Player::Player(string Name, int Coin)
{
	name = Name;
	coin = Coin;
	typedef list<int> terriotories;;
	typedef list<int> cards;
	typedef list<int> cities;;
	typedef list<int> armies;
	armyOnhand = 100;
	numOfCubes = 18;
	numOfDisks = 3;
}

// Player copy constructor.
Player::Player(const Player& anotherPlayer)
{
	name = anotherPlayer.name;
	coin = anotherPlayer.coin;

	for (Territory* territory : anotherPlayer.territories)
	{
		territories.push_back(territory);
	}


	for (Army* army : anotherPlayer.armies)
	{
		armies.push_back(new Army(*army));
	}
	armyOnhand = anotherPlayer.armyOnhand;
	numOfCubes = anotherPlayer.numOfCubes;
	numOfDisks = anotherPlayer.numOfDisks;
}

// Player destructor.
Player::~Player()
{
	territories.clear();
	cards.clear();
	cities.clear();
	armies.clear();
	armyOnhand = 0;
	numOfCubes = 0;
	numOfDisks = 0;
}

// Switched Pay coin into a boolean type 
// Pay coin.
void Player::payCoin(int cost)
{
	if (this->coin >= cost)
	{
		coin = coin - cost;
		cout << this->name << " has now paied " << cost << ", and left" << this->coin << "coins." << endl;
	}
	else
	{
		cout << this->name + " doesn't have enough coins " << endl;
	}
}

// Creates new army.
void Player::placeNewArmies(Territory* territory, int numberOfArmies)
{
	if (this->armyOnhand > numberOfArmies)
	{
		territory->AddArmy();
		territory->numOfArmies = territory->numOfArmies + numberOfArmies;
		cout << "Created " << numberOfArmies << " in " << territory << endl;
		armyOnhand = armyOnhand - numberOfArmies;
		numOfCubes--;
	}
	else {
		cout << this->name << "only has " << this->armyOnhand << " armies left " << endl;
	}

}

// Moves army. Should work for both land and water.
void Player::moveArmies(Army* army, Territory* endLocation)
{
	Territory* oldPos = army->getPosition();
	oldPos->RemoveArmy();
	army->setPosition(endLocation);
	endLocation->AddArmy();
	cout << "Moved " << *army << " from " << oldPos->countryName << " to " << endLocation << endl;
	oldPos = nullptr;
}

void Player::moveOverLand(Army* army, Territory* endLocation)
{
	Territory* oldPos = army->getPosition();
	cout << "Moved " << *army << " overland from " << oldPos->countryName << " to " << endLocation << endl;
	oldPos = nullptr;

}

void Player::buildCity(Territory* territory)
{
	if (numOfDisks <= 0)
	{
		cout << name << " does not have enough disks to place a new city." << endl;
		return;
	}
	City* city = new City(this, territory);
	this->cities.push_back(city);
	cout << *city << " is built in " << territory;
	city = nullptr;
	numOfDisks--;
}


void Player::destroyArmy()
{
	armies.clear();
	armyOnhand = 0;
}


string Player::getName()
{
	return name;
}

void Player::setName(string n) {
	name = n;
}

int Player::getCoins() {
	return this->coin;
}

void Player::setCoin(int c) {
	this->coin = c;
}




ostream& operator<<(ostream& strm, const Player& player)
{
	return strm << player.name << ": " << player.coin << " coins";
}

Player& Player::operator= (const Player& anotherPlayer)
{
	if (&anotherPlayer == this)
		return *this;

	name = anotherPlayer.name;
	coin = anotherPlayer.coin;


	for (Territory* territory : anotherPlayer.territories)
	{
		territories.push_back(territory);
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

	return *this;
}

// ============================================
// Army Implementation
// ============================================

// Default constructor.
Army::Army()
{
	owner = nullptr;
	position = nullptr;
}

// Army constructor.
Army::Army(Player* anOwner, Territory* aPosition)
{
	owner = anOwner;
	position = aPosition;
}

// Copy constructor.
Army::Army(const Army& anotherArmy)
{
	// Shallow copies because the owner and position will the same.
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

// Army destructor.
Army::~Army()
{
	// Doesn't make sense to delete them because owner/position will exist even after an army is deleted.
	owner = nullptr;
	position = nullptr;
}

// Returns owner name.
string Army::getOwnerName()
{
	return (*owner).getName();
}

// Returns pointer to owner.
Player* Army::getOwner()
{
	return owner;
}

// Returns pointer to current position.
Territory* Army::getPosition()
{
	return position;
}

// Changes position.
void Army::setPosition(Territory* newPosition)
{
	position = newPosition;
}

// Army's toString
ostream& operator<<(ostream& strm, const Army& army)
{
	return strm << army.owner->getName() << "'s army";
}

// Assignment operator overload.
Army& Army::operator=(Army& anotherArmy)
{
	if (&anotherArmy == this)
		return *this;

	// Shallow copies because the owner and position will the same.
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

// ============================================
// City Implementation
// ============================================

// Default constructor.
City::City()
{
	owner = nullptr;
	position = nullptr;
}

// City constructor.
City::City(Player* anOwner, Territory* aPosition)
{
	owner = anOwner;
	position = aPosition;
}

City::City(const City& anotherCity)
{
	// Shallow copies because the owner and position will the same.
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

// City destructor.
City::~City()
{
	// Doesn't make sense to delete them because owner/position will exist even after an army is deleted.
	owner = nullptr;
	position = nullptr;
}

// Returns owner name.
string City::getOwnerName()
{
	return owner->getName();
}

// Returns pointer to owner.
Player* City::getOwner()
{
	return owner;
}

// Returns pointer to current position.
Territory* City::getPosition()
{
	return position;
}

// City's toString
ostream& operator<<(ostream& strm, const City& city)
{
	return strm << city.owner->getName() << "'s city";
}

// Assignment operator overload.
City& City::operator=(City& anotherCity)
{
	if (&anotherCity == this)
		return *this;

	// Shallow copies because the owner and position will the same.
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
