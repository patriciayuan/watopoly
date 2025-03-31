export module gototims;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

import player;
import square;
import nonproperty;

export class GoToTims : public NonProperty{
    public:
        GoToTims(int pos, const std::string& name);
        void landed(std::shared_ptr<Player>player) override;
};
