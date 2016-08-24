#include "transaction.h"

void Transaction::setTranType(std::string type)
{ this->type = type; }

void Transaction::setTranAmount(double amount)
{ this->amount = amount; }

std::string Transaction::getTranType() const
{ return type; }

double Transaction::getTranAmount() const
{ return amount; }
