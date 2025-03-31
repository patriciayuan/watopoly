export module dice;

import <random>;
import <array>;


export class Dice {

        std::discrete_distribution<int> distribution;
        std::mt19937 random;

    public:
        Dice();
        int roll();


};

