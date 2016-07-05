#ifndef bank_h
#define bank_h
#include "account.h"

const int maxacc = 50;

class Bank
{
  Account *account[maxacc];
  int active_accounts;

  public:
    Bank() { active_accounts = 0; }

    Bank(Account a_account)
    {
      account[active_accounts] = new Account;
      active_accounts++;
    }
    ~Bank()
    {
      while(active_accounts > 0)
      {
        active_accounts--;
        delete account[active_accounts];
        account[active_accounts] = NULL;
      }
    }

   //Mutators (Setters)
   bool openAccount(int index, Account account, Depositor depositor, Name name);
   bool closeAccount(double balance, int index);
   void countActiveAccounts(Account account, Depositor depositor, Name name);
   void setAccount(Account account, int index);
   bool deleteAccount(double balance, int index);
   void addAccount(int num, string type, double bal, Depositor depositor);
   //Accessors (Getters)
   int findAccount(int requested_acct) const;
   int findAccountSSN(string requested_ssn) const;
   Account* getAccount(int index) const;
   int getActiveAccounts() const;

};
#endif // classbank_h
