module nonproperty;
import square;
import player;
import <memory>;
import <iostream>;
import <string>;
using namespace std;
NonProperty::NonProperty(const string& name, int pos): Square(name, pos){}

CollectOSAP::CollectOSAP(int pos): NonProperty("COLLECT OSAP", pos){}

void CollectOSAP::landed(shared_ptr<Player>player){
    player->addMoney(200);
}

DCTimsLine::DCTimsLine(int pos): NonProperty("DC TIMS LINE", pos){}

void DCTimsLine::landed(shared_ptr<Player>player){
    return;
}

GoToTims::GoToTims(int pos): NonProperty("GO TO TIMS", pos){}
void GoToTims::landed(shared_ptr<Player>player){
    cout << "you are now being sent to tims line" << endl;
    player->sendToTims();
}

GooseNesting::GooseNesting(int pos): NonProperty("GOOSE NESTING", pos){}
void GooseNesting::landed(shared_ptr<Player>player){
    cout << player->getName() << " was attacked by a flock of geese." << endl;
}

Tuition::Tuition(int pos): NonProperty("TUITION", pos){}
void Tuition::landed(shared_ptr<Player>player){
    cout << player->getName() << " time to pay tuition."<< endl;
    cout << " choose payment method:" << endl << " input 1 to pay 300$" << endl
         << " input 2 to pay 10% of your total assets" << endl;
    int method1 = 300;
    int method2 = player->totalAsset / 10;
    int choice;
    while(true){
        cin >> choice;
        if(choice == 1){
            player->payMoney(method1);
            break;
        }else if(choice == 2){
            player->payMoney(method2);
            break;
        }
        cout << "Invalid method, must enter 1 or 2" << endl;
    }   
}

CoopFee::CoopFee(int pos): NonProperty("COOP FEE", pos){}
void CoopFee::landed(shared_ptr<Player>player){
    player->payMoney(150);
}

SLC::SLC(int pos): 
    NonProperty("SLC", pos),random(random_device{}()),moveDistribution({3,4,4,3,4,4,1,1}){}

int SLC::landed(shared_ptr<Player>player){
    static uniform_int_distribution<int> cupDistribution(1, 100);
    if (cupDistribution(random) == 1 && player->canGetTimsCup()) {
        player->addTimsCup();
        cout << player->getName() << " got a Roll Up the Rim cup" << endl;
        return -1;
    }
    int movement = calcMovement();
    int newPos = (player->getPos() + movement + 40) % 40;
    string description = getMovement(movement);
    out << description << endl;
    if(movement == 6){  //dc tims line
        player->sendToTims();
        return 11;
    }else if(movement == 7){ //osap
        player->addMoney(200);
        return 1;
    }
    return newPos;
}	

int SLC::calcMovement(){
    static const array<int,8> movements = {-3,-2,-1,1,2,3,0,0};
    int index = movementDistribution(random);
    return movements[index];
}
string SLC::getMovement(int movement) const{
    static const array<string, 8> description ={
        "Move back 3 position",
        "Move back 2 position",
        "Move back 1 position",
        "Move forward 1 position",
        "Move forward 2 position",
        "Move forward 3 position",
        "Go to DC Tims Line",
        "Go to Collect OSAP"
    };
    static const array<int, 8> movementIndex = {0,1,2,3,4,5,6,7};
    for(size_t i=0; i<movementIndex.size(); ++i){
        if(movementIndex[i] == movement){
            return description[i];
        }
    }
    return "No movement(bug)";
}
