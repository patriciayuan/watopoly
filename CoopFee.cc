export module coopfee;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


import player;
import square;
import nonproperty;


export class CoopFee : public NonProperty{
    public:
        CoopFee(int pos, const std::string& name);
        void landed(std::shared_ptr<Player>player) override;
};








