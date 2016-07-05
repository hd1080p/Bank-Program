#include "bank.h"
#include "account.h"

bool Bank::openAccount(int index, Account account, Depositor depositor, Name name)
{
  if(index != -1)
    return false;
  active_accounts++;
  return true;
}

bool Bank::deleteAccount(double balance, int index)
{
  if(balance != 0 || index == -1)
    return true;
  for(int i = index; i < active_accounts; i++)
    account[index] = account[index+1];
  return false;
}

void Bank::addAccount(int accnum, string type, double balance, Depositor depositor)
{
  account[active_accounts] = new Account(accnum, type, balance, depositor);
  active_accounts++;
}

bool Bank::closeAccount(double balance, int index)
{
  if(balance == 0 || index != -1)
  {
    account[index]->setAccountStatus("Closed");
    return false;
  }
  return true;
}

int Bank::findAccount(int requested_acc) const
{
  for(int i = 0; i < active_accounts; i++)
    if(account[i]->getAccountNumber() == requested_acc)
      return i;
  return -1;
}

int Bank::findAccountSSN(string requested_ssn) const
{
  for(int i = 0; i < active_accounts; i++)
    if(account[i]->getDepositor().getSSN() == requested_ssn)
      return i;
  return -1;
}

int Bank::getActiveAccounts() const
{ return active_accounts; }

void Bank::countActiveAccounts(Account account, Depositor depositor, Name name)
{ active_accounts++; }

void Bank::setAccount(Account account, int index)
{ *this->account[index] = account; }

Account* Bank::getAccount(int index) const
{ return account[index]; }
