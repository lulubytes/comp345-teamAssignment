#include <iostream>
#include <string>
#include "Cards.h"
#include "Player.h"
using namespace std;


Cards::Cards() 
{
	name = "";
	good = "";
	action = "";
}

Cards::~Cards()
{}

Cards::Cards(string name, string good, string action) 
{
	name = name;
	good = good;
	action = action;
}


Cards::Cards(const Cards& other) 
{
	this->name = other.name;
	this->good = other.good;
	this->action = other.action;

}

Cards& Cards::operator=(const Cards& other) 
{
	this->name = other.name;
	this->good = other.good;
	this->action = other.action;
	return *this;
}


ostream& operator<<(ostream& output, const Cards& other) 
{
	return output << "Card Name: " << other.name << " Goods: " << other.good << " Action: " << other.action  << endl;
}

Deck::Deck() 
{

}

Deck::Deck(const Deck& other) 
{
	for (int i = 0; i < other.decks.size(); i++) 
	{
		Cards* card = new Cards(*other.decks[i]);
		this->decks.push_back(card);
	}

}

Deck& Deck::operator=(const Deck& other) 
{
	for (int i = 0; i < other.decks.size(); i++) 
	{
		Cards* card = new Cards(*other.decks[i]);
		this->decks.push_back(card);
	}
	return *this;
}

Deck::~Deck() 
{
	for (int i = 0; i < decks.size(); i++) 
	{
		delete decks[i];
		decks[i] = nullptr;
	}
}


ostream& operator<<(ostream& output, const Deck& other) 
{
	output << "Deck Cards : ";
	output << other.decks.size();
	output << endl;
	for (int i = 0; i < other.decks.size(); i++) 
	{
		output << i + 1;
		output << ": " << *(other.decks[i]);
	}
	output << endl;
	return output;
}

Cards* Deck::draw() 
{
	Cards* tempcard = new Cards(*(this->decks.front()));
	delete this->decks.front();
	this->decks.front() = nullptr;
	this->decks.erase(this->decks.begin());
	return tempcard;
}


vector<Cards*> Deck::GetDeck() 
{
	return decks;
}


void Deck::SetDeck(Cards* other) 
{
	this->decks.push_back(other);
}

Hand::Hand() 
{
}

Hand::Hand(const Hand& other) 
{
	for (int i = 0; i < other.hands.size(); i++) 
	{
		Cards* card = new Cards(*other.hands[i]);
		this->hands.push_back(card);
	}

}

Hand& Hand::operator=(const Hand& other) 
{

	for (int i = 0; i < other.hands.size(); i++) 
	{
		Cards* card = new Cards(*other.hands[i]);
		this->hands.push_back(card);
	}
	return *this;
}

Hand::~Hand() 
{
	for (int i = 0; i < hands.size(); i++) 
	{
		delete hands[i];
		hands[i] = nullptr;
	}
}

ostream& operator<<(ostream& output, const Hand& other) 
{
	output << "Hand Cards: ";
	output << endl;
	for (int i = 0; i < other.hands.size(); i++) 
	{
		output << i + 1;
		output << ": " << *(other.hands[i]);
	}
	output << endl;
	return output;
}

void Hand::SetHand(Cards* other) 
{
	this->hands.push_back(other);
}

void Hand::exchange(int index, Player* player) 
{
	int cost;
	switch (index)
	{
	case 1:
		cost = 0;
		break;
	case 2:
	case 3:
		cost = 1;
		break;
	case 4:
	case 5:
		cost = 2;
		break;
	case 6:
		cost = 3;
		break;
	default:
		break;
	}

	if (player->GetCoin() < cost) 
	{
		cout << player->GetName() << ": You do not have enough coin pay for card cost" << endl;
		return;
	}


	player->SetCoin(cost);
	Cards* card = new Cards(*hands[index - 1]);
	player->GetHandCard().push_back(card);
	cout << "\n" << player->GetName() << " has select " << *card << endl;
	Cards* hand = hands[index - 1];
	hands.erase(this->hands.begin() + (index - 1));
	delete hand;
	hand = nullptr;
	delete card;
	card = nullptr;

}

vector<Cards*> Hand::GetHand() 
{
	return hands;
}
