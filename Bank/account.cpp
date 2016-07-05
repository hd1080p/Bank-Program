#include "account.h"

double Account::getBalance() const
{ return balance; }

Depositor Account::getDepositor() const
{ return depositor; }

int Account::getAccountNumber() const
{ return accnum; }

string Account::getAccountType() const
{ return type; }

string Account::getAccountStatus() const
{ return status; }

Transaction* Account::getTransaction(int index)
{ return transaction[index]; }

int Account::getNumTrans() const
{ return numtrans; }

void Account::setBalance(double newbalance)
{ balance = newbalance; }

void Account::setAccountType(string type)
{ this->type = type; }

void Account::setAccountStatus(string status)
{ this->status = status; }

void Account::makeDeposit(double amount)
{ balance += amount; }

bool Account::makeWithdraw(double amount)
{
  if(amount > balance || amount <= 0)
    return true;
  balance -= amount;
  return false;
}

void Account::addTransaction(string type, double amount)
{
    transaction[numtrans] = new Transaction(type, amount);
    numtrans++;
}
