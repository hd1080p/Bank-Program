#ifndef account_h
#define account_h
#include "depositor.h"
#include "transaction.h"
#include <string>

class Account{
  Depositor depositor;
  int accnum;
  string type, status;
  Transaction *transaction[50];
  int numtrans;
  double balance;

  public:
    Account(int accnum = 0, string type = "", double balance = 0, Depositor depositor = Name())
    {
      this->accnum = accnum;
      this->type = type;
      this->balance = balance;
      this->depositor = depositor;
      status = "Open";
      numtrans = 0;
    }

    //Mutators
    void makeDeposit(double amount);
    bool makeWithdraw(double amount);
    void setBalance(double balance);
    int setAccountNumber(int accnum);
    void setAccountType(string type);
    void setAccountStatus(string status);
    void setTransaction(Transaction transaction, int index);
    void addTransaction(string type, double amount);
    //Accessors
    double getBalance() const;
    Depositor getDepositor() const;
    int getAccountNumber() const;
    string getAccountType() const;
    string getAccountStatus() const;
    Transaction* getTransaction(int index);
    int getNumTrans() const;
};
#endif
