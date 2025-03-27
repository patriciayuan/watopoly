export module game;

import <iostream>;
import <memory>; 

import board;


export class Game {
        <unique_ptr<Board>> board;
        <vector<shared_ptr<Player>> players;
        int numPlayers;
        int currPlayerInd;

    public:
        Game(istream & in = std::cin); // creates board and players

        void turn(); // plays current player's move
        

}





