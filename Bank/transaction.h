#ifndef transaction_h
#define transaction_h
#include <string>

using namespace std;

class Transaction{
  string type;
  double amount;

  public:
    Transaction(string type = "", double amount = 0)
    {
      this->type = type;
      this->amount = amount;
    }
    //Mutators
    void setTranType(string type);
    void setTranAmount(double amount);
    //Accessors
    string getTranType() const;
    double getTranAmount() const;
};
#endif
