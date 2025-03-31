module square;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

import player;

using namespace std;

Square::Square(int pos, const string& name): name(name), pos(pos) {}

// void Square::passOver(shared_ptr<Player>player){
//     cout << player->getName() << " passed " << name << endl; //testing purpose, delete later
//     if(name == "COLLECT OSAP"){
//         player->addBal(200);
//         cout << player->getName() << " collected 200$ from osap" << endl; //testing, delete later
//     }
// }


void Square::landed(std::shared_ptr<Player> player) {
    cout << player->getName() << " has landed on " << getPos();
    addPlayer(player);
}

const string& Square::getName() const { return name; } // may need to reconsider returning const ref

int Square::getPos() const { return pos - 1; }

// bool Square::isOwnable() const { return false; } //default not ownable, update later
// bool Square::isOwned() const { return false; } //default not owned, update later

// used for adding during set up, not move.
void Square::addPlayer(shared_ptr<Player> player) { onsquare.emplace_back(player); } 

// a move is called in game and uses removePlayer(Player) and landed(Player)

void Square::removePlayer(shared_ptr<Player> player) {
    for (auto it = onsquare.begin(); it != onsquare.end(); ++it) {
        if (*it == player) {
            onsquare.erase(it);
            break; // exit loop once removed
        }
    }
}

// for now, may be virtual method for each building and nproptery
// void Square::land(shared_ptr<Player> player) { 
//     // will notify 
//     addPlayer(player); // for now
// }

// returns a vector of player symbols currently on square
vector<char> Square::getPlayers() { 
    vector<char> symbols;
    for (auto & player : onsquare) {
        symbols.emplace_back(player->getSym());
    }
    return symbols;
}

vector<string> Square::printSquare() {
    vector<string> load;

    string name = getName();
    istringstream iss{name};
    string first, second, third;
    iss >> first >> second >> third;
    if (first.length() + second.length() < 7) {
        first += " ";
        first += second;
        second = third;
    }
    load.emplace_back(first);
    load.emplace_back(second);
    
    // load name 

    load.emplace_back(""); // middle empty space
    load.emplace_back(""); // will be used later when distinction is made
    // cout << "asaa11" << endl; 

    // load players
    string player1 = "", player2 = "";
    for (size_t i = 0; i < 4; i++) {
        // Top row players (0-3)
        if (i < onsquare.size() && onsquare[i]) {
            player1 += onsquare[i]->getSym();
        }
        
        // Bottom row players (4-7)
        size_t j = i + 4;
        if (j < onsquare.size() && onsquare[j]) {
            player2 += onsquare[j]->getSym();
        }
    }

    load.emplace_back(player1); 
    load.emplace_back(player2); 
    // cout << "asaa" << endl; 

    return load;

}


int Square::newpos(std::shared_ptr<Player>player, int newpos) {
    return getPos();
}

int Square::turn(std::shared_ptr<Player>player) { // deafult impl
    return 0;
}


