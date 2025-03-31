module residence;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

using namespace std;

int Residence::resOwned = 0;

Residence::Residence(int pos, const string& name) : Building{pos, name}, cost{200} {}

void Residence::landed(shared_ptr<Player> player) {
    cout << player->getName() << " has landed on " << getName() << endl;
    addPlayer(player);
    if (isOwned()) {
        if (player != getOwner()) {
            player->pay(getRent());
            getOwner()->addMoney(getRent());
            cout << player->getName() << " has paid " << getOwner()->getName() << " rent: " << getRent() << endl;
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
                addResOwned();
                cout << player->getName() << " now owns " << getName() << endl;
            } else {
               cout << "    did not purchase"; 
            }
        } else {
            cout << "you cannot buy, go away" << endl;
        }
    }



}

int Residence::getRent() const {
    return 50 * resOwned;
}

int Residence::getCost() const {
    return cost;
}

void Residence::addResOwned() {
    resOwned++;
}


