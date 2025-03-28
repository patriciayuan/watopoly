export module building;
import square;
import <memory>;
import <string>;
using namespace std;
export class Player;
export class Building : public Square { 
    protected:
        int cost;
        bool isMortgaged;
        weak_ptr<Player>owner;
    public:
        Building(const string& name, int pos, int cost);
        virtual ~Building() = default;
        virtual void landed(shared_ptr<Player> player)override;
        void setOwner(shared_ptr<Player>player);
        void mortage();
        void unmortage();

        bool isOwnable() const override {return true;}
        bool owned() const override;
        int getCost() const;
        bool getIsMortaged() const;
        shared_ptr<Player> getOwner() const;

        virtual int calcTuition(shared_ptr<Player> player) const = 0;
        virtual bool canImprove() const {return false;}
        virtual void improve() {throw runtime_error("Cannot improve this building");}
        virtual void sellImprovement(){throw runtime_error("Cannot sell improvement on this building");}
};



