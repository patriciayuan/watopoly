module nonproperty;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

using namespace std;

NonProperty::NonProperty(int pos, const string& name) : Square{pos, name} {}

void NonProperty::landed(std::shared_ptr<Player> player) {
    cout << "nonproperty";
    cout << player->getName() << " has landed on " << getPos() << endl;
    addPlayer(player);
}

int NonProperty::newpos(std::shared_ptr<Player>player, int newpos) { return getPos(); }
int NonProperty::turn(std::shared_ptr<Player>player) { return 0; }


