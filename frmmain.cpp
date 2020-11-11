#include "frmmain.h"
#include "ui_frmmain.h"


FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);

    Zeile_1->setText("Das Passwort benötigt:");
    Zeile_1->setBackground(Qt::black);
    Zeile_1->setForeground(Qt::white);

    Zeile_2->setText("- Mindestens 8 Zeichen");
    Zeile_2->setBackground(Qt::black);
    Zeile_2->setForeground(Qt::red);

    Zeile_3->setText("- Mindestens 2 Ziffern");
    Zeile_3->setBackground(Qt::black);
    Zeile_3->setForeground(Qt::red);

    Zeile_4->setText("- Mindestens 2 Sonderzeichen");
    Zeile_4->setBackground(Qt::black);
    Zeile_4->setForeground(Qt::red);

    Zeile_5->setText("- Nicht die Worte: Hund, Katze oder Maus");
    Zeile_5->setBackground(Qt::black);
    Zeile_5->setForeground(Qt::green);

    Zeile_6->setText("- Mindestens einen Groß- und einen Klein-Buchstaben");
    Zeile_6->setBackground(Qt::black);
    Zeile_6->setForeground(Qt::red);


    ui->lstPasswortAnforderungen->addItem(Zeile_1);
    ui->lstPasswortAnforderungen->addItem(Zeile_2);
    ui->lstPasswortAnforderungen->addItem(Zeile_3);
    ui->lstPasswortAnforderungen->addItem(Zeile_4);
    ui->lstPasswortAnforderungen->addItem(Zeile_5);
    ui->lstPasswortAnforderungen->addItem(Zeile_6);
}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::on_edtPasswort_textChanged(const QString & arg1)
{
    p.setpasswort(arg1);

    //Testet die Länge und ändert die Farbe
    p.checklength();
    if (p.checklength() == 1)
    {
        Zeile_2->setForeground(Qt::green);
    }

    else
    {
        Zeile_2->setForeground(Qt::red);
    }

    //Testet die Nummern und ändert die Farbe
    p.checknumbers();
    if (p.checknumbers() == 1)
    {
        Zeile_3->setForeground(Qt::green);
    }

    else
    {
        Zeile_3->setForeground(Qt::red);
    }

    //Testet die Sonderzeichen und ändert die Farbe
    p.checkspecialcharacters();
    if (p.checkspecialcharacters() == 1)
    {
        Zeile_4->setForeground(Qt::green);
    }

    else
    {
        Zeile_4->setForeground(Qt::red);
    }

    //Testet die Wörter Hund, Katze & Maus und ändert die Farbe
    p.checkhundkatzemaus();
    if (p.checkhundkatzemaus() == 0)
    {
        Zeile_5->setForeground(Qt::red);
    }

    else
    {
        Zeile_5->setForeground(Qt::green);
    }

    //Testet die Groß & Klein-Buchstaben und ändert die Farbe
    p.checkgrosskleincharacters();
    if (p.checkgrosskleincharacters() == 1)
    {
        Zeile_6->setForeground(Qt::green);
    }

    else
    {
        Zeile_6->setForeground(Qt::red);
    }
}

void FrmMain::on_btnBestaetigen_1_clicked()
{
    d.setdatum(ui->edtGeburtsdatum->text());
    u.setvorname(ui->edtVorname->text());
    u.setnachname(ui->edtNachname->text());
    e.setemail(ui->edtEmail->text());

    ui->lstAusgabe->clear();
    ui->lstAusgabe->addItem("Vorname: "+u.getvorname());
    ui->lstAusgabe->addItem("Nachname: "+u.getnachname());
    ui->lstAusgabe->addItem("Geburtsdatum: "+d.getdatum());
    ui->lstAusgabe->addItem("Email-Adresse: "+e.getemail());
    ui->lstAusgabe->addItem("Passwort: "+p.getpasswort());
}

void FrmMain::on_btnBestaetigen_2_clicked()
{
    ui->lstAusgabe->clear();

    if (p.checkgrosskleincharacters() == 1 && p.checkhundkatzemaus() == 1 && p.checklength() == 1 && p.checknumbers() == 1 && p.checkspecialcharacters() == 1)
    {
        ui->lstAusgabe->addItem("Danke, ihre Daten wurden gespeichert!");
        ui->lstAusgabe->addItem("Das Passwort lautet "+p.getpasswort());
    }

    else
    {
        ui->lstAusgabe->addItem("Dieses Passwort erfüllt nicht die Bedingungen!");
    }
}
