export module timsline;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <random>;
import <array>;
import <string>;

import dice;
import player;
import square;
import nonproperty;


export class TimsLine : public NonProperty {

        std::vector<std::shared_ptr<Player>> inLine;
        std::vector<std::unique_ptr<Dice>> dice;

    public: 
        TimsLine(int pos, const std::string& name);
        int turn(std::shared_ptr<Player> player);
        void landed(std::shared_ptr<Player>player) override;
        void addToLine(std::shared_ptr<Player> player);
        void removeFromLine(std::shared_ptr<Player> player);
        int handlePaymentOption(std::shared_ptr<Player> player);
        
        int handleCupOption(std::shared_ptr<Player> player);
        int handleRollOption(std::shared_ptr<Player> player);
        int handleForcedExit(std::shared_ptr<Player> player, int rollSum);
};

