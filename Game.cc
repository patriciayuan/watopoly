export module game;

import <iostream>;
import <vector>;
import <memory>; 
import <string>;

import player;
import board;



export class Game {
    unique_ptr<Board> board;
    vector<shared_ptr<Player>> players;
    vector<unique_ptr<Dice>> dice;
    int numPlayers;
    int currPlayerInd;

public:

    class Dice {
        int numSides;
        vector<int> sides;
    public:
        Dice(int numSides = 6);
        int roll();
    };

    // creates board and players
    // <shared_ptr<Player>> readPlayers(string & in);
    Game(istream& in = cin);
    int getCurrent();
    int getCurrentPos();
    void next();
    void move();
    bool kill(int player);
    void save(string fname); // saves game to file fname, continues game
    void print();
    



};






