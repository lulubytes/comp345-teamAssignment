#include <iostream>
#include "Map.h"
using namespace std;

// default constructor
Territory::Territory(){
    this->countryName = NULL;
    this->player = NULL;
    this->numOfArmies = 0;
}

// normal constructor
Territory::Territory(string newCountry, string newPlayer, int newNumOfArmies){
    countryName = &newCountry;
    player = &newPlayer;
    numOfArmies = &newNumOfArmies;
}

//copy constructor
Territory::Territory(const Territory& territory) {

    this->countryName = new string (territory.GetCountryName());
    this->player = new string(territory.GetPlayer());
    this->numOfArmies = new int (territory.GetNumOfArmies());
}

//assignment operator
Territory& Territory::operator=(const Territory& territory){
    if (this != &territory) {  // make sure not same object
        delete [] countryName;  // Delete old name's memory
        delete [] player;
        delete [] numOfArmies;  
        countryName = new string (territory.GetCountryName()); // Get new space
        player = new string(territory.GetPlayer());
        numOfArmies = new int (territory.GetNumOfArmies());
    }
    return *this;    // Return ref for multiple assignment
}//end operator=


//destructor
Territory::~Territory() {
    delete this->countryName;
    delete this->player;
    delete this->numOfArmies;
}

// assessor
string Territory::GetCountryName() const{
    return *countryName;
}

// assessor
string Territory::GetPlayer() const{
    return *player;
}

// mutator GetNumOfArmies
int Territory::GetNumOfArmies() const{
    return *numOfArmies;
}

// add arm number
void Territory::AddArmy(){
    numOfArmies++;
}

// Decrement arm number
void Territory::RemoveArmy(){
    numOfArmies--;
}

// ================================================================================
//                     Map Part
// ================================================================================


// default constructor
Map::Map(){
    map<Territory*, list< pair<Territory*, int>>> allTerritory; // all countries with a list of its neighbors
    list<list<Territory*>> allContinent; // store Territories belongs to same continent in a same innner list 
    map<string, Territory*> territories; //store all territories' names
}

//copy constructor  // deep copy
Map::Map(const Map *map) {

    this->allTerritory = map->allTerritory;
    this->allContinent = map->allContinent;
    this->territories = map->territories;

}

//assignment operator
Map& Map::operator=(const Map& map){
    if(this != &map){
        this->allTerritory = map.allTerritory;
        this->allContinent = map.allContinent;
        this->territories = map.territories;
    }
    return *this;
}

// destructor
Map::~Map() {
    // delete all conponents
    for (auto i : allTerritory){
        delete i.first;
        i.second.erase(i.second.begin(), i.second.end());
    }
    for (auto i : allContinent){
        i.erase(i.begin(), i.end());
    }
    for (auto i : territories){
        delete i.second;
    }
}

// add an edge between countries // distance used to distinguish edge between sea(1) and land(0)
void Map::addEdge(Territory* a, Territory* b, int distance) {
    allTerritory[a][b] = distance;
    allTerritory[b][a] = distance;
}

// push a new continent to allContinent nested list
void Map::pushContinent(std::list<Territory*>& newContinent){
    allContinent.push_back(newContinent);

    // adds newContinent elements(territories) to whole territories list with name
    for (Territory* input : newContinent){
        territories[input->GetCountryName()] = input;
    }
}

// assessor
Territory* Map::GetTerritory(string territoryName){
    return territories[territoryName];
}


