#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

//card
class Card
{
public:
	//constructor
	string good;
	string action[2];
	string ability;
	string andor;

	Card();

	~Card();
	//copy constructor
	Card(const Card& c);
	Card(string good, string action, string andor, string ability);
	Card(string good, string firstAction, string secondAction, string andor, string ability);
	
	Card& operator = (const Card& c);
	
	string getGood();
	string getAction1();
	string getAction2();
	string getAbility();

	void printCard();

	friend ostream& operator<<(ostream&, const Card&);
};

//deck
class Deck {
public:

	//Constructor
	Deck();//Default
	Deck(int numPlayer);
	//Copy constructor
	Deck(const Deck& d);
	//Deconstructor
	~Deck();
	void generateDeck();
	void printDeck();
	void shuffleDeck();
	Card* draw();
	Deck& operator=(const Deck&);

	static int  myRandomGenerator(int j);
	int getNumCards();

private:
	Card* topCard;
	Card cards[34];
	int number;

	friend ostream& operator<<(ostream&, const Deck&);
};

//hand
class Hand {
private:
	Deck* deck;
	Card* cards[6];
public:
	Hand() = default;
	Hand(Deck* deck);
	Hand(const Hand& h);
	~Hand();
	int getCost(int indexOfcard);
	Card* exchange(int cardIndex);
	void printHand();
	void shiftCards(int index);

	friend ostream& operator<<(ostream&, const Hand&);
	Hand& operator=(const Hand&);
};