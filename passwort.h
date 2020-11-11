#ifndef PASSWORT_H
#define PASSWORT_H

#include <QString>

class Passwort
{
public:
    void setpasswort(QString p);
    bool checklength();
    bool checknumbers();
    bool checkspecialcharacters();
    bool checkhundkatzemaus();
    bool checkgrosskleincharacters();
    QString getpasswort();

private:
    QString passwort;
};

#endif // PASSWORT_H
