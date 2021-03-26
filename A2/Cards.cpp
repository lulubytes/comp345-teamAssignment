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
    string Phoenix = "Ancient Phoenix";
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
    string TEMPLE = "Arcane Temple";
    string TREASURY = "Mountain Treasury";
    string SPHINX = "Arcane Sphinx";
    string DWARF = "Mountain Dwarf";
    //4 player cards(34)
    string CASTLE = "Castle";
    string CASTLE2 = "Castle 2";
};


struct Ability {
    string P1M = "+1 Move";
    string P1A = "+1 Army";
    string FYLING = "Flying";
    string OE = "1 Elixer";
    string TE = "2 Elixer";
    string THRE = "3 Elixer";
    string OA2C = "1 Elixer and 2 coins";
    string P1AR = "+1 VP per Arcaine card";
    string P1VP = "+1 VP per Ancient card";
    string P1VPF = "+1 VP per Fyling card";
  string P1VP2 = "+1 VP per Forest card";
    string P1VPC = "+1 VP per Cursed card";
    string P1VPN = "+1 VP per Night card";
    string P5VP3 = "All three noble cards = 5 VP";
    string P3VP2 = "+3 If you have 2 Mountain cards";
    string P1VPD = "+1 VP per Dire card";
    string ITA = "Immune to attack";
    string P1P3 = "+1 VP per 2 coins";
  
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

Card::Card(string gd, string typ, string act1, string act2, string abt)
{
    good = gd;
    action[0] = act1;
    action[1] = act2;
    ability = abt;
    andor = typ;
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
    return *this;
}


//Deck****************************************


//Creates the whole deck
void Deck::generateDeck()
{
    Good gd;
    Ability abt;

    //each card with good and 2 or 1 action
    cards[0] = Card(gd.PIXIE, "", "Move4", abt.P1A);
    cards[1] = Card(gd.STRONGHOLD, "", "BuildCity", abt.P1VPD);
    cards[2] = Card(gd.Phoenix, "", "Move5", abt.FYLING);
    cards[3] = Card(gd.Spirit, "", "Add4", abt.THRE);
    cards[4] = Card(gd.WOODS, "and", "BuildCity", "Add1", abt.P1A);
    cards[5] = Card(gd.SAGE, "", "Move3", abt.P1VP);
    cards[6] = Card(gd.CB, "", "Move6", abt.TE);
    cards[7] = Card(gd.GAR, "", "Move5", abt.FYLING);
    cards[8] = Card(gd.KING, "or", "Add3", "Move4", abt.OE);
    cards[9] = Card(gd.MAUSOLEUM, "", "BuildCity", abt.P1M);
    cards[10] = Card(gd.TOWER, "", "BuildCity", abt.P1VPF);
    cards[11] = Card(gd.DRAGON, "and", "Add3", "Destory", abt.FYLING);
    cards[12] = Card(gd.GIANT, "and", "Add3", "Destory", abt.ITA);
    cards[13] = Card(gd.EYE, "", "Add4", abt.FYLING);
    cards[14] = Card(gd.GOB, "", "Move4", abt.OE);

    cards[15] = Card(gd.OGRE, "", "Move2", abt.P1P3);
    cards[16] = Card(gd.LAKE, "or", "Add2", "Move3", abt.P1VPF);
    cards[17] = Card(gd.ELF, "or", "Add3", "Move2", abt.P1A);
    cards[18] = Card(gd.GNOME, "", "Move2", abt.THRE);
    cards[19] = Card(gd.TOWN, "", "BuildCity", abt.P1M);
    cards[20] = Card(gd.GRAVEYARD, "", "Add2", abt.P1VPC);
    cards[21] = Card(gd.HILLS, "", "Add3", abt.P5VP3);
    cards[22] = Card(gd.KNIGHT, "and", "Add4", "Destory", abt.P1M);
    cards[23] = Card(gd.UNICORN, "and", "Move4", "Add1", abt.P1M);
    cards[24] = Card(gd.HYDRA, "and", "Move4", "Destory", abt.P1A);
    cards[25] = Card(gd.VILLAGE, "", "BuildCity", abt.P1A);
    cards[26] = Card(gd.WIZARD, "and", "Add4", "Destory", abt.P1VPN);

    //3 Player cards
    if (Deck::number >= 3) {
        cards[27] = Card(gd.SPHINX, "or", "Add3", "Move4", abt.FYLING);
        cards[28] = Card(gd.MANTI, "and", "Add4", "Destory", abt.P1M);
        cards[29] = Card(gd.TEMPLE, "", "Move3", abt.P1AR);
        cards[30] = Card(gd.DWARF, "and", "Add2", "Destory", abt.P3VP2);
        cards[31] = Card(gd.TREASURY, "", "Move3", abt.OA2C);
    }
    //4 Player cards
    if (Deck::number >= 4) {
        cards[32] = Card(gd.CASTLE, "or", "Add4", "BuildCity", abt.OE);
        cards[33] = Card(gd.CASTLE2, "and", "Move3", "BuildCity", abt.OE);
    }
}

Deck::Deck()
{
    topCard = &cards[0];
    number = 2;
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
    number = numPlay;
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
    if (number == 2) return 26;
    if (number == 3) return 32;
    if (number == 4) return 34;
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

//print the content of hand
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

