module building;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

using namespace std;

Building::Building(int pos, const string& name) : Square{pos, name}, owned{false} {}

void Building::landed(std::shared_ptr<Player> player) {
    cout << "building ";
    cout << player->getName() << " has landed on " << getPos() << endl;
    addPlayer(player);
}


void Building::bought(shared_ptr<Player> player) {
    owner = player;
    owned = true;
    player->addAsset(getPos());

}

bool Building::isOwned() const {
    return owned;
}

std::shared_ptr<Player> Building::getOwner() const {
    return owner;
}


void Building::setOwner(std::shared_ptr<Player> player) {
    changeOwner(player);
    changeIsOwned(true);
}

void Building::changeOwner(std::shared_ptr<Player> player) {
    owner = player;
}

void Building::changeIsOwned(bool isOwned) {
    owned = isOwned;
}

