export module building;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


import player;
import square;
// import board;

// class Board;
export class Building : public Square {

        std::shared_ptr<Player> owner;
        bool owned;


    public:
        Building(int pos, const std::string& name);
        virtual void landed(std::shared_ptr<Player> player);
        virtual void bought(std::shared_ptr<Player> player);
        // bool Square::isOwnable() const;
        bool isOwned() const;
        void changeOwner(std::shared_ptr<Player> player);
        void changeIsOwned(bool isOwned);
        std::shared_ptr<Player> getOwner() const;
        void setOwner(std::shared_ptr<Player> player);

    

};













