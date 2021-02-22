#include "Player.h";

using namespace std;

int main() 
{
	vector<Territory*> territoryList;
	vector<Cards*> cards;
	bidding* bid = new bidding("Ben", 100, 11);
	Player* ben = new Player("Ben", 7, 18, territoryList, cards, bid);
	Territory* territory1 = new Territory("territory1", "continent1", 0, 0, false, "", false, 0);
	Territory* territory2 = new Territory("territory2", "continent1", 0, 0, false, "", false, 0);
	Territory* territory3 = new Territory("territory3", "continent2", 0, 0, false, "", false, 0);

	cout << "Test PayCoin method -- PayCoin(2) \n" << endl;
	cout << *ben;
	ben->PayCoin(2);
	cout << *ben;
	cout << endl;

	cout << "Test PlaceNewArmies -- PlaceNewArmies(territory1, 4)\n" << endl;
	cout << *territory1;
	ben->PlaceNewArmies(territory1, 4);
	cout << *territory1;
	cout << *ben;
	cout << endl;

	cout << "Test MoveArmies -- MoveArmies(territory1, territory2, 2)\n" << endl;
	cout << *territory2;
	ben->MoveArmies(territory1, territory2, 2);
	cout << *territory1;
	cout << *territory2;
	cout << endl;

	cout << "Test MoveOverLand -- MoveOverLand(territory1, territory3, 1)" << endl;
	cout << *ben;
	ben->MoveOverLand(territory1, territory2, 1);
	ben->MoveOverLand(territory1, territory3, 1);
	cout << *ben;
	cout << endl;

	cout << "Test BuildCity -- BuildCity(territory2)\n" << endl;
	cout << *territory2;
	ben->BuildCity(territory2);
	cout << *territory2;
	cout << *ben;
	cout << endl;

	cout << "Test DestroyArmy -- DestroyArmy(territory1, 1)\n" << endl;
	cout << *territory1;
	ben->DestroyArmy(territory1, 1);
	cout << *territory1;
	cout << endl;

	cout << "Test display territory list\n";
	ben->DisplayTerritory();
	cout << endl;


	delete ben;
	ben = nullptr;

	territoryList.clear();
	cards.clear();

	return 0;
}