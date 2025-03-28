module building;
import <memory>;
import <stdexcept>;
import <iostream>;
import player;
using namespace std;
Building::Building(const string &name, int pos, int cost)
    :Square(name, post), cost(cost),isMortaged(false){}
void Building::landed(shared_ptr<Player>player){
    if(isMortaged){
        cout << player->getName() << " landed on mortaged " << name << ", so nothing happens" << endl; //testing, delete later
        return;
    }
    if(auto ownerPtr = owner.lock()){
        if(ownerPtr == player){
            cout << player->getName() << " landed on their own property: " << name << endl
        }else{
            int tuition = calcTuition(player);
            cout << player->getName() << " pays" << tuition << " to " <<ownerptr->getName() << endl;
            player->tranferBal(ownerPtr, tuition);
        }
    }else{
        cout<< player->getName() << " landed on unowned " << name << ", cost:$ " << cost <<endl;
        //complete later 
    }
}
void Building::mortage(){
    if(isMortgaged) throw runtime_error("already mortaged");
    if(auto ownerPtr = owner.lock()){
        ownerPtr->addBal(cost/2);
        isMortaged = true;
    }else{
        throw runtime_error("cannot mortaged unowned property");
    }
}
void Building::unmortage(){
    if(!isMortaged) throw runtime_error("this building is not mortaged");
    if(auto ownerPtr = owner.lock()){
        ownerPtr->payBal(static_cast<int>(cost * 0.6));
        isMortgaged = false;
    }else{
        throw runtime_error("Cannot unmortage, ur not the owner");
    }
}
bool Building::isOwned() const {
    return !owner.expired();
}

int Building::getPurchaseCost() const {
    return purchaseCost;
}

bool Building::getIsMortgaged() const {
    return isMortgaged;
}

shared_ptr<Player> Building::getOwner() const {
    return owner.lock();
}