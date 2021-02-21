#include "MapLoader.h"

//default constructor
MapLoader::MapLoader() {
	this->m_fileName = "No file Name yet.";
	this->m_numberOfTerritory = 0;
	this->m_territoryNameArray = NULL;
}

//constructor with three parameter
MapLoader::MapLoader(string newFileName, int territorySize) {
	this->m_fileName = newFileName;
	this->m_numberOfTerritory = territorySize;
	this->m_territoryNameArray = new string[territorySize];
}

//copy constructor

MapLoader::MapLoader(const MapLoader * maploader) {
	this->m_fileName = maploader->m_fileName;
	this->m_numberOfTerritory = maploader->m_numberOfTerritory;
	this->m_territoryNameArray = new string(*maploader->m_territoryNameArray);
}

//assignment operator
MapLoader& MapLoader::operator=(const MapLoader & maploader) {
	if (this->m_territoryNameArray != NULL) {
		delete[] m_territoryNameArray;
		this->m_territoryNameArray = NULL;
		this->m_fileName = "";
		this->m_numberOfTerritory = 0;
	}

	this->m_fileName = maploader.m_fileName;
	this->m_numberOfTerritory = maploader.m_numberOfTerritory;
	this->m_territoryNameArray = new string(*maploader.m_territoryNameArray);

	return *this;
}

//accessor											
string MapLoader::getFileName() {
	return this->m_fileName;
}
string  MapLoader::getTerritoryName(int index) {

	return this->m_territoryNameArray[index];
}

int MapLoader::getNumberOfTerritory() {
	return this->m_numberOfTerritory;
}

//mutator
void MapLoader::setFileName(string newFileName) {
	this->m_fileName = newFileName;
}
void MapLoader::setTerritoryNameArray(string newTerritoryName, int index) {
	this->m_territoryNameArray[index] = newTerritoryName;
}
void MapLoader::setNumberOfTerritory(int newTerritoryNubmer) {
	this->m_numberOfTerritory = newTerritoryNubmer;
}


void MapLoader::loadTerritory() {
	int index;

	string str;
	ifstream ifs(this->m_fileName);
	if (!ifs.is_open()) {
		cout << "  Invalid input file!  " << endl;
		system("pause");
		return;
	}
	getline(ifs, str);
	while (!ifs.eof()) {
		if ((index = str.find("countries") != string::npos)) {

			for (int i = 0; i < this->getNumberOfTerritory(); i++) {
				ifs >> index >> this->m_territoryNameArray[i];
			}

		}
		if (ifs.eof()) {
			cout << "End of the file." << endl;
		}
		else
			getline(ifs, str);
	}




	cout << "Index \tTerritories" << endl;
	for (int i = 0; i < this->getNumberOfTerritory(); i++) {
		cout << i << "\t" << this->m_territoryNameArray[i] << endl;
	}


	ifs.close();

}


void MapLoader::showMap(int num) {
	
	

}


//deconstructor
MapLoader::~MapLoader() {
	if (this->m_territoryNameArray != NULL) {
		delete[] m_territoryNameArray;
		m_territoryNameArray = NULL;
	}
}




//default constract
Map::Map() {
	this->m_numOfNode = 0;
	this->m_adjacentNode = NULL;
}

//constractor with one parameter
Map::Map(int numberofNode) {

	this->m_numOfNode = numberofNode;
	this->m_mapTerritoryArray = new string[numberofNode];
	this->m_adjacentNode = new bool*[numberofNode];

	for (int i = 0; i < m_numOfNode; i++) {
		m_adjacentNode[i] = new bool[m_numOfNode];
		for (int j = 0; j < m_numOfNode; j++) {
			m_adjacentNode[i][j] = false;
		}
	}
}


//copy constractor
Map::Map(const Map * map) {
	this->m_numOfNode = map->m_numOfNode;
	this->m_mapTerritoryArray = new string[map->m_numOfNode];
	this->m_adjacentNode = new bool*[map->m_numOfNode];
	for (int i = 0; i < m_numOfNode; i++) {
		m_adjacentNode[i] = new bool[m_numOfNode];
		for (int j = 0; j < m_numOfNode; j++) {
			m_adjacentNode[i][j] = false;
		}
	}
}
//assignment operator
Map& Map::operator=(const Map &map) {
	//to delete the pointer of object, avoid they point to the same object
	if (this->m_mapTerritoryArray != NULL) {
		delete[] m_mapTerritoryArray;
		this->m_mapTerritoryArray = NULL;
		this->m_numOfNode = 0;

	}
	for (int i = 0; i < this->m_numOfNode; i++) {
		if (m_adjacentNode[i] != NULL) {
			delete[] m_adjacentNode[i];
			m_adjacentNode[i] = NULL;
		}

	}
	delete[] m_adjacentNode;

	//copy from map
	this->m_mapTerritoryArray = new string(*map.m_mapTerritoryArray);
	this->m_adjacentNode = new bool*[map.m_numOfNode];
	for (int i = 0; i < m_numOfNode; i++) {
		m_adjacentNode[i] = new bool[m_numOfNode];
		for (int j = 0; j < m_numOfNode; j++) {
			m_adjacentNode[i][j] = false;
		}
	}
	this->m_numOfNode = map.m_numOfNode;

	return *this;
}



