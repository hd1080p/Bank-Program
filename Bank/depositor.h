#ifndef depositor_h
#define depositor_h

#include "name.h"

class Depositor{
  Name name;
  std::string ssn;

  public:
    //Constructor
    Depositor(Name name = Name(), std::string ssn = ""){
      this->name = name;
      this->ssn = ssn;
    }

    //Mutators
    void setName(Name name);
    void setSSN(std::string ssn);

    //Accessors
    Name getName() const;
    std::string getSSN() const;
};

#endif //depositor_h
