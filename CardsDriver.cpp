#include <iostream>
#include "..\header\Cards.h"

using namespace std;

class CardsDriver
{
    public:
    void run()
    {
        Deck *deck = new Deck();

        Card *card1 = new Card("card1", "good1", "action1");
        deck->SetDeck(card1);

        cout << "deck set done, total cards: " << deck->GetDeck().size() << endl;

        Hand *hand = new Hand();
        hand->SetHand(deck->draw());
        cout << "deck draw, total cards:" << deck->GetDeck().size() << endl;
        cout << "hand setup done, total cards:" << hand->GetHand().size() << endl;
    }
};