//add an edge between two regions
void Map::addEdge(int start, int end) {
	m_adjacentNode[start][end] = true;
	m_adjacentNode[end][start] = true;
}

//remove an edge between two regions
void Map::removeEdge(int start, int end) {
	m_adjacentNode[start][end] = false;
	m_adjacentNode[end][start] = false;
}

// return the Territory Name;
string Map::getMapTerritoryName(int index) {
	return this->m_mapTerritoryArray[index];
}

// set the Territory Name;
void Map::setMapTerritoryName(string name, int index) {
	this->m_mapTerritoryArray[index] = name;
}

//display the adjacent Nodes
void Map::disPlayAdjacentNode() {
	cout << "\n***************  Map of Nodes    ***************" << endl;
	for (int i = 0; i < m_numOfNode; i++) {
		cout << "\t" << i;
	}
	cout << endl;
	for (int i = 0; i < m_numOfNode; i++) {
		cout << i << "\t";
		for (int j = 0; j < m_numOfNode; j++) {
			cout << m_adjacentNode[i][j] << "\t";
		}
		cout << "\n";
	}

}

void Map::disPlayAdjacentNodeR() {
	cout << "\n***************  Rectangle Shape of Map   ***************\n" << endl;


	for (int i = 0; i < m_numOfNode / 2; i++) {
		for (int j = 0; j < m_numOfNode; j++) {
			if (m_adjacentNode[i][j] == true) {
				cout << m_adjacentNode[i][j] << "  ";
			}

		}
	}
	cout << endl;
	for (int i = m_numOfNode / 2; i < m_numOfNode; i++) {
		for (int j = 0; j < m_numOfNode; j++) {
			if (m_adjacentNode[i][j] == true) {
				cout << m_adjacentNode[i][j] << "  ";
			}

		}
	}




	cout << endl;
}

void Map::disPlayAdjacentNodeL() {
	cout << "\n***************  L Shape of Map   ***************\n" << endl;

	for (int i = 0; i <3; i++) {

		for (int j = 0; j < m_numOfNode / 3; j++) {
			if (m_adjacentNode[i][j] == true) {
				cout << m_adjacentNode[i][j];
			}

		}
		cout << endl;
		for (int j = m_numOfNode / 3; j < m_numOfNode / 2; j++) {
			if (m_adjacentNode[i][j] == true) {
				cout << m_adjacentNode[i][j];
			}

		}
		cout << endl;
		for (int j = m_numOfNode / 2; j < m_numOfNode; j++) {
			if (m_adjacentNode[i][j] == true) {
				cout << m_adjacentNode[i][j];
			}

		}

	}


	for (int i = 3; i < m_numOfNode; i++) {

		for (int j = 0; j < m_numOfNode; j++) {
			if (m_adjacentNode[i][j] == true) {
				cout << m_adjacentNode[i][j];
			}

		}


	}








	cout << "\n\n";
}




// traverse the connected graph
void Map::traverse(int node, bool visited[]) {
	visited[node] = true;
	for (int i = 0; i < m_numOfNode; i++) {
		if (m_adjacentNode[node][i]) {
			if (!visited[i]) {
				traverse(i, visited);
			}
		}
	}
}

//verify a graph is connected or not
bool Map::validate() {
	bool * visited = new bool[m_numOfNode];
	for (int i = 0; i < m_numOfNode; i++) {
		for (int j = 0; j < m_numOfNode; j++) {
			visited[j] = false;
		}
		//traverse the graph, if visible is false, means the node is not connected.
		traverse(i, visited);
		for (int j = 0; j < m_numOfNode; j++) {
			if (!visited[j]) {
				return false;
			}
		}
	}
	return true;
}

//deconstractor
Map::~Map() {
	for (int i = 0; i < this->m_numOfNode; i++) {
		if (m_adjacentNode[i] != NULL) {
			delete[] m_adjacentNode[i];
			m_adjacentNode[i] = NULL;
		}

	}
	delete[] m_adjacentNode;

	if (this->m_mapTerritoryArray != NULL) {
		delete[] m_mapTerritoryArray;
		m_mapTerritoryArray = NULL;
	}
}