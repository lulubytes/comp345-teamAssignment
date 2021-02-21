#include <vector>
#include "Player.h"

using namespace std;

class bidding {

private:
    int *bid ;


public:
    // Constructor
    bidding(int bid);

    //Copy constructor
    bidding(const bidding &bf);
    
    //Destructor
    ~bidding();

    //bid
    void biddingFacility(vector<Player*> &player);
    
    //get bid value
    int getBid();

    //set bid value
    void setBid(int bid);

    //assignment operator
    bidding& operator= (const bidding& bidding);

};
