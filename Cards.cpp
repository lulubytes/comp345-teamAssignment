#include "Cards.h"

using namespace std;

Card::Card()
{
}

Card::~Card()
{	
}


struct Good {
    //2 players cards(27)
    string ANCIENT_PHOENIX = "Ancient Phoenix";
    string ANCIENT_TREE_SPIRIT = "Ancient Tree Spirit";
    string CURSED_BANSHEE = "Cursed Banshee";
    string CURSED_KING = "Cursed King";
    string CURSED_TOWER = "Cursed Tower";
    string DIRE_EYE = "Dire Eye";
    string DIRE_GOBLIN = "Dire Goblin";
    string FOREST_ELF = "Forest Elf";
    string FOREST_PIXIE = "Forest Pixie";
    string GRAVEYARD = "Graveyard";
    string NIGHT_HYDRA = "Night Hydra";
    string NIGHT_WIZARD = "Night Wizard";
    string NOBLE_KNIGHT = "Noble Knight";
    string STRONGHOLD = "Stronghold";
    string ANCIENT_SAGE = "Ancient Sage";
    string ANCIENT_WOODS = "Ancient Woods";
    string CURSED_GARGOYLES = "Cursed Gargoyles";
    string CURSED_MAUSOLEUM = "Cursed Mausoleum";
    string DIRE_DRAGON = "Dire Dragon";
    string DIRE_GIANT = "Dire Giant";
    string DIRE_OGRE = "Dire Ogre";
    string FOREST_GNOME = "Forest Gnome";
    string FOREST_TREE_TOWN = "Forest Tree Town";
    string LAKE = "Lake";
    string NIGHT_VILLAGE = "Night Village";
    string NOBLE_HILLS = "Noble Hills";
    string NOBLE_UNICORN = "Noble Unicorn";
    //3 players cards(32)
    string ARCANE_MANTICORE = "Arcane Manticore";
    string ARCANE_TEMPLE = "Arcane Temple";
    string MOUNTAIN_TREASURY = "Mountain Treasury";
    string ARCANE_SPHINX = "Arcane Sphinx";
    string MOUNTAIN_DWARF = "Mountain Dwarf";
    //4 player cards(34)
    string CASTLE = "Castle";
    string CASTLE_2 = "Castle 2";
};
// All action on the card
struct Action {
        string MOVE_2_ARMY = "Move 2 army";
        string MOVE_3_ARMY = "Move 3 army";
        string MOVE_4_ARMY = "Move 4 army";
        string MOVE_5_ARMY = "Move 5 army";
        string MOVE_6_ARMY = "Move 6 army";
        string BUILD_CITY = "Build city";
        string ADD_1_ARMY = "Add 1 army";
        string ADD_2_ARMY = "Add 2 army";
        string ADD_3_ARMY = "Add 3 army";
        string ADD_4_ARMY = "Add 4 army";
        string DESTROY_1_ARMY = "Destroy 1 army";
};


//Constructor
Card::Card(string gd, string actn){
    good = gd;
    action[0] = actn;
}

Card::Card(string gd, string act1, string act2) {
    good = gd;
    action[0] = act1;
    action[1] = act2;
}

//Copy constructor
Card :: Card(const Card &c){
    good = c.good;
    action[0] = c.action[0];
     action[1] = c.action[1];
   
}

//Getters
string Card ::getGood(){
    return good;
}

string Card ::getAction1(){
    return action[0];
}

string Card ::getAction2(){
    return action[1];
}


void Card::printCard() {
    
    cout << "\tGood: "<< good<< endl;
    cout << "\tAction: " << action[0]<< endl;
    cout << "\tAction: " << action[1]<< endl; 
    
}
// toString Cards
ostream& operator<<(ostream& strm, const Card& card)
{
	return strm << "Good: " << card.good 
    << "\nAction(s): " << card.action[0] << "\n" 
    << card.action[1] << endl;
}

