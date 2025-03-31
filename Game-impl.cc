module game;

import <iostream>;
import <vector>;
import <memory>;
import <string>;

using namespace std;

shared_ptr<Player> Game::readPlayer(const string& in) {
    istringstream stream{in};
    string name;
    char symbol;
    int timsCups = 0, money = 0, pos = 0, placeInLine = -1, turnsInLine = -1;

    stream >> name >> symbol;
    auto player = make_shared<Player>(name, symbol);

    // if (stream) {
    //     stream >> timsCups >> money >> pos;
    //     player->setTimsCups(timsCups);
    //     player->setMoney(money);
    //     player->setPos(pos);

    //     if (pos == 10 && stream) {
    //         stream >> placeInLine;
    //         if (placeInLine != 0) {
    //             stream >> turnsInLine;
    //         }
    //         // may create a tims line object, idk yet 
    //         // idrk what the tims line does
    //     }
    // }

    return player;
}

Game::Game(istream& in) : currPlayerInd{0} { // ctor
    in >> numPlayers;  
    in.ignore(); // Ignore the newline after numPlayers

    string line;
    for (int i = 0; i < numPlayers; i++) {
        if (getline(in, line)) {  // Read a full line
            players.push_back(readPlayer(line)); // Pass string to readPlayer
            
        }
    }
    
    board = make_shared<Board>(players); // board ctor will set up players
    
    dice.emplace_back(std::make_unique<Dice>()); // make 6-sided die
    dice.emplace_back(std::make_unique<Dice>());

}

// void playerDice() {
//     player->attachDice(dice);
// }



int Game::getCurrent() { return currPlayerInd; }

int Game::getCurrentPos() {return players[currPlayerInd]->getPos(); }

void Game::next() { // changes player to next player
    if (currPlayerInd == numPlayers - 1) {
        currPlayerInd = 0;
    } else {
        currPlayerInd++;
    }
}


void Game::move() {
    
    // rolls die (random number generator, may create die method)
    // moves the current player
    int moves = dice[0]->roll() + dice[1]->roll(); // roll dice
    // save two rolls to vector<int> = {roll1, roll2} --> in player
    board->move(players[currPlayerInd], moves);

}

bool Game::kill(int player) { // check if player can be killed, if can kill, if not no
    if (players[currPlayerInd]->getMoney() < players[currPlayerInd]->getDebt()) {
        board->removePlayer(players[currPlayerInd]);
        players.erase(players.begin() + currPlayerInd);
        return true;
    } else {
        return false;
    }
}

void Game::print() { board->printBoard(); }

// Game::Dice::Dice(int numSides) : numSides{numSides} {
//     for (int i = 0; i <= numSides; i++) {
//         sides.emplace_back(i);
//     }
    
// }

// int Game::Dice::roll() {
//     return { rand() % 6 };
// }


void Game::getPlayerInfo() {
    for (auto & player : players) {
        cout << player->getName() << " " << player->getSym() << " " << player->getMoney() << endl;
    }
}





