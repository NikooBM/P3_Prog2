// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#ifndef Influencer_h
#define Influencer_h

#include "SNFollowers.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Influencer{
    friend ostream& operator<<(ostream &os,const SNFollowers &inf);
private:
    string name;
    double commission;
    vector <SNFollowers> followers;
    
public:
    Influencer (string name);
    void setCommission(double commission);
    void addFollowers(string snName,int nFollowers);
    void addEvent(double rat[],string sn[],int nsns);
    double collectCommission();
    string getName() const {return name;};
    double getCommission() const {return commission;};
    vector <SNFollowers> getFollowers() const {return followers;};
};

#endif
