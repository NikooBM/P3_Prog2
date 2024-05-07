// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#ifndef SNFollowers_h
#define SNFollowers_h

#include <string>
#include <iostream>
using namespace std;

class SNFollowers{
    friend ostream& operator<<(ostream &os,const SNFollowers &snf);
private:
    string name;
    int numFollowers;
    double money;

public:
    SNFollowers(string name,int initialFollowers);
    void addFollowers(int nFollowers);
    void addEvent(double rating);
    double collectCommission(double commission);
    string getName() const {return name;};
    int getNumFollowers() const {return numFollowers;};
    double getMoney() const {return money;};
};

#endif
