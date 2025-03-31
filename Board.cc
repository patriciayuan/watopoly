export module board;

import <iostream>;
import <vector>;
import <memory>;

// class Player;

import player;
import square;
import building;
import residence;
import gym;
import academic;



import nonproperty;
import tuition;
import coopfee;
import osap;
import goose;
import slc;
import needleshall;
import gototims;
import timsline;

// class Building;
// class NonProperty;

using namespace std;

export class Board {
        std::vector<std::shared_ptr<Player>> players;
        std::vector<std::shared_ptr<Player>> timsLine;
        std::vector<std::shared_ptr<Square>> squares;
        bool owned;

    public:
        Board(std::vector<std::shared_ptr<Player>> players);

        void initSquares();

        void printBoard();

        void removePlayer(std::shared_ptr<Player> player);
        

        void move(std::shared_ptr<Player> player, int moved);

    
};


