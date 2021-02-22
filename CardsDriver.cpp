#include "Cards.h"



//the main method is to test the Cards of part 5;
int main() {

    // create a deck
    Deck* deck = new Deck();

    // generate the cards
    deck->generateDeck();
    cout << "Initial Deck\n" << endl;
    deck->printDeck();

    // shuffle the deck
    deck->shuffleDeck();
    cout << "Shuffled Deck\n" << endl;
    deck->printDeck();


    cout << "Card Space\n" << endl;
    
    Hand* hand = new Hand(deck);
   
    //Testing exchange method
    
    int index = 0;
    while (index >= 0) {
        hand->printHand();
        cout << "Enter index number";
        cin >> index;
        hand->exchange(index);
    }

    // Deallocating heap.
    if (hand)
        delete hand;
    hand = nullptr;
    if (deck)
        delete deck;
    deck = nullptr;
return 0;
    
}