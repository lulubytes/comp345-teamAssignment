#include <iostream>
#include<map>
#include "Map.h"

int main() {

	Map map;

	Territory country0("Country0", "player0", 2);
	Territory country1("Country1", "player1", 3);
	Territory country2("Country2", "player2", 1);
	Territory country3("Country3", "player3", 4);
	Territory country4("Country4", "player4", 2);
	Territory country5("Country5", "player5", 3);
	Territory country6("Country6", "player6", 6);
	Territory country7("Country7", "player7", 3);
	Territory country8("Country8", "player8", 3);
	Territory country9("Country9", "player9", 4);
	Territory country10("Country10", "player10", 5);
	Territory country11("Country11", "player11", 3);
	Territory country12("Country12", "player12", 2);
	Territory country13("Country13", "player13", 0);
	Territory country14("Country14", "player14", 1);
    
	// Continent 1
	map.addEdge(&country1, &country2, 0);
	map.addEdge(&country2, &country3, 0);
	map.addEdge(&country3, &country4, 0);

	// add Counties to Continent1
    list<Territory*> continent1;
    continent1.push_back(&country1);
    continent1.push_back(&country2);
    continent1.push_back(&country3);
    continent1.push_back(&country4);
    map.pushContinent(continent1);

    //Continent 2
	map.addEdge(&country4, &country5, 1);
	map.addEdge(&country5, &country6, 0);
	map.addEdge(&country6, &country7, 0);
	map.addEdge(&country7, &country8, 0);

	// add Counties to Continent2
    list<Territory*> continent2;
    continent2.push_back(&country5);
    continent2.push_back(&country6);
    continent2.push_back(&country7);
    continent2.push_back(&country8);
    map.pushContinent(continent2);

	// Continent 3
	map.addEdge(&country8, &country9, 1);
    map.addEdge(&country9, &country10, 0);
    map.addEdge(&country10, &country11, 0);
	map.addEdge(&country11, &country12, 0);    //comment any two to test connected Map //==// Continent
    map.addEdge(&country12, &country13, 0);                   
	map.addEdge(&country13, &country14, 0);

	// add Counties to Continent3
    list<Territory*> continent3;
    continent3.push_back(&country9);
    continent3.push_back(&country10);
    continent3.push_back(&country11);
    continent3.push_back(&country12);
    continent3.push_back(&country13);
    continent3.push_back(&country14);

	
    // continent3.push_back(&country5);      // uncomment this to test for belongs to unique Continent
    map.pushContinent(continent3);
	

	map.show();                      // uncomment this to print all countries and their neabers
	map.validate();

	return 0;
}