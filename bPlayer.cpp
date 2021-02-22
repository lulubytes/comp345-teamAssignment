#include "BPlayer.h"
#include "bidding.h"
    
    
    
    BPlayer::BPlayer(string aName, int coin)
    {
	    name = aName;
	    bidFaci = new bidding(coin);
    }//constructor
    
    string  BPlayer:: getName(){
        return name;
    }//get name
    
    int BPlayer::getCoins(){
        return coin;
    }//get coin
    
    bidding*  BPlayer:: getBidFacility(){
        return bidFaci;
    }//get bid object
    
    void BPlayer:: PayCoin(int i){
        this->coin-=i;
    }//pay coin

    void BPlayer:: setCoin(int i){
        this->coin = i;
    }//set coin
