#include "Player.h"

#include <iostream>
#include "Cards/Cards.h"
#include "BiddingFacility.h"
using namespace std;

Player::Player() {
	                name = "Player1";
	                numOfCoins = 0;
	                bidFaci = new BiddingFacility();
	                playerTerritory = list<Territory*>();
	                playerHand = list<Card*>();
                	cities = list<City*>();
	                armies = list<Army*>();
	                numOfCubes = 18;
	                numOfDisks = 3;
                    }

Player::Player(string Name, int Coinnum) {
    
	                                        name = Name;
	                                        numOfCoins = Coinnum;
	                                        bidFaci = new BiddingFacility();
                                        	playerTerritory = list<Territory*>();
                                        	playerHand = list<Card*>();
                                          	cities = list<City*>();
                                        	armies = list<Army*>();
	                                        numOfCubes = 18;
	                                        numOfDisks = 3;
}

Player::Player(const Player& anotherPlayer)
{
	name = anotherPlayer.name;
	numOfCoins = anotherPlayer.numOfCoins;

	if (anotherPlayer.bidFaci)
		bidFaci = new BiddingFacility(*(anotherPlayer.bidFaci));
	else
		bidFaci = nullptr;

	// Shallow copy because the map is the same.
	for (Territory* territory : anotherPlayer.playerTerritory)
	{
		playerTerritory.push_back(territory);
	}

	for (Card* card : anotherPlayer.playerHand)
	{
		playerHand.push_back(new Card(*card));
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
void Player::PayCoin(int& cost) {
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

void Player::placeNewArmies(Territory* territory)
{
	if (numOfCubes <= 0)
	{
		cout << name << " does not have enough cubes to place a new army." << endl;
		return;
	}
	else{
	Army* army = new Army(this, territory);
	territory->addArmy(army);
	armies.push_back(army);
	cout << this->name<< "created " << *army << " in " << territory->getName() << endl;
	army = nullptr;
	numOfCubes--
	}
}
void Player::moveArmies(Army* army, Territory* endLocation)
{
	Territory* oldPos = army->getPosition();
	oldPos->removeArmy(army);
	army->setPosition(endLocation);
	endLocation->addArmy(army);
	cout << this->name<< "moves his " << *army << " from " << oldPos->getName() << " to " << endLocation->getName() << endl;
	oldPos = nullptr;
}

void Player::moveOverLand(Army* army, Territory* endLocation)
{
	Territory* oldPos = army->getPosition();
	oldPos->removeArmy(army);
	army->setPosition(endLocation);
	endLocation->addArmy(army);
	cout << this->name<< "moves his " << *army << " overland from " << oldPos->getName() << " to " << endLocation->getName() << endl;
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
	cout << *city << " is built in " << territory->getName();
	city = nullptr;
	numOfDisks--;
}
void Player::destroyArmy(Army* army)
{
	army->getPosition()->removeArmy(army);
	army->getOwner()->armies.remove(army);
	cout << *army << " is destroyed!";
	delete army;
	army = nullptr;
}

string Player::getName()
{
	return name;
}

void Player::setName(string n) {
	name = n;
}

int Player::getCoins() {
	return numOfCoins;
}

void Player::setCoins(int c) {
	numOfCoins = c;
}

BiddingFacility* Player::getBidFaci() const { 
	return bidFaci;
}

list<Army*>* Player::getArmies()
{
	return &armies;
}

// toString
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

	if (anotherPlayer.bidFaci)
		bidFaci = new BiddingFacility(*(anotherPlayer.bidFaci));
	else
		bidFaci = nullptr;

	for (Territory* territory : anotherPlayer.playerTerritory)
	{
		playerTerritory.push_back(territory);
	}

	for (Card* card : anotherPlayer.playerHand)
	{
		playerHand.push_back(new Card(*card));
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



