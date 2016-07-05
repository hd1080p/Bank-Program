#include "name.h"

void Name::setFirstName(string first)
{ this->first = first; }

void Name::setLastName(string last)
{ this->last = last; }

string Name::getFirstName() const
{ return first; }

string Name::getLastName() const
{ return last; }
