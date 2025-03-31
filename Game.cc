export module game;

import <iostream>;
import <vector>;
import <memory>; 
import <string>;

import dice;
import player;
import square;
import board;

export class Game {

    private: 

        std::shared_ptr<Board> board;
        std::vector<std::shared_ptr<Player>> players;
        std::vector<std::unique_ptr<Dice>> dice;
        int numPlayers;
        int currPlayerInd;

    public:


        Game(std::istream& in = std::cin);
        std::shared_ptr<Player> readPlayer(const std::string& in);
        int getCurrent();
        int getCurrentPos();
        void next();
        void move();
        bool kill(int player);
        void save(std::string fname); // saves game to file fname, continues game
        void print();
        void getPlayerInfo();
    
};






