module player;
import <iostream>;
import <vector>;
import <memory>;
import <string>;

using namespace std;


// these need to be changed to store and save 
Player::Player(string name, char symbol) : 
    name{name}, symbol{symbol}, balance{800}, pos{0}, debt{0}, previous{0}, inTimsLine{false} {}

int Player::getMoney() { return balance; }
int Player::getDebt() { return debt; }
int Player::getPos() { return pos; }
char Player::getSym() { return symbol; }
string Player::getName() const { return name; }
// void Player::setTimsCups(int cups) { timsCups = cups; }
void Player::setMoney(int m) { balance = m; }
void Player::setPos(int p) { pos = p; }
void Player::printPlayer() { cout << symbol; }
void Player::setPre(int pos) { previous = pos; }
int Player::getPre() const { return previous; }

void Player::addMoney(int money) { balance += money; }

void Player::payToPlayer(shared_ptr<Player> player, int money) {
    balance -= money;
    player->addMoney(money);
}


void Player::addAsset(int pos){
    assets.emplace_back(pos);
}



int Player::getAssets() {
    int amount = 0;
    for (auto & building : assets) {
        amount += 1000;
    }

    return amount;
}

void Player::pay(int amount) {
    balance -= amount;
}


void Player::passedOSAP() {
    balance += 200;
}


void Player::addTimsCup() {
    timsCups++;
}

bool Player::canGetTimsCup() {
    if (timsCups >= 4) {
        return false;
    }

    return true;
}


int Player::getTurnsInLine() { return turnsInLine; }
void Player::setInLine(bool isInLine) { inTimsLine = isInLine; }
bool Player::isInLine() { return inTimsLine; }
void Player::incTurnsInLine() { turnsInLine++; }
void Player::resetTurnsInLine() { turnsInLine = 0; }

int Player::getCupNum() { return timsCups; }
void Player::useCup() { timsCups--; }



