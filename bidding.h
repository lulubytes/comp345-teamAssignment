#include <vector>

using namespace std;

class BPlayer;

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
    static int  biddingFacility(vector<BPlayer*> &players);
    
    //get bid value
    int getBid();

    //set bid value
    void setBid(int bid);

    //assignment operator
    bidding& operator= (const bidding& bidding);

};
