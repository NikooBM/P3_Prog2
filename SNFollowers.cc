// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#include "SNFollowers.h"
#include "SNData.h"
#include "Util.h"

#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

SNFollowers::SNFollowers(string name,int initialFollowers){
    if(initialFollowers<0){
        throw invalid_argument(to_string(initialFollowers));
    }
    
    if(!SNData::checkSN(name)){
        throw EXCEPTION_UNKNOWN_SN;
    }

    numFollowers=initialFollowers;
    money=0;
    this->name=name;
}

void SNFollowers::addFollowers(int nFollowers){
    numFollowers=nFollowers+numFollowers;
    
    if(numFollowers<0){
        numFollowers=0;
    }    
}

void SNFollowers::addEvent(double rating){
    if(rating<0){
        throw invalid_argument(to_string(rating));
    }
    
    double ratingRelation=rating/static_cast<double>(SNData::getAvgRating(name));
    
    if(ratingRelation>0.8){
        int addedFollowers=static_cast<int>(numFollowers*ratingRelation);
        numFollowers+= addedFollowers;
        
        money=addedFollowers*static_cast<double>(SNData::getAvgMonetizing(name));
    }
    
    if(ratingRelation<0.8){
        int lostFollowers=static_cast<int>((0.9-ratingRelation)*numFollowers);
            
        if(numFollowers>=lostFollowers){
            numFollowers=numFollowers-lostFollowers;
        }
        else{
            numFollowers=0;
        }
    }
}

double SNFollowers::collectCommission(double commission){
    if(commission<0 || commission>1){
        throw invalid_argument(to_string(commission));
    }
    
    double commissionAmount=money*commission;
    money=0;
    
    return commissionAmount;
}

ostream& operator<<(ostream &os,const SNFollowers &snf){
    os<<"["<<snf.name<<"|"<<snf.numFollowers<<"|"<<snf.money<<"]";
    return os;
}

void SNFollowers::setNumFollowers(int nFollowers){
    numFollowers=nFollowers;
    if (numFollowers<0){
        numFollowers=0;
    }
}
