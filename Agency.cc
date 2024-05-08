// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ
#include "SNData.h"
#include "Agency.h"
#include "Util.h"

#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Agency::Agency(string name,double initialMoney){
    this->name=name;
    money=initialMoney;
}

Influencer* Agency::searchInfluencer(string infName){
    for (unsigned int i=0; i<influencers.size(); ++i) {
        if (influencers[i].getName()==infName) {
            return &influencers[i];
        }
    }
    throw EXCEPTION_INFL_NOT_FOUND;
}

void Agency::addInfluencer(string infName,double commission){
    bool error=false;
    
    for(unsigned int i=0;i<influencers.size();i++){
        string nombre=influencers[i].getName();
        if(nombre==infName){
            Util::error(ERR_DUPLICATED);
            error=true;
        }
    }
    if(!error){
        Influencer inf(infName);
        try{
            inf.setCommission(commission);
            influencers.push_back(inf);
        }
        catch(Exception e){
            if(e==EXCEPTION_WRONG_COMMISSION){
                Util::error(ERR_WRONG_COMMISSION);
            }
            else{
                Util::debug(e);
            }
        }
    }
}

void Agency::addFollowers(string infName, string snName, int nFollowers){
    try {
        Influencer* inf = searchInfluencer(infName);
        inf->addFollowers(snName, nFollowers);
    } catch (Exception e) {
        if(e==EXCEPTION_INFL_NOT_FOUND){
            Util::error(ERR_NOT_FOUND);
        }
        else{
            Util::debug(e);
        }
    }
}

void Agency::newEvent(vector<string> infNames,int nsns, string snNames[],double evRats[]){
    
    for(unsigned int i=0; i<infNames.size(); ++i){
         try {
             Influencer* inf = searchInfluencer(infNames[i]);
             inf->addEvent(evRats,snNames,nsns);
         }
        catch(Exception e){
            if(e==EXCEPTION_INFL_NOT_FOUND){
            }
            else{
                Util::debug(e);
            }
        }
     }
}

void Agency::deleteInfluencer (string infName){
    try {
        Influencer* inf = searchInfluencer(infName);
        double commission = inf->collectCommission();
        money += commission;
        for (unsigned int i=0; i < influencers.size(); ++i) {
            string nombre=influencers[i].getName();
            
            if (nombre== infName) {
                influencers.erase(influencers.begin() + i);
                return;
            }
        }
    } 
    catch(Exception e){
        if(e==EXCEPTION_INFL_NOT_FOUND){
            Util::error(ERR_NOT_FOUND);
        }
        else{
            Util::debug(e);
        }
    }
}


double Agency::collectCommissions(){
    double totalCommission = 0;
    for (unsigned int i=0;i<influencers.size();i++){
        double inflCommission= influencers[i].collectCommission();
        totalCommission += inflCommission;
    }
    money += totalCommission;
    return totalCommission;
}

ostream& operator<<(ostream &os,const Agency &ag){

    os << "Agency: " << ag.getName() << " [" << ag.getMoney() << "]" << endl;
    for (unsigned int i = 0; i < ag.influencers.size(); ++i) {
        string nombre=ag.influencers[i].getName();
        double commission=ag.influencers[i].getCommission();
        //int nFollowers= ag.influencers[i].getFollowers();
        
        
        os << "Influencer: " << nombre << " (" << commission << ")" << endl;
        
        vector<SNFollowers> followers = ag.influencers[i].getFollowers();
        
        for (unsigned int j = 0; j <followers.size(); ++j) {
            os << followers[j];
        }
        os<<endl;
    }
    os<<endl;
    return os;
}
