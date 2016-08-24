#include "account.h"

double Account::getBalance() const
{ return balance; }

Depositor Account::getDepositor() const
{ return depositor; }

int Account::getAccountNumber() const
{ return accnum; }

std::string Account::getAccountType() const
{ return type; }

std::string Account::getAccountStatus() const
{ return status; }

Transaction* Account::getTransaction(int index)
{ return transaction[index]; }

int Account::getNumTrans() const
{ return numtrans; }

void Account::setBalance(double newbalance)
{ balance = newbalance; }

void Account::setAccountType(std::string type)
{ this->type = type; }

void Account::setAccountStatus(std::string status)
{ this->status = status; }

void Account::makeDeposit(double amount)
{ balance += amount; }

void Account::makeWithdrawl(double amount)
{ balance -= amount; }

bool Account::checkWithdrawl(double amount)
{
  if(amount > balance || amount <= 0)
    return true;
  return false;
}

void Account::addTransaction(std::string type, double amount)
{
    transaction[numtrans] = new Transaction(type, amount);
    numtrans++;
}

bool Account::operator<(const Account& rhs){
    if(this->getDepositor().getName().getLastName().compare(rhs.getDepositor().getName().getLastName()) < 0)
        return true;
    return false;
}
