#include "bidding.h"
#include <iostream>
#include "BPlayer.h"
#include<vector>
using namespace std;

int main(){
    int numberOfPlayer = 0, coin = 0,bid = 0;
    string name = "";
    vector<BPlayer*> player;
    cout<< "How many players do you have ?"<< endl;
    cin >> numberOfPlayer;
    while (numberOfPlayer < 2 || numberOfPlayer > 4) {
        cout << "The value is not valid!" << endl;
        cin >> numberOfPlayer;
    } //check numbers of player
    
    if (numberOfPlayer == 4) 
        coin = 9;
    if (numberOfPlayer == 3) 
        coin = 11;
    if (numberOfPlayer == 2) 
        coin = 14;
    
    for (int i = 1; i <= numberOfPlayer; i++) {
        cout << i << " " << " name: " << endl;
        cin >> name;
        cout << "How much would you like to bid ? " << endl;
        cin>> bid;
        while(bid>coin||bid<0){
            cout << "the value is not correct, reenter! " << endl;
            cin>> bid;
        }
        BPlayer* p = new BPlayer(name, bid);
        p->setCoin(coin);
        player.push_back(p);
    }
    
    
    //Player *player1 = new Player("yudan", 3);
    //Player *player2 =new Player("yuwan", 4);
    //Player *player3 =new Player("yuHan", 3);
    //Player *player4 = new Player("yuluan", 6); 
    
    //player.push_back(player1);
    //player.push_back(player2);
    //player.push_back(player3);
    //player.push_back(player4);
    //for(int i = 0;i<player.size();i++){
        //cout <<" the result is :"<< player[i]->getName()<<  player[i]->getBidFacility()->getBid()  <<endl;
    //}
    cout <<" the winner is :"<< player[bidding::biddingFacility(player)]->getName() <<endl;
    return 0;
}
