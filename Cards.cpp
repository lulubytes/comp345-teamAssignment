#include <iostream>
#include <string>
#include "..\header\Cards.h"
#include "..\header\Player.h"
#include <filesystem>
using namespace std;




//Card**********************************
struct Good
{
	//2 players cards(26)
	string AN_P = "Ancient Phoenix";
	string AN_TS = "Ancient Tree Spirit";
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
//  action
struct Action
{
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
	string DES = "Destroy 1 army";
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
	string ITA = "Immune to attack";
	string P1P3 = "+1 VP per 3 coins";
	string P1VPF = "+1 VP per Forest card";
	string P1VPC = "+1 VP per Cursed card";
	string P1VPN = "+1 VP per Night card";
	string P5VP3 = "All three noble cards = 5 VP";
	string P3VP2 = "+3 If you have 2 Mountain cards";
	string P1VPD = "+1 VP per Dire card";
};
struct Andor {
	string SINGLE = " ";
	string OR = "OR";
	string AND = "AND";
};
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

Card::Card() {};
Card::~Card()
{};




Card::Card(const Card& other) 
{
	good = other.good;
	action[0] = other.action[0];
	action[1] = other.action[1];

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
string Card::getAndor() {
	return andor;
}

void Card::printCard()
{

	Andor comp;
	cout << "\tGood: " << good << endl;
	cout << "\tAbility: " << ability << endl;
	cout << "\tAction: " << action[0] << endl;
	if (andor != comp.SINGLE) {
		if (andor == comp.AND) cout << "\tAND" << endl;
		else if (andor == comp.OR)cout << "\tOR" << endl;
		cout << "\tAction: " << action[1];
	}
}


ostream& operator<<(ostream& output, const Card& other) 
{
	return output << "Good: " << other.good
		<< "Action(s): " << other.action[0] << "\n"
		<< other.action[1] << endl;
}

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

Deck::Deck()
{
	//top of the card
	topCardptr = &cards[0];
	numPlayer = 2;
}
 Deck::Deck(int nPlayer) {
        topCardptr = &cards[0];
        numPlayer = nPlayer;
    }


Deck::Deck(const Deck& other) 
{
	topCardptr = other.topCardptr;
	for (int i = 0; i < 34; i++)
	{
		cards[i] = other.cards[i];
	}

}

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


Deck ::~Deck()
{

	topCardptr = nullptr;
}


int Deck::getNumCards() {
	if (numPlayer == 2) return 26;
	if (numPlayer == 3) return 32;
	if (numPlayer == 4) return 34;
}

int Deck::myRandomGenerator(int j) {
	return rand() % j;
}

void Deck::shuffleDeck() {
	srand(time(0));
	std::shuffle(&cards[0], &cards[getNumCards()], myRandomGenerator);
}

//draw method
Card* Deck::draw()
{
	Card* card = topCardptr;
	topCardptr++;
	return card;
}

void Deck::generateDeck()
{
	Good gd;
	Action act;
	Andor ctype;
	Ability abt;

	//each card with good and 2 or 1 action
	cards[0] = Card(gd.PIXIE, ctype.SINGLE, act.MOVE4, abt.P1A);
	cards[1] = Card(gd.STRONGHOLD, ctype.SINGLE, act.BUILD, abt.P1VPD);
	cards[2] = Card(gd.AN_P, ctype.SINGLE, act.MOVE5, abt.FYLING);
	cards[3] = Card(gd.AN_TS, ctype.SINGLE, act.ADD4, abt.THRE);
	cards[4] = Card(gd.WOODS, ctype.AND, act.BUILD, act.ADD1, abt.P1A);
	cards[5] = Card(gd.SAGE, ctype.SINGLE, act.MOVE3, abt.P1VP);
	cards[6] = Card(gd.CB, ctype.SINGLE, act.MOVE6, abt.TE);
	cards[7] = Card(gd.GAR, ctype.SINGLE, act.MOVE5, abt.FYLING);
	cards[8] = Card(gd.KING, ctype.OR, act.ADD3, act.MOVE4, abt.OE);
	cards[9] = Card(gd.MAUSOLEUM, ctype.SINGLE, act.BUILD, abt.P1M);
	cards[10] = Card(gd.TOWER, ctype.SINGLE, act.BUILD, abt.P1VPF);
	cards[11] = Card(gd.DRAGON, ctype.AND, act.ADD3, act.DES, abt.FYLING);
	cards[12] = Card(gd.GIANT, ctype.AND, act.ADD3, act.DES, abt.ITA);
	cards[13] = Card(gd.EYE, ctype.SINGLE, act.ADD4, abt.FYLING);
	cards[14] = Card(gd.GOB, ctype.SINGLE, act.MOVE4, abt.OE);

	cards[15] = Card(gd.OGRE, ctype.SINGLE, act.MOVE2, abt.P1P3);
	cards[16] = Card(gd.LAKE, ctype.OR, act.ADD2, act.MOVE3, abt.P1VPF);
	cards[16] = Card(gd.ELF, ctype.OR, act.ADD3, act.MOVE2, abt.P1A);
	cards[18] = Card(gd.GNOME, ctype.SINGLE, act.MOVE2, abt.THRE);
	cards[19] = Card(gd.TOWN, ctype.SINGLE, act.BUILD, abt.P1M);
	cards[20] = Card(gd.GRAVEYARD, ctype.SINGLE, act.ADD2, abt.P1VPC);
	cards[21] = Card(gd.HILLS, ctype.SINGLE, act.ADD3, abt.P5VP3);
	cards[22] = Card(gd.KNIGHT, ctype.AND, act.ADD4, act.DES, abt.P1M);
	cards[23] = Card(gd.UNICORN, ctype.AND, act.MOVE4, act.ADD1, abt.P1M);
	cards[24] = Card(gd.HYDRA, ctype.AND, act.MOVE4, act.DES, abt.P1A);
	cards[25] = Card(gd.VILLAGE, ctype.SINGLE, act.BUILD, abt.P1A);
	cards[26] = Card(gd.WIZARD, ctype.AND, act.ADD4, act.DES, abt.P1VPN);

	//3 Player cards
	if (Deck::numPlayer >= 3) {
		cards[26] = Card(gd.SPHINX, ctype.OR, act.ADD3, act.MOVE4, abt.FYLING);// 3 Player
		cards[28] = Card(gd.MANTI, ctype.AND, act.ADD4, act.DES, abt.P1M);//3 Player
		cards[29] = Card(gd.TEMPLE, ctype.SINGLE, act.MOVE3, abt.P1AR);// 3Player
		cards[30] = Card(gd.DWARF, ctype.AND, act.ADD2, act.DES, abt.P3VP2);//3 Player
		cards[31] = Card(gd.TREASURY, ctype.SINGLE, act.MOVE3, abt.OA2C);// 3 Player
	}
	//4 Player cards
	if (Deck::numPlayer >= 4) {
		cards[32] = Card(gd.CASTLE, ctype.OR, act.ADD4, act.BUILD, abt.OE);//4 player 
		cards[33] = Card(gd.CASTLE2, ctype.AND, act.MOVE3, act.BUILD, abt.OE);//4 Player
	}
}
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


Hand::Hand(const Hand& h)
{
	deck = new Deck(*(h.deck));
	for (int i = 0; i < 6; i++)
	{
		cards[i] = deck->draw();
	}
}
Hand::Hand() {}
Hand::~Hand() {
	//deck is not dynamically allocated pointer therefore, no need to delete it
	deck = nullptr;
}

//Returns the cost of a card 
int Hand::getCardCost(int index)
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


ostream& operator<<(ostream& strm, const Hand& hand)
{
	return strm << "Hand have 6 cards to choose from";
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

//Shifts cards left with the index number
void Hand::shiftCards(int index)
{
	for (int i = index; i < 6; i++)
	{
		cards[i] = cards[i + 1];
	}
}

//select the card from its position in the row


Card* Hand::exchange(int cardIndex, Player* player) {

	int cost = getCardCost(cardIndex);
	//  if (!player->payCoin(cost)) return nullptr;

	Card* pickedCard = (cards[cardIndex]);// save picked card

	shiftCards(cardIndex);// shift cards to the left

	cards[5] = deck->draw(); // draw a new card from the deck

	return pickedCard;
}

//vector<Card*> Hand::GetHand() 
//{
//	return cards;
//}
