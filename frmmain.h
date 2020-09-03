#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include "passwort.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMain; }
QT_END_NAMESPACE

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_btnBestaetigen_1_clicked();
    void on_btnBestaetigen_2_clicked();
    void on_edtPasswort_textChanged(const QString &arg1);

private:
    Ui::FrmMain *ui;

    Passwort p;

    QListWidgetItem* Zeile_1=new QListWidgetItem;
    QListWidgetItem* Zeile_2=new QListWidgetItem;
    QListWidgetItem* Zeile_3=new QListWidgetItem;
    QListWidgetItem* Zeile_4=new QListWidgetItem;
    QListWidgetItem* Zeile_5=new QListWidgetItem;
    QListWidgetItem* Zeile_6=new QListWidgetItem;
};
#endif // FRMMAIN_H
