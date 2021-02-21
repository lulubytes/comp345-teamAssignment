#include "Player.h"

#include <iostream>
#include "Cards/Cards.h"
#include "BiddingFacility.h"
using namespace std;


void Player::PayCoin() {
    if(){
        
    }
    else{
        
    }
    cout << "This is PayCoin" << endl;
}

void Player::PlaceNewArmies() {
    cout << "This is PlaceNewArmies" << endl;
}

void Player::MoveArmies() {
    cout << "This is MoveArmies" << endl;
}

void Player::MoveOverLand() {
    cout << "This is MoveOverLand" << endl;
}

void Player::BuildCity() {
    cout << "This is BuildCity" << endl;
}
void Player::DestroyArmy() {
    cout << "This is DestroyArmy" << endl;
}

//constructor
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


