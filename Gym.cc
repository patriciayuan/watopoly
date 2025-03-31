export module gym;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

import dice;
import player;
import building;


export class Gym : public Building {
    static int gymsOwned;
    std::vector<std::unique_ptr<Dice>> dice;
    int cost;


    public: 
        Gym(int pos, const std::string& name);
        void landed(std::shared_ptr<Player> player) override;
        int roll();
        int getFees();
        int getCost() const;
        void addGymsOwned();



};


