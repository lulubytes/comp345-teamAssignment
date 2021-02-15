#include "Player.h"

void Player::PayCoin() {
    cout << "This is PayCoin" << endl;
}

void Player::PlaceNewArmies() {
    cout << "This is PlaceNewArmies" << endl;
}

void Player::MoveArmies() {
    cout << "This is MoveArmies" << endl;
}

void Player::MoveOverLand() {
    cout << "This is MoveOverLand" << endl;
}

void Player::BuildCity() {
    cout << "This is BuildCity" << endl;
}
void Player::DestroyArmy() {
    cout << "This is DestroyArmy" << endl;
}

Player::Player() {}

Player::Player(const Map &map, const Card &card, const Biding &biding) : map(map), card(card), biding(biding) {}


