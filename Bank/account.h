#ifndef account_h
#define account_h

#include "depositor.h"
#include "transaction.h"

class Account{
  Depositor depositor;
  int accnum;
  std::string type, status;
  Transaction *transaction[50];
  int numtrans;
  double balance;

  public:
    //Constructor
    Account(int accnum = 0, std::string type = "", double balance = 0, Depositor depositor = Depositor()){
      this->accnum = accnum;
      this->type = type;
      this->balance = balance;
      this->depositor = depositor;
      status = "Open";
      numtrans = 0;
    }

    //Mutators
    void makeDeposit(double amount);
    void setAccountType(std::string type);
    void setAccountStatus(std::string status);
    void setTransaction(Transaction transaction, int index);
    void addTransaction(std::string type, double amount);
    void setBalance(double balance);
    bool checkWithdrawl(double amount);
    void makeWithdrawl(double amount);
    int setAccountNumber(int accnum);

    //Accessors
    double getBalance() const;
    int getNumTrans() const;
    int getAccountNumber() const;
    std::string getAccountType() const;
    std::string getAccountStatus() const;
    Depositor getDepositor() const;
    Transaction* getTransaction(int index);

    //Operator Overload
    bool operator<(const Account& rhs);
};

#endif //account_h
