#include <string>
#include <iostream>

class bidding;
using namespace std;


class BPlayer{
    private:
        string name = "";
        int coin = 10;
        bidding* bidFaci;
    
    public:
        BPlayer(string aName, int coinNum);
        string getName();
        int getCoins();
        bidding* getBidFacility();
        void PayCoin(int i);
        void setCoin(int i);
};
