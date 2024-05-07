// DNI 78008606N BIBILEISHVILI MAMALADZE, NIKOLOZ

#ifndef _UTIL_H_
#define _UTIL_H_

enum Exception {
  EXCEPTION_INFL_NOT_FOUND,
  EXCEPTION_WRONG_COMMISSION,
  EXCEPTION_UNKNOWN_SN
};



enum Error{
  ERR_DUPLICATED,
  ERR_NOT_FOUND,
  ERR_WRONG_SOCIALNETWORK,
  ERR_WRONG_COMMISSION,
  ERR_UNKNOWN_SN
};



class Util{
  public:
    // prints an error message
    static void error(Error e);

    // prints exception type (debug)
    static void debug(Exception e);
    
};

#endif
