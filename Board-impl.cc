

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


Board::Board(vector<shared_ptr<Player>> players) : players{players} {
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


// im still trying to figure out how to print board
void Board::        void printBoard() {
            
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



void Board::move(shared_ptr<Player> player, int moved) {
    cout << "game, move" << endl;
    int pos = player->getPos();
    cout << pos << endl;
    squares[pos]->removePlayer(player);
    squares[pos + moved]->land(player);
    player->setPos(pos + moved);

}

void Board::removePlayer(shared_ptr<Player> player) {
    int pos = player->getPos();
    squares[pos]->removePlayer(player);
}





