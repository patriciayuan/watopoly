export module residence;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

import player;
import building;

// class Board;
export class Residence : public Building {
        static int resOwned;
        int cost;


    public:
        Residence(int pos, const std::string& name);
        void landed(std::shared_ptr<Player> player) override;
        int getRent() const;
        int getCost() const;
        void addResOwned();

        

};





