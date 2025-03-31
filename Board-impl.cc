module board;

import <iostream>;
import <memory>;
import <map>;
import <iomanip>;
import <vector>;
import <string>;

using namespace std;

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
    {12, "RCH"},
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


Board::Board(vector<shared_ptr<Player>> players) : players{players} {
    cout << "board ctor" << endl;
    // create squares

    
    initSquares();

    for (auto & player : players) {
        int pos = player->getPos();
        squares[pos]->addPlayer(player);
    }

}



void Board::initSquares() {
    squares.emplace_back(make_shared<CollectOSAP>(0, "COLLECT OSAP"));
    squares.emplace_back(make_shared<Academic>(1, "AL", "Arts1"));
    squares.emplace_back(make_shared<SLC>(2, "SLC"));
    squares.emplace_back(make_shared<Academic>(3, "ML", "Arts1"));
    squares.emplace_back(make_shared<Tuition>(4, "TUITION"));
    squares.emplace_back(make_shared<Residence>(5, "MKV"));
    squares.emplace_back(make_shared<Academic>(6, "ECH", "Arts2"));
    squares.emplace_back(make_shared<NeedlesHall>(7, "NEEDLES HALL"));
    squares.emplace_back(make_shared<Academic>(8, "PAS", "Arts2"));
    squares.emplace_back(make_shared<Academic>(9, "HH", "Arts2"));
    squares.emplace_back(make_shared<TimsLine>(10, "DC Tims Line"));

    squares.emplace_back(make_shared<Academic>(11, "RCH", "Eng"));
    squares.emplace_back(make_shared<Gym>(12, "PAC"));
    squares.emplace_back(make_shared<Academic>(13, "DWE", "Eng"));
    squares.emplace_back(make_shared<Academic>(14, "CPH", "Eng"));
    squares.emplace_back(make_shared<Residence>(15, "UWP"));
    squares.emplace_back(make_shared<Academic>(16, "LHI", "Health"));
    squares.emplace_back(make_shared<SLC>(17, "SLC"));
    squares.emplace_back(make_shared<Academic>(18, "BMH", "Health"));
    squares.emplace_back(make_shared<Academic>(19, "OPT", "Health"));
    squares.emplace_back(make_shared<GooseNesting>(20, "Goose Nesting"));

    squares.emplace_back(make_shared<Academic>(21, "EV1", "Env"));
    squares.emplace_back(make_shared<NeedlesHall>(22, "NEEDLES HALL"));
    squares.emplace_back(make_shared<Academic>(23, "EV2", "Env"));
    squares.emplace_back(make_shared<Academic>(24, "EV3", "Env"));
    squares.emplace_back(make_shared<Residence>(25, "V1"));
    squares.emplace_back(make_shared<Academic>(26, "PHYS", "Sci1"));
    squares.emplace_back(make_shared<Academic>(27, "B1", "Sci1"));
    squares.emplace_back(make_shared<Gym>(28, "CIF"));
    squares.emplace_back(make_shared<Academic>(29, "B2", "Sci1"));
    squares.emplace_back(make_shared<GoToTims>(30, "GO TO TIMS"));

    squares.emplace_back(make_shared<Academic>(31, "EIT", "Sci2"));
    squares.emplace_back(make_shared<Academic>(32, "ESC", "Sci2"));
    squares.emplace_back(make_shared<SLC>(33, "SLC"));
    squares.emplace_back(make_shared<Academic>(34, "C2", "Sci2"));
    squares.emplace_back(make_shared<Residence>(35, "REV"));
    squares.emplace_back(make_shared<NeedlesHall>(36, "NEEDLES HALL"));
    squares.emplace_back(make_shared<Academic>(37, "MC", "Math"));
    squares.emplace_back(make_shared<CoopFee>(38, "COOP FEE"));
    squares.emplace_back(make_shared<Academic>(39, "DC", "Math"));


}



void Board::move(shared_ptr<Player> player, int moved) {
    int pos = player->getPos();
    player->setPre(pos);
    // cout << pos << endl;
    cin >> moved; // for testing --> this can be used in testing mode
    
    int newpos = pos + moved;


    if (player->isInLine()) { // if in line
        // newpos = player->movement();
        // cout << "hello" << endl;

        player->setPre(30);
        moved = squares[pos]->turn(player);
        newpos = 10;
    } else {
        cout << "move" << endl;
        if (newpos > 39) {
            newpos = newpos % 40;
            player->passedOSAP(); // adds balance
        }
        
        if (newpos == 2 || newpos == 17 || newpos == 33) {
            newpos = squares[newpos]->newpos(player, newpos);
        } else if (newpos == 30) {
            cout << player->getName() << " was sent to the DC Tims Line" << endl;
            newpos = 10; 
            player->setPre(30);
        }

        squares[pos]->removePlayer(player);
        player->setPos(newpos);
        squares[newpos]->landed(player);

    }

}

void Board::removePlayer(shared_ptr<Player> player) {
    int pos = player->getPos();
    squares[pos]->removePlayer(player);
    player->resetTurnsInLine();
}









// print board
void Board::printBoard() {
            
    // top border
    for (int i = 0; i <= 88; i++) {
        cout << "_";
    }
    cout << endl;

    // load top row
    vector<vector<string>> printLoadOut;
    for (int i = 21; i <= 31; i++) {
        printLoadOut.emplace_back(squares[i - 1]->printSquare());
    }

    // print top row
    for (int i = 0; i < 7; i++) { // rows
        cout << "|";
        for (int j = 0; j < 11; j++) { // cols
            if (i == 6) {
                cout << "_______";
            } else {
                cout << setw(7) << printLoadOut[j][i];
            }
            cout << "|";
        }
        cout << "\n";
    }

    // sides
    vector<vector<string>> printSides;
    for (int i = 20, j = 12; i >= 12 && j <= 28; i--, j += 2) {

        printSides.emplace_back(squares[i - 1]->printSquare());
        printSides.emplace_back(squares[i + j - 1]->printSquare());
        for (int j = 0; j < 7; j++) {
            if (j == 6){
                cout << "|_______|";
                for (int k = 0; k <= 70; k++) {
                    if (i == 12) {
                        cout << "_";
                    } else {
                        cout << " ";
                    }
                }
                cout << "|_______|";

            } else {
                cout << "|";
                cout << setw(7) << printSides[0][j];
                cout << "|";
                for (int k = 0; k <= 70; k++) {
                    cout << " ";
                    
                }
                cout << "|";
                cout << setw(7) << printSides[1][j];
                cout << "|";
            }
            cout << "\n";
            
        }
        printSides.clear();

    }

    // load botom
    printLoadOut.clear();
    for (int i = 11; i >= 1; i--) {
        printLoadOut.emplace_back(squares[i - 1]->printSquare());
    }

    // print bottom
    for (int i = 0; i < 7; i++) { // rows
        cout << "|";
        for (int j = 0; j < 11; j++) { // cols
            if (i == 6) {
                cout << "_______";
            } else {
                cout << setw(7) << printLoadOut[j][i];
            }
            cout << "|";
        }
        cout << "\n";
    }
}





