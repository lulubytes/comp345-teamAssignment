#include <iostream>
#include <string>
#include "..\header\Cards.h"
#include "..\header\Player.h"
#include <filesystem>
#include <algorithm>
#include <stdio.h>
using namespace std;
#include <random>

using namespace std;


// information of cards**********************
struct Good
{
    //2 players cards(26)
    string PhOneElinix = "Ancient PhOneElinix";
    string Spirit = "Ancient Tree Spirit";
    string CB = "Cursed Banshee";
    string KING = "Cursed King";
    string TOWER = "Cursed Tower";
    string EYE = "Dire Eye";
    string GOB = "Dire Goblin";
    string ELF = "Forest Elf";
    string PIXIE = "Forest Pixie";
    string GRAVEYARD = "Graveyard";
    string HYDRA = "Night Hydra";
    string WIZARD = "Night Wizard";
    string KNIGHT = "Noble Knight";
    string STRONGHOLD = "Stronghold";
    string SAGE = "Ancient Sage";
    string WOODS = "Ancient Woods";
    string GAR = "Cursed Gargoyles";
    string MAUSOLEUM = "Cursed Mausoleum";
    string DRAGON = "Dire Dragon";
    string GIANT = "Dire Giant";
    string OGRE = "Dire Ogre";
    string GNOME = "Forest Gnome";
    string TOWN = "Forest Tree Town";
    string LAKE = "Lake";
    string VILLAGE = "Night Village";
    string HILLS = "Noble Hills";
    string UNICORN = "Noble Unicorn";
    //3 players cards(32)
    string MANTI = "Arcane Manticore";
    string TwoEliMPLE = "Arcane TwoElimple";
    string TREASURY = "Mountain Treasury";
    string SPHINX = "Arcane Sphinx";
    string DWARF = "Mountain Dwarf";
    //4 player cards(34)
    string CASTLE = "Castle";
    string CASTLE2 = "Castle 2";
};


struct Ability {
    string Plus1Move = "+1 Move";
    string Plus1Army = "+1 Army";
    string FYLING = "Flying";
    string OneEli = "1 Elixer";
    string TwoEli = "2 Elixer";
    string ThreeEli = "3 Elixer";
    string OneEliAndTwoCoin = "1 Elixer and 2 coins";
    string Plus1VpArcaine = "+1 VP per Arcaine card";
    string Plus1VpAncient = "+1 VP per Ancient card";
    string Plus1VpFlying = "+1 VP per Fyling card";
  string Plus1VpForest = "+1 VP per Forest card";
    string Plus1VpCursed = "+1 VP per Cursed card";
    string Plus1VpNight = "+1 VP per Night card";
    string All3Eli5VP = "All ThreeElie noble cards = 5 VP";
    string Win3TwoMountain = "+3 If you have 2 Mountain cards";
    string Plus1VpDire = "+1 VP per Dire card";
    string Attack = "Immune to attack";
    string Plus1TwoCoin = "+1 VP per 2 coins";
  
};



//Card**********************************
Card::Card() {};
Card :: ~Card() {};
Card::Card(string gd, string typ, string act, string abt)
{
    good = gd;
    action[0] = act;
    ability = abt;
    andor = typ;
   
}
Card::Card(string gd, string typ, string act, string abt,int num)
{
    good = gd;
    action[0] = act;
    ability = abt;
    andor = typ;
    number = num;
}

Card::Card(string gd, string typ, string act1, string act2, string abt)
{
    good = gd;
    action[0] = act1;
    action[1] = act2;
    ability = abt;
    andor = typ;
   
}

Card::Card(string gd, string typ, string act1, string act2, string abt, int num)
{
    good = gd;
    action[0] = act1;
    action[1] = act2;
    ability = abt;
    andor = typ;
    number = num;
}

//Copy constructor
Card::Card(const Card& c)
{
    good = c.good;
    action[0] = c.action[0];
    action[1] = c.action[1];
}

string Card::getGood()
{
    return good;
}

string Card::getAction1()
{
    return action[0];
}

string Card::getAction2()
{
    return action[1];
}

