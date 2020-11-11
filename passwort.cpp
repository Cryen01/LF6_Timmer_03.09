#include "passwort.h"
#include "frmmain.cpp"

//Setzt das Passwort
void Passwort::setpasswort(QString p)
{
    this->passwort=p;
}

//Testet die Länge
bool Passwort::checklength()
{
    if (passwort.length() >= 8)
    {
        return(1);
    }

    else
    {
        return(0);
    }
}

//Testet die Nummern
bool Passwort::checknumbers()
{
    int passwortlaenge = 0;

    for (int i = 0; i < passwort.size() ; i++)
    {
        if (passwort[i].isDigit())
        {
            passwortlaenge = passwortlaenge + 1;
        }
    }


    if (passwortlaenge >= 2)
    {
        return(1);
    }

    else
    {
        return(0);
    }
}

//Testet die Sonderzeichen
bool Passwort::checkspecialcharacters()
{
    int countsc = 0;

    for (int a = 0; a < passwort.size() ; a++)
    {
        for (int i = 33; i <= 47; i++)
        {
            if (passwort[a] == i)
            {
                countsc = countsc + 1;
            }
        }

        for (int i = 58; i <= 64 ; i++)
            if (passwort[a] == i)
            {
                countsc = countsc + 1;
            }

        for (int i = 91; i <= 96 ; i++)
            if (passwort[a] == i)
            {
                countsc = countsc + 1;
            }

        for (int i = 123; i <= 126 ; i++)
            if (passwort[a] == i)
            {
                countsc = countsc + 1;
            }
    }

    if (countsc >= 2)
    {
        return(1);
    }

    else
    {
        return(0);
    }
}

//Testet auf die Wörter Hund, Katze & Maus
bool Passwort::checkhundkatzemaus()
{
    if (passwort.contains("Hund") || passwort.contains("Katze") || passwort.contains("Maus") || passwort.contains("hund") || passwort.contains("katze") || passwort.contains("maus"))
    {
        return(0);
    }

    else
    {
        return(1);
    }
}

//Testet auf mindestens einen Groß- & einen Klein-Buchstaben
bool Passwort::checkgrosskleincharacters()
{
    int passwortzeichengross = 0;
    int passwortzeichenklein = 0;

    for (int e = 0; e < passwort.size() ; e++)
    {
        if (passwort[e].isUpper())
        {
            passwortzeichengross = passwortzeichengross + 1;
        }
        else if (passwort[e].isLower())
        {
            passwortzeichenklein = passwortzeichenklein + 1;
        }
    }

    if (passwortzeichenklein >= 1 && passwortzeichengross >= 1)
    {
        return(1);
    }

    else
    {
        return(0);
    }
}

//Holt das Passwort
QString Passwort::getpasswort()
{
    if (checkgrosskleincharacters() == 1 && checkhundkatzemaus() == 1 && checklength() == 1 && checknumbers() == 1 && checkspecialcharacters() == 1)
        return(this->passwort);
    else
    {
        return("Dieses Passwort erfüllt nicht die Bedingungen!");
    }
}
