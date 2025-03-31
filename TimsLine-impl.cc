module timsline;

import <memory>;
import <iostream>;
import <sstream>;
import <vector>;
import <string>;


using namespace std;


TimsLine::TimsLine(int pos, const std::string& name) : NonProperty{pos, name} {
    dice.emplace_back(std::make_unique<Dice>());
    dice.emplace_back(std::make_unique<Dice>());
}


void TimsLine::landed(std::shared_ptr<Player> player) {
    addPlayer(player);
    int previousPosition = player->getPre();
    cout << "previous position: " << previousPosition << endl;

    if (previousPosition != 30) { // Player is passing by
        cout << player->getName() << " has landed on " << getName() << endl;
    } else { // Player was sent to Tims line
        addToLine(player);
        turn(player);
    }
}

int TimsLine::turn(std::shared_ptr<Player> player) {
    player->incTurnsInLine();
    
    cout << player->getName() << " is in the DC Tims Line" << endl;
    cout << "Options:" << endl;
    cout << "   1. pay $50" << endl;
    cout << "   2. use a Roll Up the Rim Cup" << endl;
    cout << "   3. attempt to roll doubles" << endl;
    
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 1: // Pay $50
            return handlePaymentOption(player);
            
        case 2: // Use cup
            return handleCupOption(player);
            
        case 3: // Roll doubles
            return handleRollOption(player);
            
        default:
            cout << "invalid choice, staying in line" << endl;
            return 0;
    }
}

int TimsLine::handlePaymentOption(std::shared_ptr<Player> player) {
    player->pay(50);
    removeFromLine(player);
    cout << "Paid $50 to leave Tims Line" << endl;
    return 0;
}

int TimsLine::handleCupOption(std::shared_ptr<Player> player) {
    if (player->getCupNum() >= 1) {
        player->useCup();
        removeFromLine(player);
        cout << "used cup to leave DC Tims Line" << endl;
        return 0;
    }
    cout << "no cups available, staying in line" << endl;
    return 0;
}

int TimsLine::handleRollOption(std::shared_ptr<Player> player) {
    int roll1 = dice[0]->roll();
    int roll2 = dice[1]->roll();
    cout << "rolled: " << roll1 << " and " << roll2 << endl;
    
    if (roll1 == roll2) {
        removeFromLine(player);
        cout << "rolled doubles" << endl;
        return roll1 + roll2;
    }
    
    if (player->getTurnsInLine() >= 3) {
        return handleForcedExit(player, roll1 + roll2);
    }
    
    return 0;
}

int TimsLine::handleForcedExit(std::shared_ptr<Player> player, int rollSum) {
    cout << "Been in line for 3 turns, must leave" << endl;
    cout << "Options:" << endl;
    cout << "   1. pay $50" << endl;
    cout << "   2. use a Roll Up the Rim Cup" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 2 && player->getCupNum() >= 1) {
        player->useCup();
        removeFromLine(player);
        cout << "used Roll Up the Rim Cup" << endl;
        return rollSum;
    }
    
    // Default to payment if cup not available or not chosen
    player->pay(50);
    removeFromLine(player);
    cout << "paid 50" << endl;
    return rollSum;
}

void TimsLine::addToLine(std::shared_ptr<Player> player) {
    player->setInLine(true);
    inLine.push_back(player);
}

void TimsLine::removeFromLine(std::shared_ptr<Player> player) {
    player->setInLine(false);
    player->resetTurnsInLine();
    for (auto it = inLine.begin(); it != inLine.end(); ) {
        if (*it == player) {  // Note: == for comparison, not =
            it = inLine.erase(it); // erase returns next valid iterator
        } else {
            ++it;
        }
    }
}


T