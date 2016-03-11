#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString ad=getenv("USER");
    qDebug()<< ad;

if(ad=="root")
    w.show();
   else{
qDebug()<<"root can run this program !";
exit(1);}


    return a.exec();
}
