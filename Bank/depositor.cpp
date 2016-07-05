#include "depositor.h"
#include <string>

void Depositor::setName(Name name)
{ this->name = name; }

void Depositor::setSSN(string ssn)
{ this->ssn = ssn; }

Name Depositor::getName() const
{ return name; }

string Depositor::getSSN() const
{ return ssn; }
