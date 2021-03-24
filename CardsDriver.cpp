#include <iostream>
#include "..\header\Cards.h"

using namespace std;

class CardsDriver
{
    public:
    void run()
    {
       // Player* player = new Player();
        // create a deck
        Deck* deck = new Deck(2);

        // print cards information
        deck->generateDeck();
        cout << "Deck Object\n" << endl;
      //  deck->printDeck();

        deck->shuffleDeck();
      //  deck->printDeck();


        cout << "Hand card information\n" << endl;

        Hand* hand = new Hand(deck);

        //Testing exchange method
        int coins = 8;
        int index = 0;
        while (index >= 0) {
       //     hand->printHand();
            cout << "Choose an index number \n";
            cin >> index;
         //   hand->exchange(index, player);
            cout << "After exchange: \n" << endl;
        }
    }
};