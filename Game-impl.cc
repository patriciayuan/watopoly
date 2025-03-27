module game;

import <iostream>
import <memory>
import <string>

import player;
import board;
using namespace std;

Game::Game(istream & in) : currPlayerInd{0}{
    string playerName;
    char playerSymbol;
    int timsCups, money, pos, placeInLine = -1, turnsInLine = -1;
    in << numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        in << playerName << playerSymbol << timsCups << money << pos;
        if (pos == 10) {
            in << placeInLine;
            if (placeInLine == 0) {
                in << turnsInLine;
            }
        }
        players.push_back(Player{playerName, playerSymbol, timsCups, money, pos, placeInLine, turnsInLine});
    }



    /// do board set up

}










