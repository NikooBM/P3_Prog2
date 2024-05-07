// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#include "SNData.h"
#include "Util.h"

#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<SocialNetworkData> SNData::sns;

void SNData::newSocialNetwork(string name,double avgR,double avgM){

    if(checkSN(name)){
            throw invalid_argument(name);
        }
    
    if(avgR<0 || avgR>1){
        throw invalid_argument(to_string(avgR));
    }
    else if(avgM<0 || avgM>1){
        throw invalid_argument(to_string(avgM));
    }
    
    else{
        SocialNetworkData newsns;
        newsns.name=name;
        newsns.averageRating=avgR;
        newsns.averageMonetizing=avgM;
       
        sns.push_back(newsns);
    }
}

 bool SNData::checkSN(string name){
     for(unsigned int i=0;i<sns.size();i++){
         if(sns[i].name==name){
             return true;
         }
     }
     return false;
}

 double SNData::getAvgRating(string name){
     for(unsigned int i=0;i<sns.size();i++){
         if(sns[i].name==name){
             return sns[i].averageRating;
         }
     }
         return 0.0;
}

 double SNData::getAvgMonetizing(string name){
     for(unsigned int i=0;i<sns.size();i++){
         if(sns[i].name==name){
             return sns[i].averageMonetizing;
         }
     }
         return 0.0;
}
