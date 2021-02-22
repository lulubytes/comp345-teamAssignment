#include "bidding.h"
#include <iostream>
#include <string>
using namespace std;

bidding::bidding() 
{
}

bidding::bidding(string name, int money, int bid)
{
	this->name = new string(name);
	this->money = new int(money);
	this->bid = new int(bid);
}


bidding::bidding(const bidding& other)
{
	this->name = new string(*other.name);
	this->money = new int(*other.money);
	this->bid = new int(*other.bid);
}

bidding& bidding::operator=(const bidding& other) 
{
	if (&other == this)
		return *this;
	*this->name = *other.name;
	*this->money = *other.money;
	*this->bid = *other.bid;
	return *this;
}



void bidding::SetBid()
{
	cout << "Enter the amount you wanna bid: ";
	cin >> *bid;
	while (bid < 0)
	{
		cout << "You can't bid less than 0";
		cin.clear();
		cin >> *bid;
	}
}


int bidding::GetBid()
{
	return *bid;
}


void bidding::CompareBid(vector<bidding*> bidList)
{
	int max = 0;
	string maxName = *bidList[0]->name;
	size_t len = sizeof(bidList) / sizeof(bidList[0]);
	bool beSame = false;

	for (size_t i = 0; i < bidList.size(); i++)
	{
		cout << *bidList[i]->name << " has bid " << *bidList[i]->bid << endl;
		if (*bidList[i]->bid > max)
		{
			max = *bidList[i]->bid;
			maxName = *bidList[i]->name;
		}

	}

	for (int i = 0; i < bidList.size(); i++)
	{

		if ((*bidList[i]->bid) == max && (*bidList[i]->name).compare(maxName) < 0)
		{
			maxName = (*bidList[i]->name);
			beSame = true;
		}

	}
	if (max == 0)
		cout << "\nThe bid of all player are 0 so " << maxName << " will go first in alphabetical order " << endl;
	else
	{
		if (beSame)
			cout << "\nTwo or more players have the same bid but " << maxName << " will go first in alphabetical order " << endl;
		else
			cout << "\n" << maxName << " will go first due to highest bid(" << max << ")";
	}
}


ostream& operator<<(ostream& output, const bidding& bid)
{
	output << "Name: " << bid.name << " Money: " << bid.money << " Bid: " << bid.money << endl;
	return output;
}


bidding::~bidding() 
{
	cout << "bidding destructor is called" << endl;
	if (name != nullptr)
	{
		delete name;
		name = nullptr;
	}
	if (money != nullptr)
	{
		delete money;
		money = nullptr;
	}
	if (bid != nullptr)
	{
		delete bid;
		bid = nullptr;
	}

}