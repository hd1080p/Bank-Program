#ifndef depositor_h
#define depositor_h
#include "name.h"


class Depositor{
  Name name;
  string ssn;
  public:
    Depositor(Name name = Name(), string ssn = "")
    {
      this->name = name;
      this->ssn = ssn;
    }

    //Mutators
    void setName(Name name);
    void setSSN(string ssn);
    //Accessors
    Name getName() const;
    string getSSN() const;
};
#endif
