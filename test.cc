
// import <iostream>;
// import <memory>;
// import <vector>;
// import <string>;

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include <iomanip>
#include <string>

using namespace std;
const int SQUARE_WIDTH = 8;

class Building;

class Player {
    string name;
    char symbol;
    int balance, pos, timsCups, debt;

    // <vector<Improvements>> improvements;
    // <vector<Building>> assets;


public:
    Player(string name, char symbol) : 
        name{name}, symbol{symbol}, balance{1500}, pos{0}, timsCups{0}, debt{0} {}

    // set defaults in MIL
    int getMoney() { return balance; }
    int getDebt() { return debt; }
    int getPos() { return pos; }
    char getSym() { return symbol; }
    void setTimsCups(int cups) { timsCups = cups; }
    void setMoney(int m) { balance = m; }
    void setPos(int p) { pos = p; }
    void printPlayer() { cout << symbol; }

};

class Square {
        int pos;
        string name;
        vector<shared_ptr<Player>> onsquare;
    public:
        Square(int pos, string name) : pos{pos}, name{name} {}
        
        // used for adding during set up, not move.
        void addPlayer(shared_ptr<Player> player) { onsquare.emplace_back(player); } 
        
        string getName() { return name; }
        int getPos() { return pos; }
        vector<char> getPlayers() {
            vector<char> symbols;
            for (auto & player : onsquare) {
                symbols.emplace_back(player->getSym());
            }
            return symbols;
        }
        
        void removePlayer(shared_ptr<Player> player) {
            for (auto it = onsquare.begin(); it != onsquare.end(); ++it) {
                if (*it == player) {
                    onsquare.erase(it);
                    break; // Exit loop once removed
                }
            }
        }

        void land(shared_ptr<Player> player) {
            // will notify 
            addPlayer(player); // for now
        }


};


map<int, string> posAndName = {
    // bottom
    {1, "COLLECT OSAP"},
    {2, "AL"},
    {3, "SLC"},
    {4, "ML"},
    {5, "TUITION"},
    {6, "MKV"},
    {7, "ECH"},
    {8, "NEEDLES HALL"},
    {9, "PAS"},
    {10, "HH"},
    {11, "DC Tims Line"},
    
    // left
    {1, "RCH"},
    {13, "PAC"},
    {14, "DWE"},
    {15, "CPH"},
    {16, "UWP"},
    {17, "LHI"},
    {18, "SLC"},
    {19, "BMH"},
    {20, "OPT"},
    {21, "Goose Nesting"},

    // top
    {22, "EV1"},
    {23, "NEEDLES HALL"},
    {24, "EV2"},
    {25, "EV3"},
    {26, "V1"},
    {27, "PHYS"},
    {28, "B1"},
    {29, "CIF"},
    {30, "B2"},
    {31, "GO TO TIMS"},

    // right
    {32, "EIT"},
    {33, "ESC"},
    {34, "SLC"},
    {35, "C2"},
    {36, "REV"},
    {37, "NEEDLES HALL"},
    {38, "MC"},
    {39, "COOP FEE"},
    {40, "DC"}


};

class Board {
        vector<shared_ptr<Player>> players;
        vector<shared_ptr<Player>> timsLine;
        vector<unique_ptr<Square>> squares;

    public:
        Board(vector<shared_ptr<Player>> players) : players{players} {
            cout << "board ctor" << endl;
            // create squares
            for (int i = 1; i <= 40; i++) {
                squares.emplace_back(make_unique<Square>(i, posAndName[i]));
            }

            for (auto & player : players) {
                int pos = player->getPos();
                squares[pos]->addPlayer(player);
            }

        }
        // start == CollectOSAP
        

        void printBoard() {
            vector<int> bottom = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        
            // Print top row

            for (int i = 21; i <= 31; i++) {
                printSquare(i);
            }
            cout << "\n";
        
            // Print middle section with spacing
            for (int i = 20, j = 12; i >= 12 && j <= 28; i--, j += 2) {
                printSquare(i);
                cout << setw(SQUARE_WIDTH) << " "; // Uniform spacing for empty middle
                printSquare(i + j);
                cout << "\n";
            }
            
        
            // Print bottom row
            for (int i : bottom) {
                printSquare(i);
            }
        }
        
