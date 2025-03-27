
// import <iostream>;
// import <memory>;
// import <vector>;
// import <string>;

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include <string>

using namespace std;

class Squares;
class Building;

class Player {
    string name;
    char symbol;
    int balance, pos, timsCups, debt;

    // <vector<Improvements>> improvements;
    // <vector<Building>> assets;


public:
    Player(string name, char symbol);
    // set defaults in MIL
    void setTimsCups(int cups) { timsCups = cups; }
    void setMoney(int m) { balance = m; }
    void setPos(int p) { pos = p; }
    void printPlayer() { 
        // cout << name;
        cout << symbol;
    }



    int move(int pos); // takes target position




};


map<int, string> squareNames = {
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
        // vector<shared_ptr<Squares>> squares;

    public:
        Board(vector<shared_ptr<Player>> players) : players{players} {
            // create squares
        }
        // start == CollectOSAP
        
        void printBoard() {
            vector<int> top = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
            vector<int> bottom = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        }

        void printSquare(int pos) {


        }

        


        

        void setSquare(); // adds squares to the 


    
};

shared_ptr<Player> readPlayer(const string& in) {
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

        if (pos == 10) {
            stream >> placeInLine;
            if (placeInLine != 0) {
                stream >> turnsInLine;
            }
            // may create a tims line object, idk yet idrk what the tims line does
        }
    }

    return player;
}

class Game {
        unique_ptr<Board> board;
        vector<shared_ptr<Player>> players;
        int numPlayers;
        int currPlayerInd;

    public:
        // creates board and players
        // <shared_ptr<Player>> readPlayers(string & in);
        Game(istream& in = cin) : currPlayerInd{0} { // Constructor for loading a saved game
            in >> numPlayers;  
            in.ignore(); // Ignore the newline after numPlayers

            string line;
            for (int i = 0; i < numPlayers; i++) {
                if (getline(in, line)) {  // Read a full line
                    players.push_back(readPlayer(line)); // Pass string to readPlayer
                }
            }
            
            auto board = make_unique<Board>(players);
            // Do board setup
        }

        int getCurrent() { return currPlayerInd; }
        int getAssets(int player = 0);

        void next() {
            if (currPlayerInd == numPlayers - 1) {
                currPlayerInd = 0;

            } else {
                currPlayerInd++;
            }
        }

        void move(); 
        // rolls die (random number generator, may create die method)
        // moves the current player


        bool kill(int player); // check if player can be killed, if can kill, if not no
        void save(string fname); // saves game to file fname, continues game
        



};



int main(int argc, char * argv[]) {
    // "-load "filename"
    // create game, which will create a board
    // run through each command: roll, next, improve, mortgage, unmortgage, bankrupt, assets, all, save
    // need to save to file and save games. 
    istream &in = cin;
    if (argc >= 2 && argv[1] == "-load") {
        ifstream ifs{argv[2]};
        auto game = make_unique<Game>(ifs);
    } 

    auto game = make_unique<Game>();

    

    string command;
    string name, give, receive, property;
    string filename;
    cin >> command;

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
            game->getAssets(game->getCurrent());
        } else if (command == "all") {
            // does not work if a player is deciding how to pay tuition
            game->getAssets();
        } else if (command == "save") {
            cin >> filename;
            game->save(filename);

        }
    }



    

    





}
