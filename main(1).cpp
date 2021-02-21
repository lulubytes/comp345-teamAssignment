#include "Player.h"
#include <iostream>

int main()
{
	Territory* territory1 = new Territory();
	Territory* territory2 = new Territory("Troy");
	Player* player1 = new Player("Achilles", 12);

	std::cout << "\n Creat a new army:\t";
	player1->placeNewArmies(territory1);
	Army* army = player1->getArmies()->front();
    
	std::cout << "\n Moving army:\t";
	player1->moveArmies(army, territory2);

	std::cout << "\n Moving army overland:\t";
	player1->moveOverLand(army, territory1);

	std::cout << "\n Find territory1 owner:\t";
	territory1->getOwner();

	std::cout << "\n Find territory2 owner:\t";
	territory2->getOwner();

	std::cout << "\n Destory army:\t";
	player1->destroyArmy(army);
	
	std::cout << "\n" << std::endl;

	territory1 = nullptr;
	territory2 = nullptr;
	player1 = nullptr;

	return 0;
}
