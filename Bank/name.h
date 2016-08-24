#ifndef name_h
#define name_h
#include <string>

class Name{
  std::string first, last;

  public:
    //Constructor
    Name(std::string first = "", std::string last = "") {
       this->first = first;
       this->last = last;
    }

    //Mutators
    void setFirstName(std::string first);
    void setLastName(std::string last);

    //Accessors
    std::string getFirstName() const;
    std::string getLastName() const;
};

#endif //name_h
