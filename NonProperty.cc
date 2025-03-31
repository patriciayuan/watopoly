export module nonproperty;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


import player;
import square;
// import board;

// class Board;
export class NonProperty: public Square {

        // std::shared_ptr<Board> board;
        std::shared_ptr<Player> owner;


    public:

        NonProperty(int pos, const std::string& name);
        virtual void landed(std::shared_ptr<Player> player) override;
        virtual int newpos(std::shared_ptr<Player>player, int newpos) override;
        virtual int turn(std::shared_ptr<Player>player) override;
    

};








