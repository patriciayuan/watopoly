export module goose;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

import player;
import square;
import nonproperty;

export class GooseNesting : public NonProperty{
    public:
        GooseNesting(int pos, const std::string& name);
        void landed(std::shared_ptr<Player>player) override;
};


