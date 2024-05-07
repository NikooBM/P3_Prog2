// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#ifndef Agency_h
#define Agency_h

#include <string>
#include <iostream>
#include "Influencer.h"
using namespace std;

class Agency{
    friend ostream& operator<<(ostream &os,const Agency &ag);
private:
    string name;
    double money;
    vector <Influencer> influencers;
public:
    Agency(string name,double initialMoney);
    Influencer *searchInfluencer (string infName);
    void addInfluencer (string infName,double commission);
    void addFollowers (string infName,string snName,int nFollowers);
    void newEvent( vector<string> infNames,int nsns, string snNames[],double evRats[]);
    void deleteInfluencer (string infName);
    double collectCommissions();
    string getName() const {return name;};
    double getMoney() const {return money;};
};

#endif
