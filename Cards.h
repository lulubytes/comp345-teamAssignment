#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Player;

class Card
{
public:
	Card();
	Card(string good, string action, string andor, string ability);
	Card(string good, string firstAction, string secondAction, string andor, string ability);
	Card(const Card& other);
	Card& operator = (const Card& other);
	~Card();
	friend ostream& operator<<(ostream& output, const Card& other);

	string getGood();
	string getAction1();
	string getAction2();

	string getAndor();


	string getAbility();

	void printCard();
private:
	//string name;
	string good;
	string action[2];

	string ability;
	string andor;
};

class Deck 
{
public:
	Deck();
	Deck(int numPlayer);
	Deck(const Deck& other);
	
	~Deck();
	friend ostream& operator<<(ostream& output, const Deck& other);
	//vector<Card*> GetDeck();
//	void SetDeck(Card* other);
	void generateDeck();
	//void printDeck();
	void shuffleDeck();
	Card* draw();
	Deck& operator=(const Deck&);

	static int  myRandomGenerator(int j);
	int getNumCards();
private:
	//vector<Card*> cards;
	Card* topCardptr;
	Card cards[34];
	int numPlayer;
};

class Hand 
{

public:
	Hand();
	Hand(const Hand& other);
	Hand(Deck* deck);
	Hand& operator = (const Hand& other);
	~Hand();
	friend ostream& operator<<(ostream& output, const Hand& other);
	int getCardCost(int indexOfcard);
	Card* exchange(int cardIndex, Player* player);
//	void printHand();
	void shiftCards(int index);
	//Output
	friend ostream& operator<<(ostream&, const Hand&);
	//Hand& operator=(const Hand&);
	//void exchange(int index, Player* player);
	//vector<Card*> GetHand();
//	void SetHand(Card* other);
private:
	//vector<Card*> cards;
	Deck* deck;
	Card* cards[6];
};