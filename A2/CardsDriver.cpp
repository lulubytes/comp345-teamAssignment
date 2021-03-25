
#include "..\header\Cards.h"


class CardsDriver
{
public:
    void run()
    {


        Deck* deck = new Deck(2);

        // print cards information
        deck->generateDeck();
        cout << "Deck Object\n" << endl;
        deck->printDeck();

        deck->shuffleDeck();
        deck->printDeck();
        cout << "Hand card information\n" << endl;
        Hand* hand = new Hand(deck);
        int index = 0;
      
            hand->printHand();
            cout << "Choose an index number \n";
            cin >> index;      
            cout << "After exchange: \n" << endl;
            hand->exchange(index);
            hand->printHand();
    }
};