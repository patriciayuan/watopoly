module osap;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;

CollectOSAP::CollectOSAP(int pos, const string& name): NonProperty(pos, name){}

void CollectOSAP::landed(shared_ptr<Player>player){
    addPlayer(player);
    cout << player->getName() << " has landed on collect OSAP, nothing happens" << endl;
}






