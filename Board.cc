export module board;

import <iostream>;
import <memory>;

using namespace std;

class Board {
        vector<shared_ptr<Player>> players;
        vector<shared_ptr<Player>> timsLine;
        vector<unique_ptr<Square>> squares;

    public:
        Board(vector<shared_ptr<Player>> players);

        void printBoard();
        
        void printSquare(int pos);

        void move(shared_ptr<Player> player, int moved);

    
};


