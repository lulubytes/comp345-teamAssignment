#include "Player.h"
#include <iostream>

int main()
{
	Territory* territory1 = new Territory();
	Territory* territory2 = new Territory();
	Player* player1 = new Player("Achilles", 12);
	Player* player2 = new Player();



	std::cout << "\n" << std::endl;
	std::cout << "\n payCoin:\t";
	player1->payCoin(10);
	player2->payCoin(10);
	player1->payCoin(100);
	player2->setCoin(100);
	player1->payCoin(100);


	territory1 = nullptr;
	territory2 = nullptr;
	player1 = nullptr;
	player2 = nullptr;
	
	return 0;
}
