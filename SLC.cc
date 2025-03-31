export module slc;

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

export class SLC : public NonProperty{
    std::discrete_distribution<int> moveDistribution;
    std::mt19937 random;
    public:
        SLC(int pos, const std::string& name);
        void landed(std::shared_ptr<Player>player) override;
        int newpos(std::shared_ptr<Player>player, int newpos) override;
    private:
        int calcMovement();
        std::string getMovement(int movement) const;
};

