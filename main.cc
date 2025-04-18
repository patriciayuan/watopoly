import <iostream>;
import <iomanip>;
import <random>;  
import <fstream>;     
import <sstream>;     
import <vector>;      
import <map>;         
import <memory>;      
import <string>;      

import player;
import square;
import board;
import game;


using namespace std;

int main(int argc, char * argv[]) {
    // "-load "filename"
    // create game, which will create a board
    // run through each command: roll, next, improve, mortgage, unmortgage, bankrupt, assets, all, save
    // need to save to file and save games.

    auto game = make_unique<Game>();

    // if (argc >= 2 && std::string(argv[1]) == "-load") {
    //     ifstream ifs{argv[2]};
    //     auto game = make_unique<Game>(ifs);
    // } 


    string command;
    string name, give, receive, property;
    string filename;

    while(cin >> command) {

        if (command == "roll") {
            game->move();

        } else if (command == "next") {
            game->next();

        } else if (command == "trade") { //
            // trade between curr and name
            // give and receive cannot both be money
            cin >> name >> give >> receive;

        } else if (command == "improve") { //
            cin >> property;

        } else if (command == "mortgage") { //
            cin >> property;

        } else if (command == "unmortgage") { //
            cin >> property;

        } else if (command == "bankrupt") {
            // this is a choice
            if (game->kill(game->getCurrent())) {
                cout << "kill successful";
            } else {
                cout << "live.";
            }
            

        } else if (command == "assets") {
            // does not work if the player is deciding how to pay tuition
            // game->getAssets(game->getCurrent());
        } else if (command == "all") {
            // does not work if a player is deciding how to pay tuition
            // game->getAssets();
        } else if (command == "save") {
            cin >> filename;
            // game->save(filename);

        } else if (command == "print") {
            game->print();
        } else if (command == "players") {
            game->getPlayerInfo();
        }
    }



}













