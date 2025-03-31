export module tuition;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


import player;
import square;
import nonproperty;



export class Tuition: public NonProperty{
    public:
        Tuition(int pos, const std::string& name);
        void landed(std::shared_ptr<Player>player) override;
};




