#include "person.h"

void Person::setvorname(QString uv)
{
    this->vorname=uv;
}

QString Person::getvorname()
{
    return(this->vorname);
}

void Person::setnachname(QString un)
{
    this->nachname=un;
}

QString Person::getnachname()
{
    return(this->nachname);
}

