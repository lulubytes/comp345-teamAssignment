
#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Map.h"
#include "BiddingFacility.h"
#include "Card.h"
#include "Biding.h"
using namespace std;
using std::string;

class Player {
    
    private:
	string name;
	int numOfCoins;
	int numOfCubes;
	int numOfDisks;
	BiddingFacility* bidFaci;
	list<Territory*> playerTerritory;
	list<Card*> playerHand;
	list<City*> cities;
	list<Army*> armies;

public:
    Player();
	Player(string name, int coinNum);
	Player(const Player&);
	~Player();
    Map map;
    Card card;
    Biding biding;
	bool payCoin(int& cost);
	void placeNewArmies(Territory* territory);
	void moveArmies(Army*, Territory*);
	void moveOverLand(Army*, Territory*);
	void buildCity(Territory* territory);
	void destroyArmy(Army*);
	string getName();
	void setName(string n);
	int getCoins();
	void setCoins(int c);
	BiddingFacility* getBidFaci() const;
	list<Army*>* getArmies();
    
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
	// Useful methods.
	string getOwnerName();
	Player* getOwner();
	Territory* getPosition();
	City& operator=(City&);

    };
};
#endif
