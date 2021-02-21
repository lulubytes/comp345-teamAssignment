#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;



class MapLoader {
public:
	MapLoader();								//default constructor	
	MapLoader( string newFileName, int num);	//constructor with two parameter
	MapLoader(const MapLoader * maploader);		//copy constructor
	MapLoader& operator=(const MapLoader & maploader);		//assignment operator


	//accessor
	string getFileName();
	string getTerritoryName(int index);
	int getNumberOfTerritory();

	//mutator
	void setFileName(string newFileName);
	void setTerritoryNameArray(string territoryName, int index);
	void setNumberOfTerritory(int newTerritoryNumber);

	//to generate Territory
	void loadTerritory();
	void showMap(int num);						//load Map in different shape
	string * m_territoryNameArray;				//a pointer point to territory array
	
	//deconstructor
	~MapLoader();								


private: 
	string m_fileName;							//input file 
	
	int m_numberOfTerritory;						//number of total territories


};


class Map {
public:
	Map();										//default constract
	Map(int numberofNode);						//constractor with one parameter
	Map(const Map * map);						//copy constractor
	Map& operator=(const Map &map);				//assignment operator
	string getMapTerritoryName(int index);		// return the Territory Name;
	void setMapTerritoryName(string name, int index);					// set the Territory Name;
	void addEdge(int start, int end);		//add an edge between two regions
	void removeEdge(int edge1, int edge2);	//remove an edge between two regions
	void disPlayAdjacentNode();				//display the adjacent Nodes
	void disPlayAdjacentNodeL();
	void disPlayAdjacentNodeR();
	void traverse(int edge, bool*);			// traverse the connected graph
	bool validate();
	string * m_mapTerritoryArray;
	~Map();									//deconstractor

private:

	bool ** m_adjacentNode;					//boolean ** 2D array to represent adjacency between regions.
	int m_numOfNode;						//number of nodes to store the regions.
											//sotre the territory name 
};