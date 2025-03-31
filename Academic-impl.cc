module academic;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <map>;
import <string>;

using namespace std;

map<string, map<string, shared_ptr<Player>>> Academic::ownership = {
    {"Arts1", {{"AL", nullptr}, {"ML", nullptr}}},
    {"Arts2", {{"ECH", nullptr}, {"PAS", nullptr}, {"HH", nullptr}}},
    {"Eng", {{"RCH", nullptr}, {"DWE", nullptr}, {"CPH", nullptr}}},
    {"Health", {{"LHI", nullptr}, {"BMH", nullptr}, {"OPT", nullptr}}},
    {"Env", {{"EV1", nullptr}, {"EV2", nullptr}, {"EV3", nullptr}}},
    {"Sci1", {{"PHYS", nullptr}, {"B1", nullptr}, {"B2", nullptr}}},
    {"Sci2", {{"EIT", nullptr}, {"ESC", nullptr}, {"C2", nullptr}}},
    {"Math", {{"MC", nullptr}, {"DC", nullptr}}},
};

map<int, vector<int>> Academic::costChart = {
    {1, {40, 50, 2, 10, 30, 90, 160, 250}},
    {3, {60, 50, 4, 20, 60, 180, 320, 450}},
    {6, {100, 50, 6, 30, 90, 270, 400, 550}},
    {8, {100, 50, 6, 30, 90, 270, 400, 550}},
    {9, {120, 50, 8, 40, 100, 300, 450, 600}},
    {11, {140, 100, 10, 50, 150, 450, 625, 750}},
    {13, {140, 100, 10, 50, 150, 450, 625, 750}},
    {14, {160, 100, 12, 60, 180, 500, 700, 900}},
    {16, {180, 100, 14, 70, 200, 550, 750, 950}},
    {18, {180, 100, 14, 70, 200, 550, 750, 950}},
    {19, {200, 100, 16, 80, 220, 600, 800, 1000}},
    {21, {220, 150, 18, 90, 250, 700, 875, 1050}},
    {23, {220, 150, 18, 90, 250, 700, 875, 1050}},
    {24, {240, 150, 20, 100, 300, 750, 925, 1100}},
    {26, {260, 150, 22, 110, 330, 800, 975, 1150}},
    {27, {260, 150, 22, 110, 330, 800, 975, 1150}},
    {29, {280, 150, 24, 120, 360, 850, 1025, 1200}},
    {31, {300, 200, 26, 130, 390, 900, 1100, 1275}},
    {32, {300, 200, 26, 130, 390, 900, 1100, 1275}},
    {34, {320, 200, 28, 150, 450, 1000, 1200, 1400}},
    {37, {350, 200, 35, 175, 500, 1100, 1300, 1500}},
    {39, {400, 200, 50, 200, 600, 1400, 1700, 2000}}
};


Academic::Academic(int pos, const string& name, const string& block) : 
    Building{pos, name}, improveLevel{0}, block{block} {}

void Academic::landed(shared_ptr<Player> player) {
    cout << player->getName() << " has landed on " << getName() << endl;
    addPlayer(player);
    if (isOwned()) {
        if (player != getOwner()) {
            int tuition = getTuition();
            player->pay(tuition);
            getOwner()->addMoney(tuition);
            cout << player->getName() << " has paid " << getOwner()->getName() << " rent: " << tuition << endl;
        }
    } else { // not owned
        if (player->getMoney() >= getCost()) {
            int choice;
            cout << "would you like to purchase " << getName() << endl;
            cout << "   1 to buy, 2 no" << endl;
            cin >> choice;
            if (choice == 1) {
                bought(player);
                player->pay(getCost());
                cout << player->getName() << " now owns " << getName() << endl;
            } else {
               cout << "    did not purchase"; 
            }
        } else {
            cout << "you cannot buy, go away" << endl;
        }
    }
}

void Academic::bought(shared_ptr<Player> player) {
    changeOwner(player);
    changeIsOwned(true);
    player->addAsset(getPos());
    addOwnership(player);
}

void Academic::addOwnership(shared_ptr<Player> player) {
    for (auto & [set, buildings] : ownership) {
        if (set == block) {
            for(auto & [name, own] : buildings) {
                if (name == getName()) {
                    own = player;
                }
            }
        }
    }
}


int Academic::getCost() {
    int pos = getPos() + 1;
    if (costChart.find(pos) != costChart.end()) {
        return costChart[pos][0]; // First value in the array is cost
    }
    return -1; // Return an invalid value to indicate an error
}



int Academic::getTuition() {
    int pos = getPos() + 1;
    // cout << "pos: " << pos << endl;
    if (costChart.find(pos) != costChart.end()) {
        int index = improveLevel + 2; // Correct index for tuition
        int baseTuition = costChart[pos][index]; 
        // cout << "base tut: " << baseTuition << endl;

        if (isMonopoly()) {
            return baseTuition * 2;
        } else {
            return baseTuition;
        }
        
    }
    return -1;
}


bool Academic::isMonopoly() {
    vector<shared_ptr<Player>> players;

    for (auto & [set, buildings] : ownership) {
        if (set == block) {
            for (auto & [name, own] : buildings) {
                players.emplace_back(own);
            }
        }
    }

    bool isMonopoly = true;
    
    ///
    for (size_t i = 0; i < players.size() - 1; i++) {
        if (players[i] != players[i + 1]) {
            isMonopoly = false;
        }
    }

    return isMonopoly;

}



