export module square;
import <memory>;
import <iostream>;
import <string>;


class Board;
class Player;
using namespace std;
export class Square {
    protected:
        string name;
        int pos;
        vector<shared_ptr<Player>> onsquare; // need to keep track of the players on the square
    public:
        Square(const string& name, int pos);  //ctor
        virtual ~Square();   //dtor
        virtual void landed(shared_ptr<Player> player) = 0; //action when player land on square
        virtual void passOver(shared_ptr<Player> player); //action when player pass a square
        const string& getName() const;
        int getPos() const;   
        virtual bool isOwnable() const; //return if the square is building or non-property
        virtual bool isOwned() const; //return if the building is owned by a player or not
        

        
        // used for adding during set up, not move.
        void addPlayer(shared_ptr<Player> player);

        void removePlayer(shared_ptr<Player> player);

        // returns a vector of player symbols currently on square
        vector<char> getPlayers();

        // for now, may be virtual method for each building and nproptery
        void land(shared_ptr<Player> player);
};