        void printSquare(int pos) {
            if (pos == -1) {
                cout << setw(SQUARE_WIDTH) << " "; // Uniform empty space
                return;
            }
        
            // Ensure `squares[pos]` is valid
            if (pos >= 0 && pos < squares.size()) {
                cout << setw(SQUARE_WIDTH) << left << squares[pos]->getName(); // Fixed width
                vector<char> pieces = squares[pos]->getPlayers();
                
                if (!pieces.empty()) {
                    cout << "(";
                    for (size_t i = 0; i < pieces.size(); i++) {
                        cout << pieces[i];
                        if (i < pieces.size() - 1) cout << ","; // Separate players with commas
                    }
                    cout << ")";
                } else {
                    cout << " "; // Maintain spacing if no players
                }
            } else {
                cout << setw(SQUARE_WIDTH) << "??"; // Placeholder for invalid squares
            }
        }

        void move(shared_ptr<Player> player, int moved) {
            cout << "game, move" << endl;
            int pos = player->getPos();
            cout << pos << endl;
            squares[pos]->removePlayer(player);
            squares[pos + moved]->land(player);
            player->setPos(pos + moved);

        }

        void removePlayer(shared_ptr<Player> player) {
            int pos = player->getPos();
            squares[pos]->removePlayer(player);
        }



    
};

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


class Dice {
        int numSides;
        vector<int> sides;

    public:

        Dice(int numSides = 6) : numSides{numSides} {
            for (int i = 0; i <= numSides; i++) {
                sides.emplace_back(i);
            }
        }

        int roll() {
            return { rand() % 6 };
        }
};

class Game {
        unique_ptr<Board> board;
        vector<shared_ptr<Player>> players;
        vector<unique_ptr<Dice>> dice;
        int numPlayers;
        int currPlayerInd;

    public:
        // creates board and players
        // <shared_ptr<Player>> readPlayers(string & in);
        Game(istream& in = cin) : currPlayerInd{0} { // Constructor for loading a saved game
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

        int getCurrent() { return currPlayerInd; }
        int getCurrentPos() {return players[currPlayerInd]->getPos(); }
        

        void next() { // changes player to next player
            if (currPlayerInd == numPlayers - 1) {
                currPlayerInd = 0;
            } else {
                currPlayerInd++;
            }
        }

        void move() {
            
            // rolls die (random number generator, may create die method)
            // moves the current player
            
            int moves = dice[1]->roll() + dice[2]->roll(); // roll dice
            cout << "called game->move(): " << moves << endl;
            board->move(players[currPlayerInd], moves);
            cout << "game->move() successful " << endl;

        }


        bool kill(int player) { // check if player can be killed, if can kill, if not no
            if (players[currPlayerInd]->getMoney() < players[currPlayerInd]->getDebt()) {
                board->removePlayer(players[currPlayerInd]);
                players.erase(players.begin() + currPlayerInd);
                return true;
            } else {
                return false;
            }
        }
        
        void save(string fname); // saves game to file fname, continues game
        void print() { board->printBoard(); }
        



};



int main(int argc, char * argv[]) {
    // "-load "filename"
    // create game, which will create a board
    // run through each command: roll, next, improve, mortgage, unmortgage, bankrupt, assets, all, save
    // need to save to file and save games. 
    // istream &in = cin;
    if (argc >= 2 && std::string(argv[1]) == "-load") {
        ifstream ifs{argv[2]};
        auto game = make_unique<Game>(ifs);
    } 

    auto game = make_unique<Game>();

    cout << "board setup." << endl;

    

    string command;
    string name, give, receive, property;
    string filename;
    // cin >> command;

    while(cin >> command) {

        if (command == "roll") {
            cout << "chose roll" << endl;
            cout << game->getCurrentPos() << endl;
            game->move();
            cout << game->getCurrentPos() << endl;

            game->print();
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

        }
    }



    

    





}


