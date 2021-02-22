#include "Cards.h"

using namespace std;

Card::Card()
{
}

Card::~Card()
{	
}


struct Good {
    string A_PHOENIX = "Ancient Phoenix";
    string AT_SPIRIT = "Ancient Tree Spirit";
    string C_BANSHEE = "Cursed Banshee";
    string C_KING = "Cursed King";
    string C_TOWER = "Cursed Tower";
    string D_EYE = "Dire Eye";
    string D_GOBLIN = "Dire Goblin";
    string F_ELF = "Forest Elf";
    string F_PIXIE = "Forest Pixie";
    string GRAVEYARD = "Graveyard";
    string N_HYDRA = "Night Hydra";
    string N_WIZARD = "Night Wizard";
    string N_KNIGHT = "Noble Knight";
    string STRONGHOLD = "Stronghold";
    string A_SAGE = "Ancient Sage";
    string A_WOODS = "Ancient Woods";
    string C_GARGOYLES = "Cursed Gargoyles";
    string C_MAUSOLEUM = "Cursed Mausoleum";
    string D_DRAGON = "Dire Dragon";
    string D_GIANT = "Dire Giant";
    string D_OGRE = "Dire Ogre";
    string F_GNOME = "Forest Gnome";
    string FT_TOWN = "Forest Tree Town";
    string LAKE = "Lake";
    string N_VILLAGE = "Night Village";
    string N_HILLS = "Noble Hills";
    string N_UNICORN = "Noble Unicorn";
    //3 players 
    string A_MANTICORE = "Arcane Manticore";
    string A_TEMPLE = "Arcane Temple";
    string M_TREASURY = "Mountain Treasury";
    string A_SPHINX = "Arcane Sphinx";
    string M_DWARF = "Mountain Dwarf";
    //4 player 
    string CASTLE = "Castle";
    string CASTLE_2 = "Castle 2";
};
//  action 
struct Action {
        string MOVE2 = "Move 2 army";
        string MOVE3 = "Move 3 army";
        string MOVE4 = "Move 4 army";
        string MOVE5 = "Move 5 army";
        string MOVE6 = "Move 6 army";
        string BUILD = "Build city";
        string ADD1 = "Add 1 army";
        string ADD2 = "Add 2 army";
        string ADD3 = "Add 3 army";
        string ADD4 = "Add 4 army";
        string DESTROY1 = "Destroy 1 army";
};


//Constructor
Card::Card(string gd, string act){
    good = gd;
    action[0] = act;
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
    
    cout << "Good: "<< good<< endl;
    cout << "Action 1: " << action[0]<< endl;
    cout << "Action 2: " << action[1]<< endl;  
}
// toString Cards
ostream& operator<<(ostream& strm, const Card& card)
{
	return strm << "Good: " << card.good 
    << "Action(s): " << card.action[0] << "\n" 
    << card.action[1] << endl;
}

Card& Card::operator=(const Card& another)
{
    if (&another == this)
        return *this;

    good = another.good;
    
    action[0] = another.action[0];
   action[1] = another.action[1];

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
        cout << "Card number: " << i + 1 << endl;
        cards[i].printCard();
        cout << endl;
    }
}

//Shuffle the content of the whole array.
//void Deck::shuffleDeck() {
   // srand(time(0)); 
   // shuffle(&cards[0], &cards[34], myRandomGenerator);
//}

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
      cards[0] = Card(gd.A_SPHINX,  act.ADD3, act.MOVE4);
    cards[1] = Card(gd.A_MANTICORE,  act.ADD4, act.DESTROY1);
    cards[2] = Card(gd.A_TEMPLE,  act.MOVE3);
    cards[3] = Card(gd.A_PHOENIX,  act.MOVE5);
    cards[4] = Card(gd.AT_SPIRIT, act.ADD4);
    cards[5] = Card(gd.A_WOODS,  act.BUILD, act.ADD1);

    cards[6] = Card(gd.A_SAGE , act.MOVE3);
    cards[7] = Card(gd.C_BANSHEE,  act.MOVE6);
    cards[8] = Card(gd.C_GARGOYLES,  act.MOVE5);
    cards[9] = Card(gd.C_KING ,  act.ADD3,act.MOVE4);
    cards[10] = Card(gd.C_MAUSOLEUM, act.BUILD);
    cards[11] = Card(gd.C_TOWER,  act.BUILD);

    cards[12] = Card(gd.D_DRAGON, act.ADD3,act.DESTROY1);
    cards[13] = Card(gd.D_GIANT,  act.ADD3,act.DESTROY1);
    cards[14] = Card(gd.D_EYE,  act.ADD4);
    cards[15] = Card(gd.D_GOBLIN, act.MOVE4);
    cards[16] = Card(gd.D_OGRE,  act.MOVE2);

    cards[17] = Card(gd.LAKE,  act.ADD2,act.MOVE3);
    cards[18] = Card(gd.F_ELF,   act.ADD3,act.MOVE2);
    cards[19] = Card(gd.F_GNOME, act.MOVE2);
    cards[20] = Card(gd.FT_TOWN ,  act.BUILD);
    cards[21] = Card(gd.GRAVEYARD,  act.ADD2);
    cards[22] = Card(gd.N_HILLS,  act.ADD3);

    cards[23] = Card(gd.N_KNIGHT,  act.ADD4, act.DESTROY1);
    cards[24] = Card(gd.N_UNICORN,  act.MOVE4, act.ADD1);
    cards[25] = Card(gd.N_HYDRA,  act.MOVE4,act.DESTROY1);
    cards[26] = Card(gd.N_VILLAGE,  act.BUILD);
    cards[27] = Card(gd.N_WIZARD,  act.ADD4, act.DESTROY1);
    cards[28] = Card(gd.M_DWARF, act.ADD2, act.DESTROY1);

    cards[29] = Card(gd.M_TREASURY,  act.MOVE3);
    cards[30] = Card(gd.CASTLE,  act.ADD4,act. BUILD);
    cards[31] = Card(gd.CASTLE_2,  act.MOVE3,act.BUILD);
    cards[32] = Card(gd.F_PIXIE,  act.MOVE4);
    cards[33] = Card(gd.STRONGHOLD,  act.BUILD);

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

//Returns the cost of a card according to  the place of card 
int Hand::getCardCost(int index) {
         if (index == 0) return 0;
    else if (index == 1) return 1;
    else if (index == 2) return 1;
    else if (index == 3) return 2;
    else if (index == 4) return 2;
    else if (index == 5) return 3;
    else return -1;
  
}

//Shifts cards left with the index number

void Hand::shiftCards(int index) {
    for (int i = index; i < 7; i++) {
        cards[i] = cards[i + 1];
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

//print the content of hand
void Hand::printHand() {
    //get the goods for each card
    string goodCard[7];
    
    string action1[7];
    string action2[7];
    for(int i=0;i<7;i++){
        goodCard[i] = cards[i]->getGood();
action1[i] = cards[i]->getAction1();
 action2[i] = cards[i]->getAction2();

 cout << "Good: "<< goodCard[i]<< endl;
    cout << "Action 1: " << action1[i]<< endl;
    cout << "Action 2: " << action2[i]<< endl; 

    }
    
}

// toString method
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
