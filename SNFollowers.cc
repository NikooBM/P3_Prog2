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
        double monetizing= SNData::getAvgMonetizing(name);
        double rating= SNData::getAvgRating(name);
        SNData::newSocialNetwork(name,rating,monetizing);
        
        throw EXCEPTION_UNKNOWN_SN;
    }

    this->numFollowers=initialFollowers;
    this->money=0;
    this->name=name;
}

void SNFollowers::addFollowers(int nFollowers){
    numFollowers+=nFollowers;
    
    if(numFollowers<0){
        numFollowers=0;
    }    
}

void SNFollowers::addEvent(double rating){
    if(rating<0){
        throw invalid_argument(to_string(rating));
    }
    double avgRat=SNData::getAvgRating(name);
    
    double ratingRelation=rating/avgRat;
    
    if(ratingRelation>0.8){

        int addedFollowers=static_cast<int>(numFollowers*ratingRelation);
        numFollowers += addedFollowers;
        
        double monetizing= (SNData::getAvgMonetizing(name));
        money+=addedFollowers*monetizing;
    
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
