#include<vector>
#include <iostream>
#include "bidding.h"
#include "Player.h"

using namespace std;

//constructor
bidding::bidding(int bid) {
    this->bid = &bid;
}

//deep copy constructor
bidding::bidding(const bidding &bf) {
    this->bid = new int (*bf.bid);
}

// Destructor
bidding::~bidding() {
    if (this->bid!=NULL) {
        delete bid;
        bid = NULL;
    }
}

void bidding:: biddingFacility(vector<Player*> &players){
    string winner = "";
    int bid, highestBid = 0, index = 0 ;
    
    for(int i = 0;i<players.size();i++){
            cout << players[i]->getName() << ": how much would you like to pay?" << endl;
            cin >> bid;
            while (bid < 0 || bid > players[i]->getCoins()) {
                cout << "This amount is not valid! "<<endl;
                cin >> bid;
            }
                players[i]->getBidFacility()->setBid(bid);
        
        //if the player pointer is pointer to null then skip
    }//let players bid 

    for(int i = 1;i<players.size();i++){
        highestBid =  players[0]->getBidFacility()->getBid();
        
            if( players[i]->getBidFacility()->getBid()>highestBid){
                highestBid=players[i]->getBidFacility()->getBid();
                index= i;
                winner = players[index]->getName();
            }
        //find the largest one and mark the index    
    }   
    
    for(int i = 1;i<players.size();i++){
        
            if( players[i]->getBidFacility()->getBid()==highestBid&&players[i]->getName().compare(players[index]->getName())<0){
                highestBid=players[i]->getBidFacility()->getBid();
                index= i;
                winner = players[index]->getName();
            }
        //if bidding is equal to 0 or euqal to some players bidding, it will compare their last name and change the winner    
    }   

    cout << "The winner is :"<<players[index]->getName()<<endl;
    players[index]->PayCoin(highestBid);//show the winner and pay his coin
}

//get the bid value
int bidding::getBid(){
    return *bid;
}

//set the bid value
void bidding::setBid(int bid) {
    this->bid = &bid;
}

//assign operator
 bidding& bidding::operator= (const bidding& bidding){
    if (&bidding == this)
        return *this;
    else{
        this->bid = NULL;
        this->bid = new int(*bidding.bid);
    }
    return *this;
 }
