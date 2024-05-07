// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#ifndef SNData_h
#define SNData_h

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct SocialNetworkData {
   string name;
   double averageRating;
   double averageMonetizing;
};

class SNData{
    
private:
    static vector<SocialNetworkData> sns;

public:
    static void newSocialNetwork(string name,double avgR,double avgM);
    static bool checkSN(string name);
    static double getAvgRating(string name);
    static double getAvgMonetizing(string name);
    
};

#endif