Card& Card::operator=(const Card& anotherCard)
{
    if (&anotherCard == this)
        return *this;

    good = anotherCard.good;
    
    action[0] = anotherCard.action[0];
   action[1] = anotherCard.action[1];

    return *this;
}



Deck::Deck() {
    //top of the card
    topCardptr = &cards[0];
}
//CopyConstructor
Deck::Deck(const Deck &d){
    topCardptr = d.topCardptr;
    for(int i=0;i<34;i++){
        cards[i] = d.cards[i];
    }
}
//Deconstructor
Deck :: ~Deck(){
    
    topCardptr = nullptr;
}
//Displays all deck
void Deck::printDeck() {
    for (int i = 0; i < 34; i++) {
        cout << "Card " << i + 1 << endl;
        cards[i].printCard();
        cout << endl;
    }
}
int Deck :: myRandomGenerator(int j) {
   return rand() % j;
}
//Shuffle the content of the whole array.
void Deck::shuffleDeck() {
    srand(time(0)); 
    shuffle(&cards[0], &cards[34], myRandomGenerator);
}
// topCardptr points to the top of the deck
//When a card is drawn the pointer topCard move to the next card.
//return the drawn card
Card *Deck::draw() {
    Card* card = topCardptr;
    topCardptr++;
    return card;
}

//Creates the whole deck
void Deck ::generateDeck() {
    Good gd;
    Action act;

    //each card with good and action
      cards[0] = Card(gd.ARCANE_SPHINX,  act.ADD_3_ARMY, act.MOVE_4_ARMY);
    cards[1] = Card(gd.ARCANE_MANTICORE,  act.ADD_4_ARMY, act.DESTROY_1_ARMY);
    cards[2] = Card(gd.ARCANE_TEMPLE,  act.MOVE_3_ARMY);
    cards[3] = Card(gd.ANCIENT_PHOENIX,  act.MOVE_5_ARMY);
    cards[4] = Card(gd.ANCIENT_TREE_SPIRIT, act.ADD_4_ARMY);
    cards[5] = Card(gd.ANCIENT_WOODS,  act.BUILD_CITY, act.ADD_1_ARMY);

    cards[6] = Card(gd.ANCIENT_SAGE , act.MOVE_3_ARMY);
    cards[7] = Card(gd.CURSED_BANSHEE,  act.MOVE_6_ARMY);
    cards[8] = Card(gd.CURSED_GARGOYLES,  act.MOVE_5_ARMY);
    cards[9] = Card(gd.CURSED_KING ,  act.ADD_3_ARMY,act.MOVE_4_ARMY);
    cards[10] = Card(gd.CURSED_MAUSOLEUM, act.BUILD_CITY);
    cards[11] = Card(gd.CURSED_TOWER,  act.BUILD_CITY);

    cards[12] = Card(gd.DIRE_DRAGON, act.ADD_3_ARMY,act.DESTROY_1_ARMY);
    cards[13] = Card(gd.DIRE_GIANT,  act.ADD_3_ARMY,act.DESTROY_1_ARMY);
    cards[14] = Card(gd.DIRE_EYE,  act.ADD_4_ARMY);
    cards[15] = Card(gd.DIRE_GOBLIN, act.MOVE_4_ARMY);
    cards[16] = Card(gd.DIRE_OGRE,  act.MOVE_2_ARMY);

    cards[17] = Card(gd.LAKE,  act.ADD_2_ARMY,act.MOVE_3_ARMY);
    cards[18] = Card(gd.FOREST_ELF,   act.ADD_3_ARMY,act.MOVE_2_ARMY);
    cards[19] = Card(gd.FOREST_GNOME, act.MOVE_2_ARMY);
    cards[20] = Card(gd.FOREST_TREE_TOWN ,  act.BUILD_CITY);
    cards[21] = Card(gd.GRAVEYARD,  act.ADD_2_ARMY);
    cards[22] = Card(gd.NOBLE_HILLS,  act.ADD_3_ARMY);

    cards[23] = Card(gd.NOBLE_KNIGHT,  act.ADD_4_ARMY, act.DESTROY_1_ARMY);
    cards[24] = Card(gd.NOBLE_UNICORN,  act.MOVE_4_ARMY, act.ADD_1_ARMY);
    cards[25] = Card(gd.NIGHT_HYDRA,  act.MOVE_4_ARMY,act.DESTROY_1_ARMY);
    cards[26] = Card(gd.NIGHT_VILLAGE,  act.BUILD_CITY);
    cards[27] = Card(gd.NIGHT_WIZARD,  act.ADD_4_ARMY, act.DESTROY_1_ARMY);
    cards[28] = Card(gd.MOUNTAIN_DWARF, act.ADD_2_ARMY, act.DESTROY_1_ARMY);

    cards[29] = Card(gd.MOUNTAIN_TREASURY,  act.MOVE_3_ARMY);
    cards[30] = Card(gd.CASTLE,  act.ADD_4_ARMY,act. BUILD_CITY);
    cards[31] = Card(gd.CASTLE_2,  act.MOVE_3_ARMY,act.BUILD_CITY);
    cards[32] = Card(gd.FOREST_PIXIE,  act.MOVE_4_ARMY);
    cards[33] = Card(gd.STRONGHOLD,  act.BUILD_CITY);

}
// toString Deck
ostream& operator<<(ostream& strm, const Deck& deck)
{
	return strm << "Deck has 34 cards";
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

    topCardptr = &cards[0];

    return *this;
       
} 

