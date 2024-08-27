#include "Scientist.h"

/*
@TODO: Complete the Scientist class definition:
- add implementation for constructor with parameters
- add implementation for operator ==
- add implementation for operator <
- add implementation for get methods
*/

Scientist::Scientist(FullName name, int i):scientist(name),id(i){}

bool Scientist::operator==(const Scientist& rhs)
{
    return (scientist==rhs.scientist)&&(id == rhs.id);
}

bool Scientist::operator<(const Scientist rhs)
{
    return id<rhs.id;
}

FullName Scientist::getFullName() const
{
    return scientist;
}

int Scientist::getId() const
{
    return id;
}
