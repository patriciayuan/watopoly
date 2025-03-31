module gototims;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;


GoToTims::GoToTims(int pos, const std::string& name): NonProperty(pos, name){}

void GoToTims::landed(shared_ptr<Player>player){
    cout << player->getName() << " was sent to the DC Tims Line" << endl;
}





