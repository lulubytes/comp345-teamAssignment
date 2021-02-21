#include<iostream>
#include<fstream>
using namespace std;

#include"MapLoader.h"



int main() {
	
	int numberOfTerrities = 10;
	MapLoader *maploader = new MapLoader("map1.txt", numberOfTerrities);
	
	maploader->loadTerritory();
	Map *map = new Map(numberOfTerrities);
	
	for (int i = 0; i < numberOfTerrities; i++) {
		
		map->m_mapTerritoryArray[i] = maploader->m_territoryNameArray[i];
	}
	

	//add adjacent edges
	cout << endl;
	map->addEdge(0, 1);
	map->addEdge(0, 2);
	map->addEdge(1, 2);
	map->addEdge(1, 5);
	map->addEdge(2, 3);
	map->addEdge(2, 6);
	map->addEdge(3, 7);
	map->addEdge(3, 5);
	map->addEdge(4, 6);
	map->addEdge(5, 8);
	map->addEdge(6, 7);
	map->addEdge(8, 9);
	
	map->disPlayAdjacentNode();

	if (map->validate()) {
		cout << "Map is a connected graph!!!!\n" << endl;
		cout << "What kind of shape would you like to load? \n1-- L Shape \n2-- Rectangle Shape" << endl;
		int num = 0;
		cin >> num;
		while (true) {
			if (num == 1) {
				cout << "Map in L Shape\n" << endl;
				map->disPlayAdjacentNodeL();

				break;
			}
			else if (num == 2) {
				cout << "Map in Rectangle shape\n" << endl;
				map->disPlayAdjacentNodeR();
				break;
			}
			else {
				cout << "Invalid Input!! Please try again!" << endl;
				cin >> num;
			}
		}
	}
	else {
		cout << "Map is not connect!!!!" << endl;

	}
		
	

	system("pause");
	return 0;
}