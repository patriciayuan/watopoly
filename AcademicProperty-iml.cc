module academic;

import building;
import player;
import <vector>;
import <memory>;
import <iostream>;
import <stdexcept>;
import <string>;
using namespace std;

AcademicProperty::AcademicProperty(const string& name, int pos, int purchaseCost, int improvementCost,
                                   const vector<int>& tuition)
    : Building(name, pos, purchaseCost), improvementCost(improvementCost), improvements(0),
      tuition(tuition) {}


void AcademicProperty::landed(shared_ptr<Player>player){
    if(getIsMortgaged()){ // landed on mortaged building, does nothing
        cout << player->getName(); << " landed on mortaged building" << getName() << endl;
        return;
    }
    if(auto ownerPtr = getOwner()){ // if building is owned
        if (ownerPtr = player){ //if landed on own building, does nothing
            cout << player->getName() << " landed on their own building " << getName() << endl;
            return;
        }else{ // building is owned by another player, will now pay tuition to that player
            int tuition = calcTuition(player);
            player->payToPlayer(owner, tuition);
            cout << player->getName(); << " payed $" << tuition << " for landing on " << getName() << endl;
        }
    }else{ //building is unowned
        if(player->getBal() < getCost()){ //if player cant afford building
            cout<< player->getName() <<" have landed on unowned " << getName() 
            << ", but you don't have enough money to purchase it, it will now be auctioned." << endl;
        }else{ //if player can afford
            cout << player->getName() << " landed on unowned building " << getName() 
            << ". Input 1 if you'd like to purchase it, Input anything else if you don't want to purchase it" << endl;
            int input;
            cin >> input;
            if(input == 1){
                purchase(player);
            }else{
                cout << getName() << " will now be auctioned." << endl;
                //auction, implement later
            }
        }
    }
}
void AcademicProperty::purchase(shared_ptr<Player> player) {
    if (getOwner()) {
        throw runtime_error(getName() + " is already owned");
    }
    int price = getCost();
    if(player->getBal() < price){
        throw runtime_error(player->getName() + " can't afford " + getName());
    }
    player->pay(price);
    setOwner(player);
    player->addProperty(getName());
    cout << player->getName() << " purcahsed " << getName() << endl;
}