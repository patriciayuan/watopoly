module slc;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;

SLC::SLC(int pos, const std::string& name): 
    NonProperty(pos, name), moveDistribution({3,4,4,3,4,4,1,1}), random(random_device{}()) {}

void SLC::landed(shared_ptr<Player>player) {
    addPlayer(player);
    cout << player->getName() << " has landed on SLC" << endl;
}


int SLC::newpos(shared_ptr<Player>player, int newpos) {
    cout << player->getName() << " has landed on SLC" << endl;
    static uniform_int_distribution<int> cupDistribution(1, 100);
    if (cupDistribution(random) == 1 && player->canGetTimsCup()) {
        player->addTimsCup();
        cout << player->getName() << " got a Roll Up the Rim cup" << endl;
        return -1;
    }
    int movement = calcMovement();
    int newPos = (newpos + movement + 40) % 40;
    string description = getMovement(movement);
    cout << player->getName()<< " was " << description << endl;
    if(movement == 6){  //dc tims line
        // player->sendToTims();
        cout << player->getName() << " has been sent to the DC Times Line" << endl;
        return 10;
    }else if(movement == 7){ //osap
        cout << player->getName() << " has been sent to Collect OSAP" << endl;
        player->addMoney(200);
        return 0;
    }
    return newPos;
}	



int SLC::calcMovement(){
    static const array<int,8> movements = {-3,-2,-1,1,2,3,0,0};
    int index = moveDistribution(random);
    return movements[index];
}

string SLC::getMovement(int movement) const{
    static const array<string, 8> description ={
        "moved back 3 positions",
        "moved back 2 positions",
        "moved back 1 position",
        "moved forward 1 position",
        "moved forward 2 positions",
        "moved forward 3 positions",
        "Go to DC Tims Line",
        "Go to Collect OSAP"
    };
    // static const array<int, 8> movementIndex = {0,1,2,3,4,5,6,7};
    // 0, 0 might need to change
    static const array<int, 8> movementIndex = {-3,-2,-1,1,2,3,0,0};
    for(size_t i = 0; i < movementIndex.size(); ++i){
        if(movementIndex[i] == movement){
            
            return description[i];
        }
    }
    return "No movement(bug)";
}
