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
//dc tims line functions

void Player::sendToTims() {
    pos = 11;
    isInTimsLine = true;
    turnsInLine = 0;
    cout << name << " was sent to DC Tims Line!" << endl;
    
    while (true) {
        if (turnsInLine >= 2) {
            cout << "LAST TURN! You must pay or use a cup:" << endl;
            cout << "2. Pay $50 to leave" << endl;
            if (timsCups > 0) {
                cout << "3. Use Roll Up the Rim cup" << endl;
            }
        } else {
            cout << "Options (turn " << (turnsInLine + 1) << " of 3):" << endl;
            cout << "1. Roll dice" << endl;
            cout << "2. Pay $50 to leave" << endl;
            if (timsCups > 0) {
                cout << "3. Use Roll Up the Rim cup" << endl;
            }
        }
        int input;
        while (true) {
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Invalid input. Please enter a number: ";
                continue;
            }
            bool valid = false;
            if (turnsInLine >= 2) {
                valid = (input == 2) || (input == 3 && timsCups > 0);
            } else {
                valid = (input >= 1 && input <= 3) && 
                       !(input == 3 && timsCups <= 0);
            }

            if (valid) break;
            cout << "Invalid option. Please try again: ";
        }

        // Handle player choice
        switch (input) {
            case 1: 
                if (rollForTimsRelease()) {
                    inTimsLine = false; 
                    turnsInLine = -1;
                } else {
                    turnsInLine++;
                }
                break;
                
            case 2: 
                if (balance >= 50) {
                    balance -= 50;
                    inTimsLine = false;
                    turnsInLine = -1;
                    cout << "Paid $50 to leave DC Tims Line." << endl;
                } else {
                    cout << "Not enough money to pay! Try another option." << endl;
                }
                break;
                
            case 3: // Use cup
                timsCups--;
                inTimsLine = false;
                turnsInLine = -1;
                cout << "Used Roll Up the Rim cup to leave DC Tims Line!" << endl;
                break;
        }
    }
}

bool Player::rollForTimsRelease() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    lastRoll = die1+die2;
    cout << "Rolled: " << die1 << " and " << die2 << endl;
    
    if (die1 == die2) {
        cout << "Doubles! You're free to leave DC Tims Line!" << endl;
        return true;
    }
    
    cout << "Not doubles. You must stay in DC Tims Line." << endl;
    return false;
}




