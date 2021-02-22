#pragma once
#include <string>
#include <vector>
using namespace std;

class bidding
{
private:
	string* name;
	int* money;
	int* bid;

public:
	bidding();
	bidding(string name, int money, int bid);
	bidding(const bidding& other);
	bidding& operator = (const bidding& other);
	void SetBid();
	int GetBid();
	void DisplayBid();
	static void CompareBid(vector<bidding*> bidList);
	friend ostream& operator<<(ostream& output, const bidding& other);

	//Destructor
	~bidding();

};