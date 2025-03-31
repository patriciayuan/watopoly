export module osap;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;

import player;
import square;
import nonproperty;

export class CollectOSAP: public NonProperty{
    public:
        CollectOSAP(int pos, const std::string& name);
        void landed(std::shared_ptr<Player>player) override;
};


