#ifndef name_h
#define name_h
#include <string>
using namespace std;

class Name{
  string first, last;
  public:
    Name(string first = "", string last = "")
    {
       this->first = first;
       this->last = last;
    }
    //Mutators
    void setFirstName(string first);
    void setLastName(string last);
    //Accessors
    string getFirstName() const;
    string getLastName() const;
};
#endif
