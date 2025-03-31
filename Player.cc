export module player;
import <iostream>;
import <vector>;
import <memory>;
import <string>;

// import board;
class Building;
// class Board;

export class Player {
    std::string name;
    bool inTimsLine;
    char symbol;
    int balance;
    int pos;
    int timsCups;
    int debt;
    int turnsInLine;
    int previous; // stores previous position
    // int assets;
    // std::shared_ptr<Board> board;

    // vector<int> rolls = {last 2 rolls};
    // <vector<Improvements>> improvements;
    std::vector<int> assets;

public:
    Player(std::string name, char symbol);

    int getMoney();
    int getDebt();
    int getPos();
    char getSym();
    void setTimsCups(int cups);
    void setMoney(int m);
    void setPos(int p);
    void printPlayer();

    bool isInLine();
    void setInLine(bool isInLine);
    int getTurnsInLine();
    void incTurnsInLine();
    int getCupNum();
    void useCup();


    // std::vector<int> getRolls() {
    //     return rolls;
    // }

    std::string getName() const;


    int getAssets();

    void addMoney(int money);
    void pay(int amount);



    void payToPlayer(std::shared_ptr<Player> player, int money);
    void addAsset(int pos); // takes position of building
    void passedOSAP();
    void setPre(int pos); // set previous position
    int getPre() const;
    // void attachDice(vector<std::shared_ptr<Dice>> dice);
    // void assignBoard(std::shared_ptr<Board> board);



    void addTimsCup();
    bool canGetTimsCup();

    void resetTurnsInLine();
};

