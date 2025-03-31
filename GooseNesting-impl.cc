module goose;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;

GooseNesting::GooseNesting(int pos, const std::string& name): NonProperty(pos, name){}

void GooseNesting::landed(shared_ptr<Player>player){
    addPlayer(player);
    cout << player->getName() << " was attacked by a flock of geese." << endl;
}

