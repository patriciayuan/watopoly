module game;

import <iostream>
import <memory>
import <string>

import player;
import board;
using namespace std;

shared_ptr<Player> readPlayer(const string& in) {
    cout << "readPlayer" << endl;
    istringstream stream{in};
    string name;
    char symbol;
    int timsCups = 0, money = 0, pos = 0, placeInLine = -1, turnsInLine = -1;

    stream >> name >> symbol;
    auto player = make_shared<Player>(name, symbol);

    if (stream) {
        stream >> timsCups >> money >> pos;
        player->setTimsCups(timsCups);
        player->setMoney(money);
        player->setPos(pos);

        if (pos == 10 && stream) {
            stream >> placeInLine;
            if (placeInLine != 0) {
                stream >> turnsInLine;
            }
            // may create a tims line object, idk yet 
            // idrk what the tims line does
        }
    }

    return player;
}

Game::Game(istream& in = cin) : currPlayerInd{0} { // ctor
    cout << "game ctor" << endl;
    in >> numPlayers;  
    in.ignore(); // Ignore the newline after numPlayers

    string line;
    for (int i = 0; i < numPlayers; i++) {
        if (getline(in, line)) {  // Read a full line
            players.push_back(readPlayer(line)); // Pass string to readPlayer
            
        }
    }
    
    // for testing ---------------------
    cout << "done readPlayers" << endl;

    for (auto & player : players) {
        cout << player->getSym() << endl;
    }
    
    // for testing ---------------------
    
    board = make_unique<Board>(players); // board ctor will set up players
    
    dice.emplace_back(std::make_unique<Dice>(6)); // make 6-sided die
    dice.emplace_back(std::make_unique<Dice>(6));

    cout << "board done" << endl;
    // owners and stuff will come later
    
}

Game::getCurrent() { return currPlayerInd; }

Game::getCurrentPos() {return players[currPlayerInd]->getPos(); }

Game::next() { // changes player to next player
    if (currPlayerInd == numPlayers - 1) {
        currPlayerInd = 0;
    } else {
        currPlayerInd++;
    }
}


Game::move() {
    
    // rolls die (random number generator, may create die method)
    // moves the current player
    
    int moves = dice[1]->roll() + dice[2]->roll(); // roll dice
    cout << "called game->move(): " << moves << endl;
    board->move(players[currPlayerInd], moves);
    cout << "game->move() successful " << endl;

}

Game::kill(int player) { // check if player can be killed, if can kill, if not no
    if (players[currPlayerInd]->getMoney() < players[currPlayerInd]->getDebt()) {
        board->removePlayer(players[currPlayerInd]);
        players.erase(players.begin() + currPlayerInd);
        return true;
    } else {
        return false;
    }
}

Game::print() { board->printBoard(); }

Game::Dice::Dice(int numSides = 6) : numSides{numSides} {
    for (int i = 0; i <= numSides; i++) {
        sides.emplace_back(i);
    }
}

Game::Dice::roll() {
    return { rand() % 6 };
}









