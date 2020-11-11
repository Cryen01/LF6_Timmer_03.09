#include <frmmain.h>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrmMain w;
    w.show();
    return a.exec();
}
