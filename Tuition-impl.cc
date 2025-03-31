module tuition;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;

Tuition::Tuition(int pos, const string& name): NonProperty(pos, name){}


void Tuition::landed(shared_ptr<Player>player) {
    addPlayer(player);
    cout << player->getName() << ", time to pay tuition."<< endl;
    cout << " choose payment method:" << endl << " input 1 to pay 300$" << endl
         << " input 2 to pay 10% of your total assets" << endl;
    int method1 = 300;
    int method2 = player->getAssets() / 10;
    int choice;
    while(true){
        cin >> choice;
        if(choice == 1){
            player->pay(method1);
            cout << "paid " << method1 << " balance now: " << player->getMoney() << endl;
            break;
        }else if(choice == 2){
            player->pay(method2);
            cout << "paid " << method2 << " balance now: " << player->getMoney() << endl;
            break;
        }
        cout << "Invalid method, must enter 1 or 2" << endl;
    }   
}




