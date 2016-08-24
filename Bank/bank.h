#ifndef bank_h
#define bank_h

#include "account.h"
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

class Bank {
  std::list<Account> account;

  public:
    Bank() {}
    //Constructor
    Bank(Account account)
    { this->account.push_back(account); }

   //Mutators
   bool openAccount(int id);
   bool closeAccount(double balance, int index);
   bool deleteAccount(double balance, std::list<Account>::iterator it);
   bool reopenAccount(int id);
   void setAccount(Account account, int index);
   void addAccount(int id, std::string type, double balance, Depositor depositor);
   void reopen_account(std::ofstream &output);
   void deposit(std::ofstream &output);
   void withdrawl(std::ofstream &output);
   int  new_account(std::ofstream &output);
   int  close_account(std::ofstream &output);
   int  delete_account(std::ofstream &output);


   //Accessors
   std::list<Account>::iterator getAccount(int id);
   std::list<Account>::iterator getAccount(std::string ssn);
   int getActiveAccounts() const;
   void getDatabaseTransaction(std::ofstream &output);
   void getAccountTransaction(std::list<Account>::iterator i, std::ofstream &output);
   void account_info(std::ofstream &output);
   void transaction_info(std::ofstream &output);
   void balance(std::ofstream &output);

   //Accessory methods
   void print(std::ofstream &output);

};

#endif // classbank_h
