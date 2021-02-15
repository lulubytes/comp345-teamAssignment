
#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <iostream>
#include "Map.h"
#include "Card.h"
#include "Biding.h"
using namespace std;
class Player {

public:
    Map map;
    Card card;
    Biding biding;
    void PayCoin();
    void PlaceNewArmies();
    void MoveArmies();
    void MoveOverLand();
    void BuildCity();
    void DestroyArmy();

    Player();

    Player(const Map &map, const Card &card, const Biding &biding);
};


#endif //PROJECT_PLAYER_H
