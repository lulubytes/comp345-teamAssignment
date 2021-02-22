#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <stdlib.h> 
#include <time.h>
#include <iterator> 
#include <array>

using namespace std;

class Card
{
public:
//constructor
	Card();
	
	  ~Card();
	//copy constructor
	Card(const Card& c);
Card(string good, string action);
Card(string good, string firstAction, string secondAction);

	//assignment operators
	Card& operator = (const Card& c);

	string getGood();
	string getAction1();
	string getAction2();
string good;
	string action[2];

	void printCard();

	// Operators
	Card& operator=(const Card&);

	//initialize the type vec
	//void initial_vec_type_card();
	
	//get pointer to the type vec
	vector<string>* get_ptr_type_arr();
	//for test to print vec_types_card
	void print_vec_types_card();
	
};

class Deck {

public:
	//Constructor
	Deck();
	//Copy constructor
	Deck(const Deck &d);
	//Deconstructor
	~Deck();
	void generateDeck();
	void printDeck();
	void shuffleDeck();
	Card *draw();
	Deck& operator=(const Deck&);
private:

Card *topCardptr;
	Card cards[34];
	static int  myRandomGenerator(int j);
		// Operators
	friend ostream& operator<<(ostream&, const Deck&);

};


class Hand {
private:
	Deck* deck;
	Card *cards[6];//Face-up cards
public:
	Hand() = default;
	Hand(Deck* deck);
	//CopyConstructor
	Hand(const Hand &h);
	//Deconstructor
	~Hand();
	int getCardCost(int indexOfcard);
	Card* exchange(int cardIndex);
	void printHand();
private:
	void shiftCards(int index);
		// Operators
	friend ostream& operator<<(ostream&, const Hand&);
public:
	Hand& operator=(const Hand&);
};