string Card::getAbility()
{
    return ability;
}
int Card::getNumber()
{
    return number;
}
//print information
void Card::printCard()
{
    cout << "This is the card information: " << good << endl;
    cout << "Good: " << good << endl;
    cout << "Ability: " << ability << endl;
    cout << "Action: " << action[0] << endl;
    if (andor == "and") cout << "AND" << endl;
    if (andor == "or")cout << "OR" << endl;
    cout << "Action: " << action[1];
    
}
// toString method
ostream& operator<<(ostream& strm, const Card& card) {
    return strm << "Good: " << card.good
        << "Action: " << card.action[0] << "\n"
        << card.action[1] << endl;
}

// assignment operator
Card& Card::operator=(const Card& another)
{
    if (&another == this)
        return *this;
    good = another.good;
    andor = another.andor;
    action[0] = another.action[0];
    action[1] = another.action[1];
    ability = another.ability;
    number = another.number;
    return *this;
}


//Deck****************************************


//CreaTwoElis the whole deck
void Deck::generateDeck()
{
    
    Good gd;
    Ability abt;

    //each card with good and 2 or 1 action
    cards[0] = Card(gd.PIXIE, "", "Move4", abt.Plus1Army);
    cards[1] = Card(gd.STRONGHOLD, "", "BuildCity", abt.Plus1VpDire);
    cards[2] = Card(gd.PhOneElinix, "", "Move5", abt.FYLING);
    cards[3] = Card(gd.Spirit, "", "Add4", abt.ThreeEli);
    cards[4] = Card(gd.WOODS, "and", "BuildCity", "Add1", abt.Plus1Army);
    cards[5] = Card(gd.SAGE, "", "Move3", abt.Plus1VpAncient);
    cards[6] = Card(gd.CB, "", "Move6", abt.TwoEli);
    cards[7] = Card(gd.GAR, "", "Move5", abt.FYLING);
    cards[8] = Card(gd.KING, "or", "Add3", "Move4", abt.OneEli);
    cards[9] = Card(gd.MAUSOLEUM, "", "BuildCity", abt.Plus1Move);
    cards[10] = Card(gd.TOWER, "", "BuildCity", abt.Plus1VpFlying);
    cards[11] = Card(gd.DRAGON, "and", "Add3", "Destory", abt.FYLING);
    cards[12] = Card(gd.GIANT, "and", "Add3", "Destory", abt.Attack);
    cards[13] = Card(gd.EYE, "", "Add4", abt.FYLING);
    cards[14] = Card(gd.GOB, "", "Move4", abt.OneEli);

    cards[15] = Card(gd.OGRE, "", "Move2", abt.Plus1TwoCoin);
    cards[16] = Card(gd.LAKE, "or", "Add2", "Move3", abt.Plus1VpForest);
    cards[17] = Card(gd.ELF, "or", "Add3", "Move2", abt.Plus1Army);
    cards[18] = Card(gd.GNOME, "", "Move2", abt.ThreeEli);
    cards[19] = Card(gd.TOWN, "", "BuildCity", abt.Plus1Move);
    cards[20] = Card(gd.GRAVEYARD, "", "Add2", abt.Plus1VpCursed);
    cards[21] = Card(gd.HILLS, "", "Add3", abt.All3Eli5VP);
    cards[22] = Card(gd.KNIGHT, "and", "Add4", "Destory", abt.Plus1Move);
    cards[23] = Card(gd.UNICORN, "and", "Move4", "Add1", abt.Plus1Move);
    cards[24] = Card(gd.HYDRA, "and", "Move4", "Destory", abt.Plus1Army);
    cards[25] = Card(gd.VILLAGE, "", "BuildCity", abt.Plus1Army);
    cards[26] = Card(gd.WIZARD, "and", "Add4", "Destory", abt.Plus1VpNight);

    //3 Player cards
    if (Deck::numberP >= 3) {
        cards[27] = Card(gd.SPHINX, "or", "Add3", "Move4", abt.FYLING, 3);
        cards[28] = Card(gd.MANTI, "and", "Add4", "Destory", abt.Plus1Move, 3);
        cards[29] = Card(gd.TwoEliMPLE, "", "Move3", abt.Plus1VpArcaine, 3);
        cards[30] = Card(gd.DWARF, "and", "Add2", "Destory", abt.Win3TwoMountain, 3);
        cards[31] = Card(gd.TREASURY, "", "Move3", abt.OneEliAndTwoCoin, 3);
    }
    //4 Player cards
    if (Deck::numberP >= 4) {
        cards[32] = Card(gd.CASTLE, "or", "Add4", "BuildCity", abt.OneEli, 4);
        cards[33] = Card(gd.CASTLE2, "and", "Move3", "BuildCity", abt.OneEli, 4);
    }
}

