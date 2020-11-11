#ifndef EMAIL_H
#define EMAIL_H

#include <QString>

class Email
{
public:
    void setemail(QString em);
    QString getemail();

private:
    QString email;
};

#endif // EMAIL_H
