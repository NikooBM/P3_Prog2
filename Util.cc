// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#include <iostream>

using namespace std;

#include "Util.h"

void Util::error(Error e){
  switch(e){
    case ERR_DUPLICATED:
      cout << "ERROR: duplicated influencer" << endl;
      break;
    case ERR_NOT_FOUND:
      cout << "ERROR: influencer not found" << endl;
      break;
    case ERR_WRONG_COMMISSION:
      cout << "ERROR: wrong commission" << endl;
      break;
    case ERR_WRONG_SOCIALNETWORK:
      cout << "ERROR: wrong social network" << endl;
      break;
    case ERR_UNKNOWN_SN:
      cout << "ERROR: unknown social network" << endl;
      break;
  }
}

void Util::debug(Exception e) {

  const string EXCEPT_STR[] = {
    "EXCEPTION_INFL_NOT_FOUND",
    "EXCEPTION_WRONG_COMMISSION",
    "EXCEPTION_UNKNOWN_SN"
    };
    
  cout << "DEBUG: error produced by exception " << EXCEPT_STR[e] << endl;

}
