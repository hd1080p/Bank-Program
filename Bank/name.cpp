#include "name.h"

void Name::setFirstName(std::string first)
{ this->first = first; }

void Name::setLastName(std::string last)
{ this->last = last; }

std::string Name::getFirstName() const
{ return first; }

std::string Name::getLastName() const
{ return last; }