// check if THREE criterias true? 1>connected map 2>continent is connected submap 3> each territory belongs to one continent
bool Map::validate(){

    bool mapConnected = checkMapConnected();
    bool continentStillConnected = true;
    bool hasUniqueTerritories = toOneContinent();

    //loop all continents and see if all of them are connected submaps, only true when all of them are true
    for (list<Territory*> continent : allContinent){
        continentStillConnected = continentStillConnected && checkContinentConnected(&continent);
    }

    // valid ==> alert message / invalid ==> alert the reasons
    if (mapConnected && continentStillConnected && hasUniqueTerritories){
        cout << "The map is valid." << endl;
        return true;
    }
    else{
        if(!mapConnected){
            cout << "The map is invalid! ==> Because Map is not a connected graph" << endl;
        }
        if(!continentStillConnected){
            cout << "The map is invalid! ==> Because Continent is not a connected subgraph" << endl;
        }
        if(!hasUniqueTerritories){
            cout << "The map is invalid! ==> Because Territory is not unique to one Continent" << endl;
        }
    
    }
    return false;
}

// show details of all territories with their neighbor
void Map::show() {
    for (auto i : allTerritory) {
        Territory* terri = i.first;
        map <Territory*, int> neighbor = i.second;
        cout << "Country Name " << terri->GetCountryName() << " : ";
        for (auto j : neighbor) {
            Territory* target = j.first;
            int distance = j.second;

            cout << "NEARBY: " << target->GetCountryName() << "    ";
        }
        cout << endl;
    }
}

//=============================================
// some sub functions to check valid() menthod
//=============================================

// 1> check if map is connected graph
bool Map::checkMapConnected(){
    map<Territory*, bool> visitedList;

    // make all nodes to unvisited as false
    for (auto i : allTerritory){
        visitedList[i.first] = false; // contains all territories with false (unvisited)
    }

    // DFS to make all connected territories true
    traverse(allTerritory.begin()->first, &visitedList);

    // check if all territories is visited in the list
    for (auto i : visitedList){
        if (!i.second){return false;}
    }

    return true;
}

// 2> check continent is connected subgraph
bool Map::checkContinentConnected(list<Territory*>* continent){
    map<Territory*, bool> visitedList;

    // make all nodes to unvisited as false
    for (auto territory : (*continent)){
        visitedList[territory] = false; // contains all territories with false (unvisited) in one selected continent
    }

    // DFS to make all connected territories true
    traverse(*(*continent).begin(), &visitedList);

    // check if all territories is visited in the whole list
    for (auto territory : visitedList){
        if (!territory.second){
            return false;}
    }
    return true;
}

// 1.1/2.1> DFS traverse a graph
void Map::traverse(Territory* terri, map<Territory*, bool>* visitedList){
    // true if visit
    (*visitedList)[terri] = true;

    // get all its neighbors true ==> make them true ==> check neighbor's neighbor...
    map<Territory*, int> neighbor = allTerritory[terri];
    for (auto i : neighbor){

        if (!(*visitedList)[i.first]){
            traverse(i.first, visitedList);}
    }
}

// // 2.1> DFS traverse a graph
// void Map::traverse2(Territory* terri, std::map<Territory*, bool>* visitedList){
//     // true if visit
//     (*visitedList)[terri] = true;

//     // get all its neighbors true ==> make them true ==> check neighbor's neighbor...
//     map<Territory*, int> neighbor = allTerritory[terri];
//     for (auto i : neighbor){
//         if (!(*visitedList)[i.first]){ // && i.second != 1)
//             traverse2(i.first, visitedList);}
//     }
// }

// 3> each territory belongs to one continent
bool Map::toOneContinent(){
    map<Territory*, bool> visitedTerritories;

    // check each continent's territories ==> unvisited, then change to true // visited, then duplicated, return false
    for (list<list<Territory*>>::iterator territoryList = allContinent.begin(); territoryList != allContinent.end(); territoryList++){
        for (list<Territory*>::iterator territoryElement = territoryList->begin(); territoryElement != territoryList->end(); territoryElement++){
            if (visitedTerritories[*territoryElement]){
                // visited ==> invalid
                return false;
            }
            else{
                // not visited before, then make as true
                visitedTerritories[*territoryElement] = true;}
        }
    }
    // all good, no duplication
    return true;
}

