module dice;

import <random>;
import <array>;
import <iostream>;

using namespace std;


Dice::Dice() : distribution({1, 1, 1, 1, 1, 1}), random(random_device{}()) {}

int Dice::roll() {
    static const array<int, 6> value = {1, 2, 3, 4, 5, 6};
    int index = distribution(random);
    return value[index];
}


