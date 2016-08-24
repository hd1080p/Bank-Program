#ifndef transaction_h
#define transaction_h
#include <string>
class Transaction{
  std::string type;
  double amount;

  public:
    //Constructor
    Transaction(std::string type = "", double amount = 0){
      this->type = type;
      this->amount = amount;
    }

    //Mutators
    void setTranType(std::string type);
    void setTranAmount(double amount);

    //Accessors
    std::string getTranType() const;
    double getTranAmount() const;
};

#endif //transaction_h
