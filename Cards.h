#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>
#include "Player.h"

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
	~Card();
	Card(const Card& c);
	//assignment operators
	Card& operator = (const Card& c);
	//Accessors
	string getGood();
	string getAction1();
	string getAction2();
	
	string getAndor();
	

	string getAbility();

	void printCard();
	Card& operator=(const Card&);
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
	Card* topCardptr;
	Card cards[34];
	int numPlayer;

	//Output

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
	//CopyConstructor
	Hand(const Hand& h);
	//Deconstructor
	~Hand();
	int getCardCost(int indexOfcard);
	Card* exchange(int cardIndex, Player* player);
	void printHand();
	void shiftCards(int index);
	//Output
	friend ostream& operator<<(ostream&, const Hand&);
	Hand& operator=(const Hand&);
};