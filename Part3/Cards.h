#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Player;

class Cards
{
public:
	Cards();
	Cards(string name, string good, string action);
	Cards(const Cards& other);
	Cards& operator = (const Cards& other);
	~Cards();
	friend ostream& operator<<(ostream& output, const Cards& other);
private:
	string name;
	string good;
	string action;
};

class Deck 
{
public:
	Deck();
	Deck(const Deck& other);
	Deck& operator = (const Deck& other);
	~Deck();
	friend ostream& operator<<(ostream& output, const Deck& other);
	Cards* draw();
	vector<Cards*> GetDeck();
	void SetDeck(Cards* other);
private:
	vector<Cards*> decks;
};

class Hand 
{

public:
	Hand();
	Hand(const Hand& other);
	Hand& operator = (const Hand& other);
	~Hand();
	friend ostream& operator<<(ostream& output, const Hand& other);
	void exchange(int index, Player* player);
	vector<Cards*> GetHand();
	void SetHand(Cards* other);
private:
	vector<Cards*> hands;
};