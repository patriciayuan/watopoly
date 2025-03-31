module needleshall;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;

NeedlesHall::NeedlesHall(int pos, const string& name): 
    NonProperty(pos, name), distribution({1, 2, 3, 6, 3, 2, 1}), random(random_device{}()) {}

void NeedlesHall::landed(shared_ptr<Player>player) {
    addPlayer(player);
    cout << player->getName() << " has landed on Needles Hall" << endl;
    int amount = calcAmount();
    
    if (amount > 0) {
        player->addMoney(amount);
        cout << player->getName() << " gained " << amount << ", now has: " << player->getMoney() << endl;
    } else {
        amount *= -1;
        player->pay(amount);
        cout << player->getName() << " lost " << amount << ", now has: " << player->getMoney() << endl;
    }



}


int NeedlesHall::calcAmount() {
    static const array<int,8> amounts = {-200, -100, -50, 25, 50, 100, 200};
    int index = distribution(random);
    return amounts[index];
}











