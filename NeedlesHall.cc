export module needleshall;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <random>;
import <array>;
import <string>;


import player;
import square;
import nonproperty;


export class NeedlesHall : public NonProperty {
        std::discrete_distribution<int> distribution;
        std::mt19937 random;
    public:
        NeedlesHall(int pos, const std::string& name);
        void landed(std::shared_ptr<Player>player) override;
        int calcAmount();
};



