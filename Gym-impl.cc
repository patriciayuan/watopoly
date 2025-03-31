module gym;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

using namespace std;

int Gym::gymsOwned = 0;

Gym::Gym(int pos, const std::string& name) : Building{pos, name} , cost{150} {
    dice.emplace_back(make_unique<Dice>());
    dice.emplace_back(make_unique<Dice>());
}

int Gym::roll() {
    int rolled = dice[0]->roll() + dice[1]->roll();
    cout << "dice rolled, result: " << rolled << endl;
    return rolled;
}


void Gym::landed(std::shared_ptr<Player> player) {
    cout << player->getName() << " has landed on " << getName() << endl;
    addPlayer(player);
    if (isOwned()) {
        if (player != getOwner()) {
            int fees = getFees();
            player->pay(fees);
            getOwner()->addMoney(fees);
            cout << player->getName() << " has paid " << getOwner()->getName() << " fees: " << fees << endl;
        }
    } else { // not owned
        if (player->getMoney() >= getCost()) {
            int choice;
            cout << "would you like to purchase " << getName() << endl;
            cout << "   1 to buy, 2 no" << endl;
            cin >> choice;
            if (choice == 1) {
                bought(player);
                player->pay(getCost());
                addGymsOwned();
                cout << player->getName() << " now owns " << getName() << endl;
            } else {
               cout << "    did not purchase"; 
            }
        } else {
            cout << "you cannot buy, go away" << endl;
        }
    }



}



int Gym::getFees() {
    int fees;

    if (gymsOwned == 1) {
        fees = 4 * roll();
    } else if (gymsOwned == 2) {
        fees = 10 * roll();
    }

    return fees;
}

void Gym::addGymsOwned() {
    gymsOwned++;
}


int Gym::getCost() const {
    return cost;
}



