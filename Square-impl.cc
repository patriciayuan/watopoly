module square;
import <memory>;
import <iostream>;
import player;
import <string>;
using namespace std;

Square::square(Const string& name, int pos): name(name), pos(pos);{}
Square::passOver(shared_ptr<Player>player){
    cout << player->getName(); << " passed " << name << endl; //testing purpose, delete later
    if(name == "COLLECT OSAP"){
        player->addBal(200);
        cout << player->getName(); << " collected 200$ from osap" << endl; //testing, delete later
    }
}
const string& Square::getName()const{
    return name;
}
int Square::getPos(){
    return pos;
}
bool Square::isOwnable(){
    return false; //default not ownable, update later
}
bool Square::isOwned(){
    return false; //default not owned, update later
}