Deck::Deck()
{
    topCard = &cards[0];
    numberP = 2;
}

//CopyConstructor
Deck::Deck(const Deck& d)
{
    topCard = d.topCard;
    for (int i = 0; i < 34; i++)
    {
        cards[i] = d.cards[i];
    }
}

Deck::Deck(int numPlay) {
    topCard = &cards[0];
    numberP = numPlay;
}

//Deconstructor
Deck ::~Deck()
{

    topCard = nullptr;
}
//Displays all deck
void Deck::printDeck()
{
    for (int i = 0; i < 34; i++)
    {
        cout << "This is the whole card information: " << i + 1 << endl;
        cout << "Card number: " << i + 1 << endl;
        cards[i].printCard();
        cout << endl;
    }
}
int Deck::getNumCards() {
    if (numberP == 2) return 26;
    if (numberP == 3) return 32;
    if (numberP == 4) return 34;
}

int Deck::myRandomGenerator(int j) {
    return rand() % j;
}

void Deck::shuffleDeck() {
    srand(unsigned( time(0)));
     
   // random_shuffle(&cards[0], &cards[getNumCards()], myRandomGenerator);
}

//draw card 
Card* Deck::draw()
{
    Card* card = topCard;
    topCard++;
    return card;
}

// toString Deck
ostream& operator<<(ostream& strm, const Deck& deck)
{
    return strm << "We have 34 cards totally";
}
// Assignment operator.
Deck& Deck::operator=(const Deck& anotherDeck)
{
    if (&anotherDeck == this)
        return *this;
    for (int i = 0; i < 34; i++)
    {
        cards[i] = anotherDeck.cards[i];
    }
    topCard = &cards[0];
    return *this;
}


//hand*******************************************************

Hand::Hand(Deck* dk)
{
    deck = dk;
    //draw 6 cards from deck
    for (int i = 0; i < 6; i++)
    {
        cards[i] = deck->draw();
    }
}

//CopyConstructor
Hand::Hand(const Hand& h)
{
    deck = new Deck(*(h.deck));
    for (int i = 0; i < 6; i++)
    {
        cards[i] = deck->draw();
    }
}

Hand::~Hand() {
    deck = nullptr;
}

//Returns the cost of a card 
int Hand::getCost(int index)
{
    if (index == 0)
        return 0;
    else if (index == 1)
        return 1;
    else if (index == 2)
        return 1;
    else if (index == 3)
        return 2;
    else if (index == 4)
        return 2;
    else if (index == 5)
        return 3;
    else
        return -1;
}

//Shifts cards left with the index number
void Hand::shiftCards(int index)
{
    for (int i = index; i < 6; i++)
    {
        cards[i] = cards[i + 1];
    }
}

//choose card and get the cost

Card* Hand::exchange(int cardIndex) {

    int cost = getCost(cardIndex);

    Card* pickedCard = (cards[cardIndex]);

    shiftCards(cardIndex);

    cards[5] = deck->draw(); 

    return pickedCard;
}

//print the conTwoElint of hand
void Hand::printHand()
{
    //get the goods for each card
    string goodCard[6];
    string action1[6];
    string action2[6];
    for (int i = 0; i < 6; i++)
    {
        goodCard[i] = cards[i]->getGood();
        action1[i] = cards[i]->getAction1();
        action2[i] = cards[i]->getAction2();
        cout << "This is the information of hand cards: " << goodCard[i] << endl;
        cout << "Good: " << goodCard[i] << endl;
        cout << "Action 1: " << action1[i] << endl;
        cout << "Action 2: " << action2[i] << endl;
    }
}

// toString method
ostream& operator<<(ostream& strm, const Hand& hand)
{
    return strm << "These are 6 cards in hand";
}
Hand& Hand::operator=(const Hand& anotherHand)
{
    if (&anotherHand == this)
        return *this;
    if (anotherHand.deck)
    {
        deck = new Deck(*anotherHand.deck);
        for (int i = 0; i < 6; i++)
        {
            cards[i] = deck->draw();
        }
    }
    else
        deck = nullptr;
    return *this;
}

