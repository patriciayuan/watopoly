

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
void Board::printBoard() {
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

void Board::printSquare(int pos) {
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





