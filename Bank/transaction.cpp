#include "transaction.h"

void Transaction::setTranType(string type)
{ this->type = type; }

void Transaction::setTranAmount(double amount)
{ this->amount = amount; }

string Transaction::getTranType() const
{ return type; }

double Transaction::getTranAmount() const
{ return amount; }
