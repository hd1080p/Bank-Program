#include "depositor.h"

void Depositor::setName(Name name)
{ this->name = name; }

void Depositor::setSSN(std::string ssn)
{ this->ssn = ssn; }

Name Depositor::getName() const
{ return name; }

std::string Depositor::getSSN() const
{ return ssn; }
