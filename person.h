#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    void setvorname(QString uv);
    QString getvorname();
    void setnachname(QString un);
    QString getnachname();

private:
    QString vorname;
    QString nachname;
};

#endif // PERSON_H
