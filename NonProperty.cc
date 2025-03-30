export module nonproperty;

import square;
import player;
import <memory>;
import <random>;
import <array>;
import <string>;
using namespace std;
export class NonProperty : public Square{
    public:
        NonProperty(const string &name, int pos);
        ~NonProperty() override = default;
        void landed(shared_ptr<Player> player) override = 0;
        bool isOwnable() const override{return false;};
};
export class CollectOSAP: public NonProperty{
    public:
        CollectOSAP(int pos);
        void landed(shared_ptr<Player>player) override;
};
export class DCTimsLine : public NonProperty{
    public:
        DCTimsLine(int pos);
        void landed(shared_ptr<Player>player) override;
        void leaveLine(shared_ptr<Player>player, bool useCup = false);
};

export class GoToTims : public NonProperty{
    public:
        GoToTims(int pos);
        void landed(shared_ptr<Player>player) override;
};

export class GooseNesting : public NonProperty{
    public:
        GooseNesting(int pos);
        void landed(shared_ptr<Player>player) override;
};

export class Tuition: public NonProperty{
    public:
        Tuition(int pos);
        void landed(shared_ptr<Player>player) override;
};

export class CoopFee : public NonProperty{
    public:
        CoopFee(int pos);
        void landed(shared_ptr<Player>player) override;
};
export class SLC : public NonProperty{
    discrete_distribution<int> moveDistribution;
    mt19937 random;
    public:
        SLC(int pos);
        int landed(shared_ptr<Player>player) override;
    private:
        int calcMovement();
        string getMovement(int movement) const;
};

export class NeedlesHall : public NonProperty{
    public:
        NeedlesHall(int pos);
        void landed(shared_ptr<Player>player) override;
};