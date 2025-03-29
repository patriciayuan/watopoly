module player;

import <memory>;
import <string>;

Player::Player(string name, char symbol) : 
    name{name}, symbol{symbol}, balance{1500}, pos{0}, timsCups{0}, debt{0} {}

int Player::getMoney() { return balance; }
int Player::getDebt() { return debt; }
int Player::getPos() { return pos; }
char Player::getSym() { return symbol; }
void Player::setTimsCups(int cups) { timsCups = cups; }
void Player::setMoney(int m) { balance = m; }
void Player::setPos(int p) { pos = p; }
void Player::printPlayer() { cout << symbol; }

void Player::addMoney(int money) { balance += money; }

void Player::payToPlayer(shared_ptr<Player> player, int money) {
    balance -= money;
    player->addMoney(money);
}









