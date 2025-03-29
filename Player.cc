export module player;
import <memory>;
import <string>;


using namespace std;

export class Player {
    string name;
    char symbol;
    int balance, pos, timsCups, debt;

    // <vector<Improvements>> improvements;
    // <vector<Building>> assets;

public:
    Player(string name, char symbol) : 
        name{name}, symbol{symbol}, balance{0}, pos{0}, timsCups{0}, debt{0} {}

    int getMoney();
    int getDebt();
    int getPos();
    char getSym();
    void setTimsCups(int cups);
    void setMoney(int m);
    void setPos(int p);
    void printPlayer();

    void addMoney(int money);
    void payToPlayer(shared_ptr<Player> player, int money);
};

