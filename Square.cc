export module square;


import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

import player;

export class Square {
    protected:
        // Board* const board;
        std::string name;
        int pos;
        std::vector<std::shared_ptr<Player>> onsquare; // need to keep track of the players on the square
    public:
        Square(int pos, const std::string& name);  //ctor
        virtual ~Square() = default;   //dtor
        virtual void landed(std::shared_ptr<Player> player); //action when player land on square
        // virtual void passOver(std::shared_ptr<Player> player); //action when player pass a square
        const std::string& getName() const;
        int getPos() const;   
        // virtual bool isOwnable() const; //return if the square is building or non-property
        // virtual bool isOwned() const; //return if the building is owned by a player or not

        // used for adding during set up, not move.
        void addPlayer(std::shared_ptr<Player> player);

        void removePlayer(std::shared_ptr<Player> player);

        // returns a vector of player symbols currently on square
        std::vector<char> getPlayers();

        // for now, may be virtual method for each building and nproptery
        void land(std::shared_ptr<Player> player);

        // sets up this to print
        std::vector<std::string> printSquare();


        virtual int newpos(std::shared_ptr<Player>player, int newpos);
        virtual int turn(std::shared_ptr<Player>player);
};



