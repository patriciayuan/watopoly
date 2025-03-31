export module academic;
import building;
import <vector>;
import <array>;
import <memory>;
import <iostream>;
import <stdexcept>;
import <string>;
using namespace std;

export class AcademicProperty : public Building{
    int improvementCost;
    int improvements;   
    vector<int> tuition;
    vecotr<shared_ptr<AcademicProperty> monopolyBlock;

    public:
        AcademicProperty(const string& name, int pos, int cost, int improvementCost, int improvements
                        vector<int> tuition, vector<int> monopolyBlock);
        void landed(shared_ptr<Player>player) override;
        void improve() override;
        void sellImprovement() override;
        void output() const;
        void purchase(shared_ptr<Player>player);
        int calcTuition(shared_ptr<Player>player) const override;
        int getImprovements() const;
        int getCost() const;
        const vector<int> getTuition() const;
        bool canImprove() const override;
        bool hasMonopoly() const;
        const vector<shared_ptr<Player>player>> getMonopolyBlock() const;

                //academic property stuff
            acaa... {
        vector<vector<int>> tuitionChart{
            {2,10,30,90,160,250}
            {4,20,60,180,320,450}
            {6,30,90,270,400,550}
            {6,30,90,270,400,550}
            {8,40,100,300,450,600}
            {10,50,150,450,625,750}
            {10,50,150,450,625,750}
            {12,60,180,500,700,900}
            {14,70,200,550,750,950}
            {14,70,200,550,750,950}
            {16,80,220,600,800,1000}
            {18,90,250,700,875,1050}
            {18,90,250,700,875,1050}
            {20,100,300,750,925,1100}
            {22,110,330,800,975,1150}
            {22,110,330,800,975,1150}
            {24,120,360,850,1025,1200}
            {26,130,390,900,1100,1275}
            {26,130,390,900,1100,1275}
            {28,150,450,1000,1200,1400}
            {35,175,500,1100,1300,1500}
            {50,200,600,1400,1700,2000}
        }
        vector<map<vector<int>, vector<vector<int>>>> costChart {
            //pos,cost,improvCost,Tuition
            {{2, 40, 50},tuitionChar[0]}
            {{4,60,50},tuitionChar[1]}
            {{7,100,50},tuitionChar[2]}
            {{9,100,50},tuitionChar[3]}
            {{10,120,50},tuitionChar[4]}
            {{12,140,100},tuitionChar[5]}
            {{14,140,100},tuitionChar[6]}
            {{15,160,100},tuitionChar[7]}
            {{17,180,100},tuitionChar[8]}
            {{19,180,100},tuitionChar[9]}
            {{20,200,100},tuitionChar[10]}
            {{22,220,150},tuitionChar[11]}
            {{24,220,150},tuitionChar[12]}
            {{25,240,150},tuitionChar[13]}
            {{27,260,150},tuitionChar[14]}
            {{28,260,150},tuitionChar[15]}
            {{30,280,150},tuitionChar[16]}
            {{32,300,200},tuitionChar[17]}
            {{33,300,200},tuitionChar[18]}
            {{35,320,200},tuitionChar[19]}
            {{38,350,200},tuitionChar[20]}
            {{40,400,200},tuitionChar[21]}
        }    
        
            


        }

    }




    int getCost(int pos) {

        for (auto &i : costChart) {
            if (i[0] == pos) {
                return i[1];
            }
        }


    }

};