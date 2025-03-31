module coopfee;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;

CoopFee::CoopFee(int pos, const string& name): NonProperty(pos, name){}


void CoopFee::landed(shared_ptr<Player> player){
    addPlayer(player);
    cout << player->getName() << " needs to pay coop fee." << endl;
    player->pay(150);
    cout << "paid 150, balance now: " << player->getMoney() << endl;
}




