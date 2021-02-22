#include <iostream>
#include<map>
#include<fstream>
#include<vector>
using namespace std;

#include "Map.h"        	//uncomment this line and Part 1 to test Map.cpp	// comment MapLoader.cpp to avoid dupilicates
// #include"MapLoader.h"   	//uncomment this line and Part 2 to test MapLoader.cpp	// comment Map.cpp to avoid dupilicates
#include "Cards.h"         	// uncomment this line and Part 4 to test Cards.cpp

#include "Player.h";		// uncomment this line and Part 3 to test Player.cpp

#include "bidding.h"		//uncomment this two lines and Part 5 to test bidding.cpp
#include "BPlayer.h"		//uncomment this two lines and Part 5 to test bidding.cpp


int main() {
    //=====================================================================================================
    //          part 1
    //=====================================================================================================
 
	// Map map;

	// Territory *country0 = new Territory("Country0", "player0", 2);
	// Territory *country1 = new Territory("Country1", "player1", 3);
	// Territory *country2 = new Territory("Country2", "player2", 1);
	// Territory *country3 = new Territory("Country3", "player3", 4);
	// Territory *country4 = new Territory("Country4", "player4", 2);
	// Territory *country5 = new Territory("Country5", "player5", 3);
	// Territory *country6 = new Territory("Country6", "player6", 6);
	// Territory *country7 = new Territory("Country7", "player7", 3);
	// Territory *country8 = new Territory("Country8", "player8", 3);
	// Territory *country9 = new Territory("Country9", "player9", 4);
	// Territory *country10 = new Territory("Country10", "player10", 5);
	// Territory *country11 = new Territory("Country11", "player11", 3);
	// Territory *country12 = new Territory("Country12", "player12", 2);
	// Territory *country13 = new Territory("Country13", "player13", 0);
	// Territory *country14 = new Territory("Country14", "player14", 1);
    
	// // Continent 1
	// map.addEdge(country1, country2, 0);
	// map.addEdge(country2, country3, 0);
	// map.addEdge(country3, country4, 0);

	// // add Counties to Continent1
    // list<Territory*> continent1;
    // continent1.push_back(country1);
    // continent1.push_back(country2);
    // continent1.push_back(country3);
    // continent1.push_back(country4);
    // map.pushContinent(continent1);

    // //Continent 2
	// map.addEdge(country4, country5, 1);
	// map.addEdge(country5, country6, 0);
	// map.addEdge(country6, country7, 0);
	// map.addEdge(country7, country8, 0);

	// // add Counties to Continent2
    // list<Territory*> continent2;
    // continent2.push_back(country5);
    // continent2.push_back(country6);
    // continent2.push_back(country7);
    // continent2.push_back(country8);
    // map.pushContinent(continent2);

	// // Continent 3
	// map.addEdge(country8, country9, 1);
    // map.addEdge(country9, country10, 0);
    // map.addEdge(country10, country11, 0);
	// map.addEdge(country11, country12, 0);    //comment any two to test connected Map //==// Continent
    // map.addEdge(country12, country13, 0);                   
	// map.addEdge(country13, country14, 0);

	// // add Counties to Continent3
    // list<Territory*> continent3;
    // continent3.push_back(country9);
    // continent3.push_back(country10);
    // continent3.push_back(country11);
    // continent3.push_back(country12);
    // continent3.push_back(country13);
    // continent3.push_back(country14);

	
    // // continent3.push_back(&country5);      // uncomment this to test for belongs to unique Continent
    // map.pushContinent(continent3);
	

	// map.show();                      // uncomment this to print all countries and their neabers
	// map.validate();

	// delete country0;
	// delete country1;
	// delete country2;
	// delete country3;
	// delete country4;
	// delete country5;
	// delete country6;
	// delete country7;
	// delete country8;
	// delete country9;
	// delete country10;
	// delete country11;
	// delete country12;
	// delete country13;
	// delete country14;
	

    //=====================================================================================================
    //          part 2
    //=====================================================================================================
	// int numberOfTerrities = 10;
	// MapLoader *maploader = new MapLoader("map1.txt", numberOfTerrities);
	
	// maploader->loadTerritory();
	// Map *map = new Map(numberOfTerrities);
	
	// for (int i = 0; i < numberOfTerrities; i++) {
		
	// 	map->m_mapTerritoryArray[i] = maploader->m_territoryNameArray[i];
	// }
	

	// //add adjacent edges
	// cout << endl;
	// map->addEdge(0, 1);
	// map->addEdge(0, 2);
	// map->addEdge(1, 2);
	// map->addEdge(1, 5);
	// map->addEdge(2, 3);
	// map->addEdge(2, 6);
	// map->addEdge(3, 7);
	// map->addEdge(3, 5);
	// map->addEdge(4, 6);
	// map->addEdge(5, 8);
	// map->addEdge(6, 7);
	// map->addEdge(8, 9);
	
	// map->disPlayAdjacentNode();

	// if (map->validate()) {
	// 	cout << "Map is a connected graph!!!!\n" << endl;
	// 	cout << "What kind of shape would you like to load? \n1-- L Shape \n2-- Rectangle Shape" << endl;
	// 	int num = 0;
	// 	cin >> num;
	// 	while (true) {
	// 		if (num == 1) {
	// 			cout << "Map in L Shape\n" << endl;
	// 			map->disPlayAdjacentNodeL();

	// 			break;
	// 		}
	// 		else if (num == 2) {
	// 			cout << "Map in Rectangle shape\n" << endl;
	// 			map->disPlayAdjacentNodeR();
	// 			break;
	// 		}
	// 		else {
	// 			cout << "Invalid Input!! Please try again!" << endl;
	// 			cin >> num;
	// 		}
	// 	}
	// }
	// else {
	// 	cout << "Map is not connect!!!!" << endl;

	// }
		
	

	// system("pause");

	//=====================================================================================================
    //          part 3
    //=====================================================================================================
	// vector<Territory*> territoryList;
	// vector<Cards*> cards;
	// bidding* bid = new bidding("Ben", 100, 11);
	// Player* ben = new Player("Ben", 7, 18, territoryList, cards, bid);
	// Territory* territory1 = new Territory("territory1", "continent1", 0, 0, false, "", false, 0);
	// Territory* territory2 = new Territory("territory2", "continent1", 0, 0, false, "", false, 0);
	// Territory* territory3 = new Territory("territory3", "continent2", 0, 0, false, "", false, 0);

	// cout << "Test PayCoin method -- PayCoin(2) \n" << endl;
	// cout << *ben;
	// ben->PayCoin(2);
	// cout << *ben;
	// cout << endl;

	// cout << "Test PlaceNewArmies -- PlaceNewArmies(territory1, 4)\n" << endl;
	// cout << *territory1;
	// ben->PlaceNewArmies(territory1, 4);
	// cout << *territory1;
	// cout << *ben;
	// cout << endl;

	// cout << "Test MoveArmies -- MoveArmies(territory1, territory2, 2)\n" << endl;
	// cout << *territory2;
	// ben->MoveArmies(territory1, territory2, 2);
	// cout << *territory1;
	// cout << *territory2;
	// cout << endl;

	// cout << "Test MoveOverLand -- MoveOverLand(territory1, territory3, 1)" << endl;
	// cout << *ben;
	// ben->MoveOverLand(territory1, territory2, 1);
	// ben->MoveOverLand(territory1, territory3, 1);
	// cout << *ben;
	// cout << endl;

	// cout << "Test BuildCity -- BuildCity(territory2)\n" << endl;
	// cout << *territory2;
	// ben->BuildCity(territory2);
	// cout << *territory2;
	// cout << *ben;
	// cout << endl;

	// cout << "Test DestroyArmy -- DestroyArmy(territory1, 1)\n" << endl;
	// cout << *territory1;
	// ben->DestroyArmy(territory1, 1);
	// cout << *territory1;
	// cout << endl;

	// cout << "Test display territory list\n";
	// ben->DisplayTerritory();
	// cout << endl;


	// delete ben;
	// ben = nullptr;

	// territoryList.clear();
	// cards.clear();
	// //=====================================================================================================
    // //          part 4
    // //=====================================================================================================
	// // create a deck
    // Deck* deck = new Deck();

    // // generate the cards
    // deck->generateDeck();
    // cout << "Deck Object\n" << endl;
    // deck->printDeck();

    // // shuffle the deck
   	// // deck->shuffleDeck();
   	// // cout << "Shuffled Deck\n" << endl;
  	// //  deck->printDeck();


    // cout << "Card Space\n" << endl;
    
    // Hand* hand = new Hand(deck);
   
    // //Testing exchange method
    
    // int index =0 ;
    // while (index >= 0) {
    //     hand->printHand();
    //     cout << "Enter index number \n";
    //     cin >> index;
    //     hand->exchange(index);
    //     cout << "After exchange: \n" << endl;
    // }

    // // Deallocating heap.
    // if (hand)
    //     delete hand;
    // hand = nullptr;
    // if (deck)
    //     delete deck;
    // deck = nullptr;
	//=====================================================================================================
    //          part 5
    //=====================================================================================================
	// int numberOfPlayer = 0, coin = 0,bid = 0;
    // string name = "";
    // vector<BPlayer*> player;
    // cout<< "How many players do you have ?"<< endl;
    // cin >> numberOfPlayer;
    // while (numberOfPlayer < 2 || numberOfPlayer > 4) {
    //     cout << "The value is not valid!" << endl;
    //     cin >> numberOfPlayer;
    // } //check numbers of player
    
    // if (numberOfPlayer == 4) 
    //     coin = 9;
    // if (numberOfPlayer == 3) 
    //     coin = 11;
    // if (numberOfPlayer == 2) 
    //     coin = 14;
    
    // for (int i = 1; i <= numberOfPlayer; i++) {
    //     cout << i << " " << " name: " << endl;
    //     cin >> name;
    //     cout << "How much would you like to bid ? " << endl;
    //     cin>> bid;
    //     while(bid>coin||bid<0){
    //         cout << "the value is not correct, reenter! " << endl;
    //         cin>> bid;
    //     }
    //     BPlayer* p = new BPlayer(name, bid);
    //     p->setCoin(coin);
    //     player.push_back(p);
    // }
    
    
    // //Player *player1 = new Player("yudan", 3);
    // //Player *player2 =new Player("yuwan", 4);
    // //Player *player3 =new Player("yuHan", 3);
    // //Player *player4 = new Player("yuluan", 6); 
    
    // //player.push_back(player1);
    // //player.push_back(player2);
    // //player.push_back(player3);
    // //player.push_back(player4);
    // //for(int i = 0;i<player.size();i++){
    //     //cout <<" the result is :"<< player[i]->getName()<<  player[i]->getBidFacility()->getBid()  <<endl;
    // //}
    // cout <<" the winner is :"<< player[bidding::biddingFacility(player)]->getName() <<endl;


    return 0;
}