//hand

Hand::Hand(Deck* dk) {
    deck = dk;
 //Initializing the cards for the face-up cards by drawing from the deck
    for (int i = 0; i < 7; i++) {
        cards[i] = deck->draw();
    }
}

//CopyConstructor
Hand::Hand(const Hand &h){
    deck = new Deck(*(h.deck));
    for (int i = 0; i < 7; i++)
    {
        cards[i] = deck->draw();
    }
    
}
//Destructor
Hand::~Hand(){
    
    deck = nullptr;
}

//Returns the cost of a card depending on where the card is placed in the cards space
int Hand::getCardCost(int indexOfcard) {
         if (indexOfcard == 0) return 0;
    else if (indexOfcard == 1) return 1;
    else if (indexOfcard == 2) return 1;
    else if (indexOfcard == 3) return 2;
    else if (indexOfcard == 4) return 2;
    else if (indexOfcard == 5) return 3;
    else return -1;
  
}

//Shifts cards when a card is picked

void Hand::shiftCards(int index) {
    for (int i = index; i < 7; i++) {
        cards[i] = cards[i + 1];//cards are shift to the left
    }
}


//select the card from its position in the row
Card* Hand::exchange(int cardIndex) {

    int cost = getCardCost(cardIndex);
    

    Card* pickedCard = (cards[cardIndex]);
// shift cards to the left
    shiftCards(cardIndex);
// draw a new card from the deck

    cards[7] = deck->draw(); 
    return pickedCard;
}


//To be implemented
void Hand::printHand() {
    //get the goods for each card
    string goodCard[7];
    
    string action1[7];
    string action2[7];
    for(int i=0;i<7;i++){
        goodCard[i] = cards[i]->getGood();
action1[i] = cards[i]->getAction1();
 action2[i] = cards[i]->getAction2();

 cout << "\tGood: "<< goodCard[i]<< endl;
    cout << "\tAction1: " << action1[i]<< endl;
    cout << "\tAction2: " << action2[i]<< endl; 

    }
    
}

// toString Hand
ostream& operator<<(ostream& strm, const Hand& hand)
{
	return strm << "Hand have 7 cards to choose from";
}

Hand& Hand::operator=(const Hand& anotherHand)
{
    if (&anotherHand == this)
        return *this;

    if (anotherHand.deck)
    {
        deck = new Deck(*anotherHand.deck);

        for (int i = 0; i < 7; i++)
        {
            cards[i] = deck->draw();
        }
    }
    else
        deck = nullptr;
    
    return *this;
}
