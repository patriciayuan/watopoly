



import <string>;


using namespace std;

class Player {
        string name;
        char symbol;
        bool turn;
        int balance;
        int pos;
        <vector<Improvements>> improvements;
        <vector<Building>> assets;


    public:
        int getPos();
        void setPost();
        int getBal();
        void addBal(int);
        void payBal(int);
        string getName();
        char getPiece();
        Bool ownsProperty(Building *);
        void addProperty(Building *);
        void removeProperty(Building *);
        void transferBal(Player *, int);
        void move(int);
        void sendToTimes();
        void releaseFromTims();
        <vector<Building>> getAssets();
        <vector<Improvements>> improvements();
        void kill();



};











